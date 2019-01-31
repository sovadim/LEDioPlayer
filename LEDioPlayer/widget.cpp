#include "widget.h"
#include "ui_widget.h"
#include "bass.h"
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include "stylehelper.h"
#include "math.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /// Styles settings
    applyStyles();

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

    // Audio player itself
    m_player = new MediaPlayer(this);

    // this variable contain index of audio selected on playlist
    selectedAudioIndex = 0;

    // playing state variables
    onPause = false;
    running = false;

    connect(ui->playlist, &QTableView::clicked, [this] (const QModelIndex &index) {
        selectedAudioIndex = index.row();
    });

    // Double-click on playlist event stop current audio and play selected (even if the same selected)
    connect(ui->playlist, &QTableView::doubleClicked, [this] (const QModelIndex &index) {
        selectedAudioIndex = index.row();
        Widget::on_btnStop_clicked();
        Widget::on_btnPlay_clicked();
    });

    trackList = new QStringList();

    // Timer allow us to update visualization
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(drawSpectrum()));
    timer->start(25);

    m_transmitter = new Transmitter(this);

    /// Connect minimize/maximize/close buttons
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

}

Widget::~Widget()
{
    delete ui;
    delete playListModel;
    m_player->free();
    delete m_player;
    delete timer;
}

/*void Widget::drawSpectrum(){

    if(!running) return;

    float fft[2048];

    m_player->getFFT(fft);

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

    if(m_transmitter->isConnected()) m_transmitter->writeRGB(int(r), int(g), int(b));

    ui->slider_0-> setValue(int(fft[0]*2500)/1);
    ui->slider_1-> setValue(int(fft[1]*2500)/1);
    ui->slider_2-> setValue(int(fft[2]*2500)/1);
    ui->slider_3-> setValue(int(fft[3]*2500)/1);
    ui->slider_4-> setValue(int(fft[4]*2500)/1);
    ui->slider_5-> setValue(int(fft[5]*2500)/1);
    ui->slider_6-> setValue(int(fft[6]*2500)/1);
    ui->slider_7-> setValue(int(fft[7]*2500)/1);
    ui->slider_8-> setValue(int(fft[8]*2500)/1);
    ui->slider_9-> setValue(int(fft[9]*2500)/1);
    ui->slider_10->setValue(int(fft[10]*2500)/1);
    ui->slider_11->setValue(int(fft[11]*2500)/1);
    ui->slider_12->setValue(int(fft[12]*2500)/1);
    ui->slider_13->setValue(int(fft[13]*2500)/1);
    ui->slider_14->setValue(int(fft[14]*2500)/1);
    ui->slider_15->setValue(int(fft[15]*2500)/1);
    ui->slider_16->setValue(int(fft[16]*2500)/1);
    ui->slider_17->setValue(int(fft[17]*2500)/1);
    ui->slider_18->setValue(int(fft[18]*2500)/1);
    ui->slider_19->setValue(int(fft[19]*2500)/1);
    ui->slider_20->setValue(int(fft[20]*2500)/1);
    ui->slider_21->setValue(int(fft[21]*2500)/1);
    ui->slider_22->setValue(int(fft[22]*2500)/1);
    ui->slider_23->setValue(int(fft[23]*2500)/1);
    ui->slider_24->setValue(int(fft[24]*2500)/1);
    ui->slider_25->setValue(int(fft[25]*2500)/1);
    ui->slider_26->setValue(int(fft[26]*2500)/1);
    ui->slider_27->setValue(int(fft[27]*2500)/1);
    ui->slider_28->setValue(int(fft[28]*2500)/1);
    ui->slider_29->setValue(int(fft[29]*2500)/1);
    ui->slider_30->setValue(int(fft[30]*2500)/1);
    ui->slider_31->setValue(int(fft[31]*2500)/1);

    ui->timeController->setValue(int((( float(m_player->GetPosOfStream()) / m_player->GetTimeOfStream()) *1000)));

    if (m_player->GetPosOfStream() >= m_player->GetTimeOfStream())
        on_btnNext_clicked();
}*/

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
        //for (byte j = 0; j < 32; j++)
            //average[i] += sqrt(fft[i*32 + j]);
            //average[i*32 + j] += sqrt(fft[i*32 + j]);

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

    if (level > (ui->level->value()/100)){
        r = level*(ui->v1r->value()*v1 + ui->v2r->value()*v2 + ui->v3r->value()*v3);
        g = level*(ui->v1g->value()*v1 + ui->v2g->value()*v2 + ui->v3g->value()*v3);
        b = level*(ui->v1b->value()*v1 + ui->v2b->value()*v2 + ui->v3b->value()*v3);
    } else {
        r = 0;
        g = 0;
        b = 0;
    }

    ui->v1r->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v1r->value()) + "," +
                           QString::number(ui->v1g->value()) + "," + QString::number(ui->v1b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(255, 0, 0, 255);}");
    ui->v1g->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v1r->value()) + "," +
                           QString::number(ui->v1g->value()) + "," + QString::number(ui->v1b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 255, 0, 255);}");
    ui->v1b->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v1r->value()) + "," +
                           QString::number(ui->v1g->value()) + "," + QString::number(ui->v1b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 0, 255, 255);}");

    ui->v2r->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v2r->value()) + "," +
                           QString::number(ui->v2g->value()) + "," + QString::number(ui->v2b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(255, 0, 0, 255);}");
    ui->v2g->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v2r->value()) + "," +
                           QString::number(ui->v2g->value()) + "," + QString::number(ui->v2b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 255, 0, 255);}");
    ui->v2b->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v2r->value()) + "," +
                           QString::number(ui->v2g->value()) + "," + QString::number(ui->v2b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 0, 255, 255);}");

    ui->v3r->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v3r->value()) + "," +
                           QString::number(ui->v3g->value()) + "," + QString::number(ui->v3b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(255, 0, 0, 255);}");
    ui->v3g->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v3r->value()) + "," +
                           QString::number(ui->v3g->value()) + "," + QString::number(ui->v3b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 255, 0, 255);}");
    ui->v3b->setStyleSheet("QSlider{background-color:rgb(" + QString::number(ui->v3r->value()) + "," +
                           QString::number(ui->v3g->value()) + "," + QString::number(ui->v3b->value()) + ", 255);}"
                           "QSlider::handle:horizontal{background-color:rgb(0, 0, 255, 255);}");

    // Debug
    qDebug() << level << " " << r << " " << g << " " << b;

    if(m_transmitter->isConnected()) m_transmitter->writeRGB(int(r), int(g), int(b));

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
        on_btnNext_clicked();
}

