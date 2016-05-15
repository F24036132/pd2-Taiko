#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//設定主視窗
    ui->setupUi(this);
    this->setWindowTitle("Taiko");
    this->setFixedSize(700,480);
    ui->centralWidget->setObjectName("background");
    ui->centralWidget->setStyleSheet("#background{border-image:url(:/img/images/front2.jpg);}");
    ui->scoreDec->hide();
//設定開始與離開按鈕
    start = new QPushButton(this);
    start->setText("START");
    start->setGeometry(480,360,100,40);
    start->setFont(QFont("華康秀風體W3",24,QFont::Bold));
    exit = new QPushButton(this);
    exit->setText("EXIT");
    exit->setGeometry(120,360,100,40);
    exit->setFont(QFont("華康秀風體W3",24,QFont::Bold));
    connect(start,SIGNAL(clicked(bool)),this,SLOT(goToGamePage()));
    connect(exit,SIGNAL(clicked(bool)),this,SLOT(closeGame()));
//設定重玩按鈕
    replay = new QPushButton(this);
    replay->setText("RESTART");
    replay->setGeometry(50,50,130,40);
    replay->setFont(QFont("華康秀風體W3",24,QFont::Bold));
    connect(replay,SIGNAL(clicked(bool)),this,SLOT(backToGamePage()));
    replay->hide();
//設定說明按鈕
    help = new QPushButton(this);
    help->setText("HELP");
    help->setGeometry(300,360,100,40);
    help->setFont(QFont("華康秀風體W3",24,QFont::Bold));
    connect(help,SIGNAL(clicked(bool)),this,SLOT(showHelp()));
