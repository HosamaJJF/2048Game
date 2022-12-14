#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)    //产生窗口，以下大括号内的代码为窗口运行时执行
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/pic/myico.ico"));  //设置图标
    memset(s,0,sizeof(s));  //初始化数组
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));   //生成随机数种子
    connect(ui->startg,SIGNAL(clicked()),this,SLOT(slotStart()));   //链接槽与开始按钮的clicked信号
    game[1][1]=ui->g11; //初始化指针数组，指针指向棋盘上的label控件
    game[1][2]=ui->g12;
    game[1][3]=ui->g13;
    game[1][4]=ui->g14;
    game[2][1]=ui->g21;
    game[2][2]=ui->g22;
    game[2][3]=ui->g23;
    game[2][4]=ui->g24;
    game[3][1]=ui->g31;
    game[3][2]=ui->g32;
    game[3][3]=ui->g33;
    game[3][4]=ui->g34;
    game[4][1]=ui->g41;
    game[4][2]=ui->g42;
    game[4][3]=ui->g43;
    game[4][4]=ui->g44;
    for(int i=1;i<=4;i++){  //次循环初始化棋盘颜色
        for(int j=1;j<=4;j++){
            game[i][j]->setStyleSheet("QLabel{background:#828282;}");
        }
    }
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paint(){   //此函数用于绘制棋盘
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(s[i][j]==0){
                game[i][j]->setStyleSheet("QLabel{background:#828282;}");
                game[i][j]->setText("");
            }
            else if(s[i][j]==2){
                game[i][j]->setStyleSheet("QLabel{background:#ffe694;}");
                game[i][j]->setText("2");
            }
            else if(s[i][j]==4){
                game[i][j]->setStyleSheet("QLabel{background:#ffe668;}");
                game[i][j]->setText("4");
            }
            else if(s[i][j]==8){
                game[i][j]->setStyleSheet("QLabel{background:#ffc700;}");
                game[i][j]->setText("8");
            }
            else if(s[i][j]==16){
                game[i][j]->setStyleSheet("QLabel{background:#fbb65b;}");
                game[i][j]->setText("16");
            }
            else if(s[i][j]==32){
                game[i][j]->setStyleSheet("QLabel{background:#ffaa01;}");
                game[i][j]->setText("32");
            }
            else if(s[i][j]==64){
                game[i][j]->setStyleSheet("QLabel{background:#ff9600;}");
                game[i][j]->setText("64");
            }
            else if(s[i][j]==128){
                game[i][j]->setStyleSheet("QLabel{background:#ff8201;}");
                game[i][j]->setText("128");
            }
            else if(s[i][j]==256){
                game[i][j]->setStyleSheet("QLabel{background:#ff6e01;}");
                game[i][j]->setText("256");
            }
            else if(s[i][j]==512){
                game[i][j]->setStyleSheet("QLabel{background:#ff5a00;}");
                game[i][j]->setText("512");
            }
            else if(s[i][j]==1024){
                game[i][j]->setStyleSheet("QLabel{background:#fe4600;}");
                game[i][j]->setText("1024");
            }
            else if(s[i][j]==2048){
                game[i][j]->setStyleSheet("QLabel{background:#fe0000;}");
                game[i][j]->setText("2048");
                state=false;
                ui->description->setText("你成功了！！");
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){   //读取键盘输入事件
    if(!state){
        return ;
    }
    switch(event->key()){
        case Qt::Key_W:
            PressUp();
            break;
        case Qt::Key_S:
            PressDown();
            break;
        case Qt::Key_A:
            PressLeft();
            break;
        case Qt::Key_D:
            PressRight();
            break;
        default:
            return; //忽略非方向的输入
    }
    if(state)check();
}

void MainWindow::create(int m){  //此函数用于随机生成格子
    int randi,randj,randnum;
    randi=rand()%4+1;
    randj=rand()%4+1;
    while(s[randi][randj]!=0){
        randi=rand()%4+1;
        randj=rand()%4+1;
    }
    if(m){  //如有特定要求，生成特定要求的数字格，如开局时只能生成两个2
        s[randi][randj]=m;
        game[randi][randj]->setStyleSheet("QLabel{background:#ffe694;}");
        game[randi][randj]->setText("2");
    }
    else {  //没有特定要求，随机生成2或4,其中2的几率90%，4的几率10%
        randnum=rand()%10;
        if(randnum==9){
            s[randi][randj]=4;
            game[randi][randj]->setStyleSheet("QLabel{background:#ffe668;}");
            game[randi][randj]->setText("4");
        }
        else {
            s[randi][randj]=2;
            game[randi][randj]->setStyleSheet("QLabel{background:#ffe694;}");
            game[randi][randj]->setText("2");
        }
    }
}

void MainWindow::slotStart(){   //此函数用于开始/重置游戏
    score=0;
    for(int i=1;i<=4;i++){  //重置棋盘颜色和数字
        for(int j=1;j<=4;j++){
            s[i][j]=0;
            game[i][j]->setStyleSheet("QLabel{background:#828282;}");
            game[i][j]->setText("");
        }
    }
    ui->description->setText("按W(上)S(下)A(左)D(右)让相同数字的方格合并，得到2048！");
    ui->scorenum->setText("0");
    create(2);
    create(2);
    state=true;
}

void MainWindow::PressUp(){ //此函数控制方块（对应的数据）向上移动
    int f=0;
    for(int j=1;j<=4;j++){
        for(int i=1;i<=3;i++){
            for(int k=i+1;k<=4;k++){
                if(s[k][j]){
                    if(s[i][j]==0){
                        s[i][j]=s[k][j];
                        s[k][j]=0;
                        f=1;
                    }
                    else {
                        if(s[i][j]==s[k][j]){
                            s[i][j]*=2;
                            s[k][j]=0;
                            score+=s[i][j];
                            f=1;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
    }
    if(f){
        ui->scorenum->setText(QString::number(score));  //刷新分数
        create(0);
        paint();
    }
}

void MainWindow::PressDown(){   //此函数控制方块（对应的数据）向下移动
    int f=0;
    for(int j=1;j<=4;j++){
        for(int i=4;i>=2;i--){
            for(int k=i-1;k>=1;k--){
                if(s[k][j]){
                    if(s[i][j]==0){
                        s[i][j]=s[k][j];
                        s[k][j]=0;
                        f=1;
                    }
                    else {
                        if(s[i][j]==s[k][j]){
                            s[i][j]*=2;
                            s[k][j]=0;
                            score+=s[i][j];
                            f=1;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
    }
    if(f){
        ui->scorenum->setText(QString::number(score));  //刷新分数
        create(0);
        paint();
    }
}

void MainWindow::PressLeft(){   //此函数控制方块（对应的数据）向左移动
    int f=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=3;j++){
            for(int k=j+1;k<=4;k++){
                if(s[i][k]){
                    if(s[i][j]==0){
                        s[i][j]=s[i][k];
                        s[i][k]=0;
                        f=1;
                    }
                    else {
                        if(s[i][j]==s[i][k]){
                            s[i][j]*=2;
                            s[i][k]=0;
                            score+=s[i][j];
                            f=1;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
    }
    if(f){
        ui->scorenum->setText(QString::number(score));  //刷新分数
        create(0);
        paint();
    }
}

void MainWindow::PressRight(){  //此函数控制方块（对应的数据）向右移动
    int f=0;
    for(int i=1;i<=4;i++){
        for(int j=4;j>=2;j--){
            for(int k=j-1;k>=1;k--){
                if(s[i][k]){
                    if(s[i][j]==0){
                        s[i][j]=s[i][k];
                        s[i][k]=0;
                        f=1;
                    }
                    else {
                        if(s[i][j]==s[i][k]){
                            s[i][j]*=2;
                            s[i][k]=0;
                            score+=s[i][j];
                            f=1;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
    }
    if(f){
        ui->scorenum->setText(QString::number(score));  //刷新分数
        create(0);
        paint();
    }
}

void MainWindow::check(){   //此函数用于检测游戏失败
    int f=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(s[i][j]==0)return;
        }
    }
    for(int i=1;i<=3;i++){  //判断是否有可以合并的方格
        for(int j=1;j<=3;j++){
            if(s[i][j]==s[i][j+1]){
                f++;
                break;
            }
            if(s[i][j]==s[i+1][j]){
                f++;
                break;
            }
        }
    }
    for(int j=1;j<=3;j++){
        if(s[4][j]==s[4][j+1]){
                f++;
                break;
        }
    }
    for(int i=1;i<=3;i++){
        if(s[i][4]==s[i+1][4]){
            f++;
            break;
        }
    }
    if(f)return;
    else {
        state=false;
        ui->description->setText("你失败了QAQ");
    }
}