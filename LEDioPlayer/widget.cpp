#include "widget.h"
#include "ui_widget.h"
#include "bass.h"
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include "stylehelper.h"
#include "math.h"
#include "settings.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/images_folder/icon.ico"));

    // Styles settings
    applyStyles();

    // Audio player itself
    m_player = new MediaPlayer(this);

    // this variable contain index of audio selected on playlist
    selectedAudioIndex = 0;

    // playing state variables
    onPause = false;
    running = false;

    trackList = new QStringList();

    delay = 21;

    // Timer allow us to update visualization
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(drawSpectrum()));
    timer->start(delay);

    m_transmitter = new Transmitter(this);

    connectAll();
}

Widget::~Widget()
{
    delete ui;
    delete playListModel;
    delete m_player;
    delete timer;
}

void Widget::connectAll(){

    connect(ui->playlist, &QTableView::clicked, [this] (const QModelIndex &index) {
        selectedAudioIndex = index.row();
    });

    // Double-click on playlist event stop current audio and play selected
    connect(ui->playlist, &QTableView::doubleClicked, [this] (const QModelIndex &index) {
        selectedAudioIndex = index.row();
        Widget::ui->btnStop->click();
        Widget::ui->btnPlay->click();
    });

    // Connect minimize/maximize/close buttons
    connect(ui->btn_minimize, &QToolButton::clicked, this, &QWidget::showMinimized);
    connect(ui->btn_maximize, &QToolButton::clicked, [this](){
        if (this->isMaximized()) {
            this->layout()->setMargin(9);
            this->showNormal();
        } else {
            this->layout()->setMargin(0);
            this->showMaximized();
        }
    });
    connect(ui->btn_close, &QToolButton::clicked, this, &QWidget::close);

    // Play
    connect(ui->btnPlay, &QToolButton::clicked, [this](){
        qDebug() << "button start";

        if (trackList->isEmpty()) return;

        if (running && currentAudioIndex==selectedAudioIndex)
            return;

        if (onPause && currentAudioIndex==selectedAudioIndex) {
            onPause = false;
            m_player->resume();
        } else {
            m_player->play(trackList->at(selectedAudioIndex), ui->volController->value());

            currentAudioIndex = selectedAudioIndex;

            ui->label_Audio->setText(getAudioFileName(trackList->at(selectedAudioIndex)));
        }

        running = true;
    });

    // Stop
    connect(ui->btnStop, &QToolButton::clicked, [this](){
        onPause = false;
        running = false;

        toZeroValues();

        m_player->stop();
    });

    // Pause
    connect(ui->btnPause, &QToolButton::clicked, [this](){
        onPause = true;
        running = false;

        toZeroValues();

        m_player->pause();
    });

    // Previous
    connect(ui->btnPrevious, &QToolButton::clicked, [this](){
        if(selectedAudioIndex!=0){
            selectedAudioIndex--;
            Widget::ui->btnStop->click();
            Widget::ui->btnPlay->click();
        }
    });

    // Next
    connect(ui->btnNext, &QToolButton::clicked, [this](){
        Widget::ui->btnStop->click();
        if(selectedAudioIndex!=trackList->length() - 1){
            selectedAudioIndex++;
        } else {
            selectedAudioIndex = 0;
        }
        Widget::ui->btnPlay->click();
    });

    // Reconnect
    connect(ui->btnReconnect, &QToolButton::clicked, [this](){
        m_transmitter = new Transmitter(this);
    });

    connect(ui->btn_settings, &QToolButton::clicked, [this](){
        qDebug() << "settings";
        //s.setParent(this);
        s.show();
    });

}