//設定返回主頁按鈕
    back = new QPushButton(this);
    back->setText("BACK");
    back->setGeometry(550,50,100,40);
    back->setFont(QFont("華康秀風體W3",24,QFont::Bold));
    connect(back,SIGNAL(clicked(bool)),this,SLOT(backToStart()));
    back->hide();
}
//返回主頁SLOT
void MainWindow::backToStart()
{
    replay->hide();
    back->hide();
    ui->scoreDec->hide();
    delete score;
    delete finalScoreTimer;
    success=0;
    ui->centralWidget->setObjectName("background");
    ui->centralWidget->setStyleSheet("#background{border-image:url(:/img/images/front2.jpg);}");
    start->show();
    exit->show();
    help->show();
}
//說明SLOT
void MainWindow::showHelp()
{
    explain.show();
}
//開始遊戲SLOT
void MainWindow::goToGamePage()
{
    start->hide();
    exit->hide();
    help->hide();
    gamePage();

}
//重玩遊戲SLOT
void MainWindow::backToGamePage()
{
    replay->hide();
    ui->scoreDec->hide();
    delete score;
    delete finalScoreTimer;
    success=0;
    gamePage();
}
//關閉遊戲
void MainWindow::closeGame()
{
    this->close();
}
//遊戲畫面
void MainWindow::gamePage()
{
    gameStatus=true;
    ui->centralWidget->setObjectName("background");
    ui->centralWidget->setStyleSheet("#background{border-image:url(:/img/images/bg.png);}");
    musicSelect();

//設定打擊點圖片
    hitPoint = new QLabel(this);
    hitPoint->setStyleSheet("border-image:url(:/img/images/hitpoint.png)");
    hitPoint->setGeometry(130,140,55,55);
    hitPoint->show();

    points();

//設定鼓圖片
    drum = new QLabel(this);
    drum->setStyleSheet("border-image:url(:/img/images/mtaiko.png)");
    drum->setGeometry(0,120,620,90);
    drum->show();
    reddrum = new QLabel(this);
    reddrum->setStyleSheet("border-image:url(:/img/images/mtaikoflash_red.png)");
    reddrum->setGeometry(12,104,100,100);
    reddrum->hide();
    bluedrum = new QLabel(this);
    bluedrum->setStyleSheet("border-image:url(:/img/images/mtaikoflash_blue.png)");
    bluedrum->setGeometry(7,104,111,103);
    bluedrum->hide();

    riverTop();
    countDown();
    girl_chick();
    taikokun();
    scoreTab();
}
//隨機選擇音樂
void MainWindow::musicSelect()
{
    int select;
    music = new QMediaPlayer();
    srand((unsigned)time(NULL));
    select = (rand()%5)+1;
    switch (select) {
    case 1:
        music->setMedia(QUrl("qrc:/bgm/bgm/SPYAIR_-_[1_mp3cut_net_mp3.wav"));
        break;
    case 2:
        music->setMedia(QUrl("qrc:/bgm/bgm/_-_[1_mp3cut_net_mp3 (1).wav"));
        break;
    case 3:
        music->setMedia(QUrl("qrc:/bgm/bgm/_-_[1_mp3cut_net_mp3 (2).wav"));
        break;
    case 4:
        music->setMedia(QUrl("qrc:/bgm/bgm/_-_[1_mp3cut_net_mp3.wav"));
        break;
    case 5:
        music->setMedia(QUrl("qrc:/bgm/bgm/_Go_to_Heart_Edge_cv_[1_mp.wav"));
        break;
    default:
        break;
    }

    music->play();
}
//設定points
void MainWindow::points()
{
//points
    redpoint = new QLabel(this);
    redpoint->resize(40,40);
    redpoint->setStyleSheet("border-image:url(:/img/images/redpoint.png);");
    redpoint->show();
    redpoint2 = new QLabel(this);
    redpoint2->resize(40,40);
    redpoint2->setStyleSheet("border-image:url(:/img/images/redpoint.png);");
    redpoint2->show();
    redpoint3 = new QLabel(this);
    redpoint3->resize(40,40);
    redpoint3->setStyleSheet("border-image:url(:/img/images/redpoint.png);");
    redpoint3->show();
    bluepoint = new QLabel(this);
    bluepoint->resize(40,40);
    bluepoint->setStyleSheet("border-image:url(:/img/images/bluepoint.png);");
    bluepoint->show();
    bluepoint2 = new QLabel(this);
    bluepoint2->resize(40,40);
    bluepoint2->setStyleSheet("border-image:url(:/img/images/bluepoint.png);");
    bluepoint2->show();
    bluepoint3 = new QLabel(this);
    bluepoint3->resize(40,40);
    bluepoint3->setStyleSheet("border-image:url(:/img/images/bluepoint.png);");
    bluepoint3->show();
//初始x位置
    srand((unsigned)time(NULL));
    xR = (rand()%700)+700;
    xR2 = (rand()%700)+750;
    xR3 = (rand()%700)+850;
    xB = (rand()%700)+800;
    xB2 = (rand()%700)+900;
    xB3 = (rand()%700)+950;
//timer
    pointTimer = new QTimer(this);
    connect(pointTimer,SIGNAL(timeout()),this,SLOT(pointMove()));
    pointTimer->start(5);
}
//移動point
void MainWindow::pointMove()
{
    xR-=1;
    xR2-=1;
    xR3-=1;
    xB-=1;
    xB2-=1;
    xB3-=1;
    redpoint->move(QPoint(xR,y));
    redpoint2->move(QPoint(xR2,y));
    redpoint3->move(QPoint(xR3,y));
    bluepoint->move(QPoint(xB,y));
    bluepoint2->move(QPoint(xB2,y));
    bluepoint3->move(QPoint(xB3,y));
    if(xR<=70) xR = (rand()%700)+700;
    if(xR2<=70) xR2 = (rand()%700)+750;
    if(xR3<=70) xR3 = (rand()%700)+850;
    if(xB<=70) xB = (rand()%700)+800;
    if(xB2<=70) xB2 = (rand()%700)+900;
    if(xB3<=70) xB3 = (rand()%700)+950;
}
//計分
void MainWindow::scoreTab()
{
    score = new QLabel(this);
    score->setGeometry(570,75,120,40);
    score->setFont(QFont("Hobo Std",24));
    score->setStyleSheet("color:white");
    score->setAlignment(Qt::AlignRight);
    score->setText(QString::number(success));
    score->show();
}
//按鍵計分
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(gameStatus){
        if(event->key() == Qt::Key_Z){
            QSound::play(":/bgm/bgm/dong.wav");
            reddrum->show();
            if(xR>=130&&xR<=140){
                success+=1000;
                score->setText(QString::number(success));
            }
            else if(xR>=141&&xR<=150){
                success+=800;
                score->setText(QString::number(success));
            }
            if(xR2>=130&&xR2<=140){
                success+=1000;
                score->setText(QString::number(success));
            }
            else if(xR2>=141&&xR2<=150){
                success+=800;
                score->setText(QString::number(success));
            }
            if(xR3>=130&&xR3<=140){
                success+=1000;
                score->setText(QString::number(success));
            }
            else if(xR3>=141&&xR3<=150){
                success+=800;
                score->setText(QString::number(success));
            }
            event->accept();
        }

        if(event->key() == Qt::Key_M){
            QSound::play(":/bgm/bgm/ka.wav");
            bluedrum->show();
            if(xB>=130&&xB<=140){
                success+=1000;
                score->setText(QString::number(success));
            }
            else if(xB>=141&&xB<=150){
                success+=800;
                score->setText(QString::number(success));
            }
            if(xB2>=130&&xB2<=140){
                success+=1000;
                score->setText(QString::number(success));
            }
            else if(xB2>=141&&xB2<=150){
                success+=800;
                score->setText(QString::number(success));
            }
            if(xB3>=130&&xB3<=140){
                success+=1000;
                score->setText(QString::number(success));
            }
            else if(xB3>=141&&xB3<=150){
                success+=800;
                score->setText(QString::number(success));
            }
            event->accept();
        }
    }
}
//Z&M按鍵事件
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(gameStatus){
        if(event->key() == Qt::Key_Z){
            reddrum->hide();
            event->accept();
        }
        if(event->key() == Qt::Key_M){
            bluedrum->hide();
            event->accept();
        }
    }
}
//設定倒數計時器
void MainWindow::countDown()
{
//計時器
    counter = new QLabel(this);
    counter->setGeometry(300,30,100,70);
    counter->setFont(QFont("Hobo Std",48,QFont::Bold));
    counter->setAlignment(Qt::AlignCenter);
    counter->show();
//計時器timer
    countDownTimer = new QTimer(this);
    connect(countDownTimer, SIGNAL(timeout()),this,SLOT(countDownThirty()));
    countDownTimer->start(1000);
}
//倒數計時器SLOT
void MainWindow::countDownThirty()
{
    counter->setText(QString::number(countTime));
    countTime-=1;
    if(countTime==-2){
        countTime=30;
        countDownTimer->stop();
        showScore();
    }
}
//顯示分數頁面
void MainWindow::showScore()
{
    gameStatus=false;
    ui->centralWidget->setObjectName("background");
    ui->centralWidget->setStyleSheet("#background{border-image:url(:/img/images/score_bg.jpg);}");
    ui->scoreDec->show();

    score->setGeometry(190,150,300,120);
    score->setFont(QFont("Hobo Std",72));
    score->setStyleSheet("color:white");
    score->setAlignment(Qt::AlignCenter);

    finalScoreTimer = new QTimer(this);
    connect(finalScoreTimer,SIGNAL(timeout()),this,SLOT(scoreCount()));
    finalScoreTimer->start(0.01);

    delete drum;
    delete reddrum;
    delete bluedrum;
    delete hitPoint;
    delete counter;
    delete countDownTimer;
    delete redpoint;
    delete redpoint2;
    delete redpoint3;
    delete bluepoint;
    delete bluepoint2;
    delete bluepoint3;
    delete pointTimer;
    delete music;
    delete taikoK;
    delete taikokunTimer;
    delete river;
    delete river2;
    delete riverTimer;
    delete girl;
    delete girl2;
    delete girl3;
    delete girl_chick_Timer;
    delete chicken;
}
//計算分數SLOT
void MainWindow::scoreCount()
{
    static int i=0;
    QSound::play(":/bgm/bgm/glass-clink-2.wav");
    score->setText(QString::number(i));
    i+=100;
    if(i>success) {
        i=0;
        QSound::play(":/bgm/bgm/applause.wav");
        finalScoreTimer->stop();
        replay->show();
        back->show();
    }
}
//設定女孩&小雞動圖
void MainWindow::girl_chick()
{
//小雞
    chicken = new QLabel(this);
    chicken->setStyleSheet("border-image:url(:/img/images/runner1.png)");
    chicken->setGeometry(0,200,49,51);
    chicken->show();
    chickPose=1;
//女孩
    girl = new QLabel(this);
    girl->setStyleSheet("border-image:url(:/img/images/dancer_2n1.png)");
    girl->setGeometry(260,200,180,240);
    girl->show();
    girl2 = new QLabel(this);
    girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n1.png)");
    girl2->setGeometry(50,200,180,240);
    girl2->show();
    girl3 = new QLabel(this);
    girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n1.png)");
    girl3->setGeometry(470,200,180,240);
    girl3->show();
    pose=1;
