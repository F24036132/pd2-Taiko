#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "explain.h"
#include <time.h>
#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QMediaPlayer>
#include <QSound>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void girl_chick();
    void taikokun();
    void countDown();
    void riverTop();
    void scoreTab();
    void points();
    void showScore();
    void gamePage();
    void musicSelect();


public slots:
    void goToGamePage();
    void backToStart();
    void closeGame();
    void backToGamePage();
    void countDownThirty();
    void pointMove();
    void girl_chick_Move();
    void taikokunMove();
    void riverMove();
    void scoreCount();
    void showHelp();



private:
    Ui::MainWindow *ui;
    Explain explain;
//主畫面按鈕
    QPushButton *start;
    QPushButton *exit;
    QPushButton *help;
    QPushButton *back;
    QPushButton *replay;
//遊戲畫面
    QMediaPlayer *music;
    QLabel *drum;
    QLabel *reddrum;
    QLabel *bluedrum;
    QLabel *hitPoint;
    QLabel *counter;
    QTimer *countDownTimer;
    int countTime=30;
    QLabel *redpoint;
    QLabel *redpoint2;
    QLabel *redpoint3;
    QLabel *bluepoint;
    QLabel *bluepoint2;
    QLabel *bluepoint3;
    int xR,xR2,xR3,xB,xB2,xB3, y=148;
    QTimer *pointTimer;
    QLabel *score;
    int success=0;
    QLabel *taikoK;
    QTimer *taikokunTimer;
    int change;
    QLabel *river;
    QLabel *river2;
    int riverSpeed=0;
    QTimer *riverTimer;
    QLabel *girl;
    QLabel *girl2;
    QLabel *girl3;
    int pose;
    QLabel *chicken;
    int chickRun=0;
    int chickPose;
    QTimer *girl_chick_Timer;
    QTimer *finalScoreTimer;
    bool gameStatus=false;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
