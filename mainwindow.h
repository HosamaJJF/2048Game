#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QLabel>
#include <QKeyEvent>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);   //读取键盘输入事件
    QLabel *game[5][5];   //定义棋盘label的指针数组
    int s[5][5];    //储存棋盘数字的数组
    int score=0;    //分数
    bool state=false; //游戏状态，true进行中false未运行
    void PressUp(); //以下四行是与键盘操作对应的函数
    void PressDown();
    void PressLeft();
    void PressRight();
    void create(int s); //创建随机方格
    void paint();   //绘制方格
    void check();   //检测游戏失败

public slots:
    void slotStart();   //定义槽函数

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
