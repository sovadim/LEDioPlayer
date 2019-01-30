#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bass.h"
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include "stylehelper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Styles settings
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
    ui->label_Audio->setText("m_player inited");

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
        MainWindow::on_btnStop_clicked();
        MainWindow::on_btnPlay_clicked();
    });

    trackList = new QStringList();

    // Timer allow us to update visualization
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(drawSpectrum()));
    timer->start(25);

    m_transmitter = new Transmitter(this);
}

void MainWindow::applyStyles()
{
    // UI settings
    this->setWindowFlags(Qt::FramelessWindowHint); //Отключение оформления окна
    this->setAttribute(Qt::WA_TranslucentBackground); //Фон главного виджета - прозрачный
    this->setStyleSheet(StyleHelper::getWindowStyleSheet());
    this->setMouseTracking(true);

    // Создание тени
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(9);
    shadowEffect->setOffset(0);

    //ui->widgetInterface->setGraphicsEffect(shadowEffect);
    //ui->widgetInterface->layout()->setMargin(0);
    //ui->widgetInterface->layout()->setSpacing(0);
    //ui->label->setText("My player");
    //ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawSpectrum(){

    if(!running) return;

    float fft[1024];

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

    m_transmitter->writeRGB(int(r), int(g), int(b));

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

    ui->timeController->setValue(int((( float(m_player->GetPosOfStream()) / m_player->GetTimeOfStream()) *1000)));

    if (m_player->GetPosOfStream() >= m_player->GetTimeOfStream())
        on_btnNext_clicked();

}

void MainWindow::on_btnAdd_clicked()
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

void MainWindow::on_btnPlay_clicked()
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

QString MainWindow::getAudioFileName(QString filename){
    return filename.mid(filename.lastIndexOf('/') + 1, filename.lastIndexOf('.') - filename.lastIndexOf('/') - 1);
}

void MainWindow::on_btnPause_clicked()
{
    onPause = true;
    running = false;

    toZeroValues();

    m_player->pause();
}

void MainWindow::on_btnStop_clicked()
{
    onPause = false;
    running = false;

    toZeroValues();

    m_player->stop();
}

void MainWindow::on_btnPrevious_clicked()
{
    if(selectedAudioIndex!=0){
        selectedAudioIndex--;
        MainWindow::on_btnStop_clicked();
        MainWindow::on_btnPlay_clicked();
    }
}

void MainWindow::on_btnNext_clicked()
{
    MainWindow::on_btnStop_clicked();
    if(selectedAudioIndex!=trackList->length() - 1){
        selectedAudioIndex++;
    } else {
        selectedAudioIndex = 0;
    }
    MainWindow::on_btnPlay_clicked();
}

void MainWindow::on_volController_valueChanged(int value)
{
    ui->label_Vol->setText(QString::number(value));
    m_player->SetVolumeToStream(value);
}

void MainWindow::toZeroValues()
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
}

void MainWindow::on_MainWindow_destroyed()
{
    m_player->free();
}