//timer
    girl_chick_Timer = new QTimer(this);
    connect(girl_chick_Timer, SIGNAL(timeout()),this,SLOT(girl_chick_Move()));
    girl_chick_Timer->start(100);
}
//女孩&小雞動圖SLOT
void MainWindow::girl_chick_Move()
{
    if(chickRun==700) chickRun=-50;
    pose+=1;
    chickPose+=1;
    chickRun+=5;
    switch (pose) {
    case 1:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n1.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n1.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n1.png)");
        break;
    case 2:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n2.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n2.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n2.png)");
        break;
    case 3:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n3.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n3.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n3.png)");
        break;
    case 4:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n4.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n4.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n4.png)");
        break;
    case 5:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n5.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n5.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n5.png)");
        break;
    case 6:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n6.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n6.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n6.png)");
        break;
    case 7:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n7.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n7.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n7.png)");
        break;
    case 8:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n8.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n8.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n8.png)");
        break;
    case 9:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n9.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n9.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n9.png)");
        break;
    case 10:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n10.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n10.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n10.png)");
        break;
    case 11:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n11.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n11.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n11.png)");
        break;
    case 12:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n12.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n12.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n12.png)");
        break;
    case 13:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n13.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n13.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n13.png)");
        break;
    case 14:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n14.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n14.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n14.png)");
        break;
    case 15:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n15.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n15.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n15.png)");
        break;
    case 16:
        girl->setStyleSheet("border-image:url(:/img/images/dancer_2n16.png)");
        girl2->setStyleSheet("border-image:url(:/img/images/dancer_3n16.png)");
        girl3->setStyleSheet("border-image:url(:/img/images/dancer_4n16.png)");
        pose=0;
        break;
    default:
        break;
    }
    switch (chickPose) {
    case 1:
        chicken->setStyleSheet("border-image:url(:/img/images/runner1.png)");
        chicken->setGeometry(chickRun,200,49,51);
        break;
    case 2:
        chicken->setStyleSheet("border-image:url(:/img/images/runner2.png)");
        chicken->setGeometry(chickRun,200,53,51);
        break;
    case 3:
        chicken->setStyleSheet("border-image:url(:/img/images/runner3.png)");
        chicken->setGeometry(chickRun,200,53,51);
        break;
    case 4:
        chicken->setStyleSheet("border-image:url(:/img/images/runner1.png)");
        chicken->setGeometry(chickRun,200,46,54);
        break;
    case 5:
        chicken->setStyleSheet("border-image:url(:/img/images/runner5.png)");
        chicken->setGeometry(chickRun,200,51,55);
        break;
    case 6:
        chicken->setStyleSheet("border-image:url(:/img/images/runner6.png)");
        chicken->setGeometry(chickRun,200,52,55);
        break;
    case 7:
        chicken->setStyleSheet("border-image:url(:/img/images/runner7.png)");
        chicken->setGeometry(chickRun,200,52,52);
        break;
    case 8:
        chicken->setStyleSheet("border-image:url(:/img/images/runner8.png)");
        chicken->setGeometry(chickRun,200,49,51);
        break;
    case 9:
        chicken->setStyleSheet("border-image:url(:/img/images/runner9.png)");
        chicken->setGeometry(chickRun,200,53,51);
        break;
    case 10:
        chicken->setStyleSheet("border-image:url(:/img/images/runner10.png)");
        chicken->setGeometry(chickRun,200,53,51);
        break;
    case 11:
        chicken->setStyleSheet("border-image:url(:/img/images/runner11.png)");
        chicken->setGeometry(chickRun,200,46,54);
        break;
    case 12:
        chicken->setStyleSheet("border-image:url(:/img/images/runner12.png)");
        chicken->setGeometry(chickRun,200,51,55);
        break;
    case 13:
        chicken->setStyleSheet("border-image:url(:/img/images/runner13.png)");
        chicken->setGeometry(chickRun,200,52,55);
        break;
    case 14:
        chicken->setStyleSheet("border-image:url(:/img/images/runner14.png)");
        chicken->setGeometry(chickRun,200,52,52);
        chickPose=0;
        break;
    default:
        break;
    }
}
//設定太鼓君動圖
void MainWindow::taikokun()
{
//太鼓君
    taikoK = new QLabel(this);
    taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p1.png)");
    taikoK->setGeometry(0,8,150,112);
    taikoK->show();
    change=2;