void Widget::applyStyles()
{
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
    //
    ui->btnAdd->setStyleSheet(StyleHelper::getButtonAddStyleSheet());

    // Plyalist
    ui->playlist->setStyleSheet(StyleHelper::getTableStyleSheet());

    // Sliders
    ui->volController->setStyleSheet(StyleHelper::getSliderStyleSheet());
    ui->timeController->setStyleSheet(StyleHelper::getSliderStyleSheet());

    ui->level->setStyleSheet(StyleHelper::getSliderStyleSheet());

    // Window control buttons
    ui->btn_minimize->setStyleSheet(StyleHelper::getMinimizeStyleSheet());
    ui->btn_maximize->setStyleSheet(StyleHelper::getMaximizeStyleSheet());
    ui->btn_close->setStyleSheet(StyleHelper::getCloseStyleSheet());

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

void Widget::on_btnPrevious_clicked()
{
    if(selectedAudioIndex!=0){
        selectedAudioIndex--;
        Widget::on_btnStop_clicked();
        Widget::on_btnPlay_clicked();
    }
}

void Widget::on_btnStop_clicked()
{
    onPause = false;
    running = false;

    toZeroValues();

    m_player->stop();
}

void Widget::on_btnPlay_clicked()
{
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

    // here we didn't catch an exception
    running = true;
}

void Widget::on_btnPause_clicked()
{
    onPause = true;
    running = false;

    toZeroValues();

    m_player->pause();
}

void Widget::on_btnNext_clicked()
{
    Widget::on_btnStop_clicked();
    if(selectedAudioIndex!=trackList->length() - 1){
        selectedAudioIndex++;
    } else {
        selectedAudioIndex = 0;
    }
    Widget::on_btnPlay_clicked();
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

void Widget::on_btnReconnect_clicked()
{
    m_transmitter = new Transmitter(this);
}