void Widget::drawSpectrum(){

    if(!running) return;

    float fft[2048];
    float average[32];

    m_player->getFFT(fft);

    // default
    for (byte i = 0; i < 32; i++)
        average[i] = 0;

    //getting values
    for (byte i = 0; i < 32; i++)
        average[i] += sqrt(fft[i]);

    Settings::get_mode() ? playMode1(fft) : playMode2(fft);

    // drawing
    ui->slider_0-> setValue(int(average[0] *1400)/1);
    ui->slider_1-> setValue(int(average[1] *1400)/1);
    ui->slider_2-> setValue(int(average[2] *1400)/1);
    ui->slider_3-> setValue(int(average[3] *1400)/1);
    ui->slider_4-> setValue(int(average[4] *1400)/1);
    ui->slider_5-> setValue(int(average[5] *1400)/1);
    ui->slider_6-> setValue(int(average[6] *1400)/1);
    ui->slider_7-> setValue(int(average[7] *1400)/1);
    ui->slider_8-> setValue(int(average[8] *1400)/1);
    ui->slider_9-> setValue(int(average[9] *1400)/1);
    ui->slider_10->setValue(int(average[10]*1400)/1);
    ui->slider_11->setValue(int(average[11]*1400)/1);
    ui->slider_12->setValue(int(average[12]*1400)/1);
    ui->slider_13->setValue(int(average[13]*1400)/1);
    ui->slider_14->setValue(int(average[14]*1400)/1);
    ui->slider_15->setValue(int(average[15]*1400)/1);
    ui->slider_16->setValue(int(average[16]*1400)/1);
    ui->slider_17->setValue(int(average[17]*1400)/1);
    ui->slider_18->setValue(int(average[18]*1400)/1);
    ui->slider_19->setValue(int(average[19]*1400)/1);
    ui->slider_20->setValue(int(average[20]*1400)/1);
    ui->slider_21->setValue(int(average[21]*1400)/1);
    ui->slider_22->setValue(int(average[22]*1400)/1);
    ui->slider_23->setValue(int(average[23]*1400)/1);
    ui->slider_24->setValue(int(average[24]*1400)/1);
    ui->slider_25->setValue(int(average[25]*1400)/1);
    ui->slider_26->setValue(int(average[26]*1400)/1);
    ui->slider_27->setValue(int(average[27]*1400)/1);
    ui->slider_28->setValue(int(average[28]*1400)/1);
    ui->slider_29->setValue(int(average[29]*1400)/1);
    ui->slider_30->setValue(int(average[30]*1400)/1);
    ui->slider_31->setValue(int(average[31]*1400)/1);

    // Time control
    ui->timeController->setValue(int((( float(m_player->GetPosOfStream()) / m_player->GetTimeOfStream()) *1000)));

    if (m_player->GetPosOfStream() >= m_player->GetTimeOfStream())
        ui->btnNext->click();
}

void Widget::playMode1(float *fft){
    qDebug() << "Mode1";

    float r = 0;
    float g = 0;
    float b = 0;

    byte delta = 6;

    // RED
    for (byte i = 0; i < delta; i++)
        r += fft[i];

    r = r/delta * r/delta * 7 * 255 + 1;

    // GREEN
    for (byte i = 4; i < 4 + delta; i++)
        g += fft[i];

    g = g/delta * g/delta * 10 * 255 + 1;

    // BLUE
    for (byte i = 8; i < 8 + delta; i++)
        b += fft[i];

    b = b/delta * b/delta * 13 * 255 + 1;

    if (r > 255) {b += (r - 255); r = 255;}
    if (g > 255) g = 255;
    if (b > 255) b = 255;

    if(m_transmitter->isConnected()) m_transmitter->writeRGB(int(r), int(g), int(b), 12, Settings::get_led_amount());
}

void Widget::playMode2(float *fft){
    // vectors
    float v1 = 0;
    float v2 = 0;
    float v3 = 0;

    // V1
    for (int i = 512; i < 1024; i++) {
        v1 = v1 + sqrt(fft[i]) * (((2*i)/1024) - 1);
    }

    // V2
    for (int i = 0; i < 512; i++) {
        v2 = v2 + sqrt(fft[i]) * (i/1024);
    }

    for (int i = 512; i < 1024; i++) {
        v2 = v2 + sqrt(fft[i]) * (1 - i/1024);
    }

    // V3
    for (int i = 0; i < 512; i++) {
        v3 = v3 + sqrt(fft[i]) * (1 - (2*i/1024));
    }

    float level = m_player->GetLevel();
    if (level < 0) level*=-1;

    float vmax = (v1 > v2) ? ((v1 > v3) ? v1 : v3) : ((v2 > v3) ? v2 : v3);

    if (vmax == 0) vmax = 1;

    v1 /= vmax;
    v2 /= vmax;
    v3 /= vmax;

    // Color calculating
    float r = 0;
    float g = 0;
    float b = 0;

    if (level > Settings::get_minLevel()){
        r = level*(Settings::get_v1r()*v1 + Settings::get_v2r()*v2 + Settings::get_v3r()*v3);
        g = level*(Settings::get_v1g()*v1 + Settings::get_v2g()*v2 + Settings::get_v3g()*v3);
        b = level*(Settings::get_v1b()*v1 + Settings::get_v3b()*v2 + Settings::get_v3b()*v3);
    } else {
        r = 0;
        g = 0;
        b = 0;
    }

    // Debug
    qDebug() << level << " " << r << " " << g << " " << b << " " << delay << " " << Settings::get_mode() << " " << Settings::get_led_amount();

    if(m_transmitter->isConnected()) m_transmitter->writeRGB(int(r), int(g), int(b), char(delay), Settings::get_led_amount());
}