//timer
    taikokunTimer = new QTimer(this);
    connect(taikokunTimer, SIGNAL(timeout()),this,SLOT(taikokunMove()));
    taikokunTimer->start(250);
}
//太鼓君SLOT
void MainWindow::taikokunMove()
{
    if (countTime==19){
        taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p3.png)");
        change=4;
    }
    switch (change) {
    case 1:
        taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p1.png)");
        change=2;
        break;
    case 2:
        taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p2.png)");
        change=1;
        break;
    case 3:
        taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p3.png)");
        taikoK->setGeometry(0,8,160,112);
        change=4;
        break;
    case 4:
        taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p4.png)");
        taikoK->setGeometry(0,8,160,112);
        change=5;
        break;
    case 5:
        taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p5.png)");
        taikoK->setGeometry(0,8,150,112);
        change=6;
        break;
    case 6:
        taikoK->setStyleSheet("border-image:url(:/img/images/playerchar_p6.png)");
        taikoK->setGeometry(0,8,130,112);
        change=3;
        break;
    default:
        break;
    }
}
//設定河流背景
void MainWindow::riverTop()
{
//河流
    river = new QLabel(this);
    river->setStyleSheet("border-image:url(:/img/images/bg_p2.png)");
    river->setGeometry(0,10,700,110);
    river->show();
    river2 = new QLabel(this);
    river2->setStyleSheet("border-image:url(:/img/images/bg_p2.png)");
    river2->setGeometry(700,10,700,110);
    river2->show();
//河流timer
    riverTimer = new QTimer();
    connect(riverTimer,SIGNAL(timeout()),this,SLOT(riverMove()));
    riverTimer->start(150);
}
//河流背景SLOT
void MainWindow::riverMove()
{
    riverSpeed -=4;
    river->move(QPoint(riverSpeed,10));
    river2->move(QPoint((riverSpeed+700),10));
    if(riverSpeed==-700) riverSpeed=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