void Widget::applyStyles()
{
    // Playlist setting
    playListModel = new QStandardItemModel(this);
    ui->playlist->setModel(playListModel);

    playListModel->setHorizontalHeaderLabels(QStringList() << tr("Audio") << tr("File path"));

    ui->playlist->hideColumn(1);
    ui->playlist->verticalHeader()->setVisible(false);
    ui->playlist->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlist->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlist->resizeColumnsToContents();
    ui->playlist->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->playlist->horizontalHeader()->setStretchLastSection(true);

    // UI settings
    this->setWindowFlags(Qt::FramelessWindowHint); //Отключение оформления окна
    this->setAttribute(Qt::WA_TranslucentBackground); //Фон главного виджета - прозрачный
    this->setStyleSheet(StyleHelper::getWindowStyleSheet());
    this->setMouseTracking(true);

    // Info labels
    ui->label_Vol->setStyleSheet(StyleHelper::getLabelStyleSheet());
    ui->label_Audio->setStyleSheet(StyleHelper::getLabelStyleSheet());

    // Set up styles to buttons
    ui->btnPlay->setStyleSheet(StyleHelper::getPlayStyleSheet());
    ui->btnPause->setStyleSheet(StyleHelper::getPauseStyleSheet());
    ui->btnStop->setStyleSheet(StyleHelper::getStopStyleSheet());
    ui->btnPrevious->setStyleSheet(StyleHelper::getPreviousStyleSheet());
    ui->btnNext->setStyleSheet(StyleHelper::getNextStyleSheet());
    ui->btnReconnect->setStyleSheet(StyleHelper::getReconnectStyleSheet());
    //
    ui->btnAdd->setStyleSheet(StyleHelper::getButtonAddStyleSheet());

    // Plyalist
    ui->playlist->setStyleSheet(StyleHelper::getTableStyleSheet());

    // Sliders
    ui->volController->setStyleSheet(StyleHelper::getSliderStyleSheet());
    ui->timeController->setStyleSheet(StyleHelper::getSliderStyleSheet());

    // Window control buttons
    ui->btn_minimize->setStyleSheet(StyleHelper::getMinimizeStyleSheet());
    ui->btn_maximize->setStyleSheet(StyleHelper::getMaximizeStyleSheet());
    ui->btn_close->setStyleSheet(StyleHelper::getCloseStyleSheet());

    // Settings
    ui->btn_settings->setStyleSheet(StyleHelper::getSettingsStyleSheet());

    // Progress bars
    ui->slider_0 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_1 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_2 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_3 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_4 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_5 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_6 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_7 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_8 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_9 ->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_10->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_11->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_12->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_13->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_14->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_15->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_16->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_17->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_18->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_19->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_20->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_21->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_22->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_23->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_24->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_25->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_26->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_27->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_28->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_29->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_30->setStyleSheet(StyleHelper::getBarStyleSheet());
    ui->slider_31->setStyleSheet(StyleHelper::getBarStyleSheet());
}

QPoint Widget::previousPosition() const
{
    return m_previousPosition;
}

void Widget::setPreviousPosition(QPoint previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged(previousPosition);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton ) {
        m_leftMouseButtonPressed = checkResizableField(event);
        setPreviousPosition(event->pos());
    }
    return QWidget::mousePressEvent(event);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_leftMouseButtonPressed = None;
    }
    return QWidget::mouseReleaseEvent(event);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    switch (m_leftMouseButtonPressed) {
    case Move: {
        if (isMaximized()) {
            //ui->btn_maximize->setStyleSheet(StyleHelper::getMaximizeStyleSheet());
            this->layout()->setMargin(9);
            auto part = event->screenPos().x() / width();
            this->showNormal();
            auto offsetX = width() * part;
            setGeometry(event->screenPos().x() - offsetX, 0, width(), height());
            setPreviousPosition(QPoint(offsetX, event->y()));
        } else {
            auto dx = event->x() - m_previousPosition.x();
            auto dy = event->y() - m_previousPosition.y();
            setGeometry(x() + dx, y() + dy, width(), height());
        }
        break;
    }
    case Top: {
        if (!isMaximized()) {
        auto dy = event->y() - m_previousPosition.y();
        setGeometry(x(), y() + dy, width(), height() - dy);
        }
        break;
    }
    case Bottom: {
        if (!isMaximized()) {
            auto dy = event->y() - m_previousPosition.y();
            setGeometry(x(), y(), width(), height() + dy);
            setPreviousPosition(event->pos());
        }
        break;
    }
    case Left: {
        if (!isMaximized()) {
            auto dx = event->x() - m_previousPosition.x();
            setGeometry(x() + dx, y(), width() - dx, height());
        }
        break;
    }
    case Right: {
        if (!isMaximized()) {
            auto dx = event->x() - m_previousPosition.x();
            setGeometry(x(), y(), width() + dx, height());
            setPreviousPosition(event->pos());
        }
        break;
    }
    default:
        checkResizableField(event);
        break;
    }
    return QWidget::mouseMoveEvent(event);
}

Widget::MouseType Widget::checkResizableField(QMouseEvent *event)
{
    QPointF position = event->screenPos();
    qreal x = this->x();
    qreal y = this->y();
    qreal width = this->width();
    qreal height = this->height();

    QRectF rectTop(x + 9, y, width - 18, 7);
    QRectF rectBottom(x + 9, y + height - 7, width - 18, 7);
    QRectF rectLeft(x, y + 9, 7, height - 18);
    QRectF rectRight(x + width - 7, y + 9, 7, height - 18);
    QRectF rectInterface(x + 9, y + 9, width - 18, height - 18);

    if (rectTop.contains(position)) {
        setCursor(Qt::SizeVerCursor);
        return Top;
    } else if (rectBottom.contains(position)) {
        setCursor(Qt::SizeVerCursor);
        return Bottom;
    } else if (rectLeft.contains(position)) {
        setCursor(Qt::SizeHorCursor);
        return Left;
    } else if (rectRight.contains(position)) {
        setCursor(Qt::SizeHorCursor);
        return Right;
    } else if (rectInterface.contains(position)){
        setCursor(QCursor());
        return Move;
    } else {
        setCursor(QCursor());
        return None;
    }
}

QString Widget::getAudioFileName(QString filename){
    return filename.mid(filename.lastIndexOf('/') + 1, filename.lastIndexOf('.') - filename.lastIndexOf('/') - 1);
}

void Widget::on_volController_valueChanged(int value)
{
    ui->label_Vol->setText(QString::number(value));
    m_player->SetVolumeToStream(value);
}

void Widget::on_btnAdd_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Open files"), QString(), tr("Audio Files (*.mp3)"));
    trackList->append(files);

    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        playListModel->appendRow(items);
    }
}

void Widget::toZeroValues()
{
    ui->slider_0-> setValue(0);
    ui->slider_1-> setValue(0);
    ui->slider_2-> setValue(0);
    ui->slider_3-> setValue(0);
    ui->slider_4-> setValue(0);
    ui->slider_5-> setValue(0);
    ui->slider_6-> setValue(0);
    ui->slider_7-> setValue(0);
    ui->slider_8-> setValue(0);
    ui->slider_9-> setValue(0);
    ui->slider_10->setValue(0);
    ui->slider_11->setValue(0);
    ui->slider_12->setValue(0);
    ui->slider_13->setValue(0);
    ui->slider_14->setValue(0);
    ui->slider_15->setValue(0);
    ui->slider_16->setValue(0);
    ui->slider_17->setValue(0);
    ui->slider_18->setValue(0);
    ui->slider_19->setValue(0);
    ui->slider_20->setValue(0);
    ui->slider_21->setValue(0);
    ui->slider_22->setValue(0);
    ui->slider_23->setValue(0);
    ui->slider_24->setValue(0);
    ui->slider_25->setValue(0);
    ui->slider_26->setValue(0);
    ui->slider_27->setValue(0);
    ui->slider_28->setValue(0);
    ui->slider_29->setValue(0);
    ui->slider_30->setValue(0);
    ui->slider_31->setValue(0);
}
