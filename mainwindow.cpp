#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPainter>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool cmp(const request& a, const request& b){
    return a.num < b.num;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //设置背景
    QRect rect(QPoint(0, 0), QPoint(1500, 800));
    QLinearGradient linear(rect.topLeft(), rect.bottomLeft());
    linear.setColorAt(0, QColor(255, 182, 193, 255));
    linear.setColorAt(1, QColor(135, 206, 250, 255));
    painter.setBrush(linear);
    painter.drawRect(rect);
    //画上下边界
    int l = 50, r = 1450, t = 80, b = 750;
    painter.setPen(QPen(Qt::black, 4));
    painter.drawLine(l, t, r, t);
    painter.drawLine(l, b, r, b);
    //依次画点、连线
    painter.setPen(QPen(Qt::black, 2));
    int n_req = management.getAns().size();
    if (n_req == 0) return;
    vector<request> copy(management.getAns());
    request p;
    p.num = management.getNow();
    copy.push_back(p);
    sort(copy.begin(), copy.end(), cmp);
    int maxlen = copy.back().num - copy.front().num;
    int minnum = copy.front().num;
    QPoint p1(l + (management.getNow() - minnum) * (r - l) / maxlen, t + (b - t) / (n_req + 2));
    QPoint p2;
    painter.drawPoint(p1);  //磁头初始位置
    painter.drawText(p1.x() - 20, p1.y()+20, "磁头");
    float len = 10.0;        //箭头的长度
    float a = 0.5;          //箭头与线段角度
    int i = 2;
    vector<request> Ans(management.getAns());
    for (auto it = Ans.begin();it != Ans.end();it++){
        p2 = p1;
        p1.setX(l + (it->num - minnum) * (r - l) / maxlen);
        p1.setY(t + i * (b - t) / (n_req + 2));
        painter.drawLine(p2, p1);
        //画箭头
        float x3 = p1.x() - len * cos(atan2((p1.y() - p2.y()) , (p1.x() - p2.x())) - a);
        float y3 = p1.y() - len * sin(atan2((p1.y() - p2.y()) , (p1.x() - p2.x())) - a);
        float x4 = p1.x() - len * sin(atan2((p1.x() - p2.x()) , (p1.y() - p2.y())) - a);
        float y4 = p1.y() - len * cos(atan2((p1.x() - p2.x()) , (p1.y() - p2.y())) - a);
        painter.drawLine(p1.x(), p1.y(), x3, y3);
        painter.drawLine(p1.x(), p1.y(), x4, y4);
        //显示标签
        painter.drawText(p1.x() - 20, p1.y() + 20, QString::fromStdString(it->name));
        painter.drawText(p1.x(), p1.y() + 20, QString::number(it->num));
        i++;
    }
    //显示平均移动道数
    painter.drawText(670, b + 30, "平均移动道数：" + QString::number(management.avg(), 'f', 5));
}

void MainWindow::on_readButton_clicked()
{
    QFile file;
    QString f = QFileDialog::getOpenFileName(this, QString("选择文件"), QString("/"),QString("TEXT(*.txt)"));
    file.setFileName(f);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //读入数据
        QTextStream in(&file);
        request p;
        QString line = in.readLine();
        QStringList sl = line.split(' ');
        management.setNow(sl[0].toInt());
        management.set_d(sl[1].toInt());
        management.reread();
        while (!in.atEnd()){
             line = in.readLine();
             sl = line.split(' ');
             management.addreq(sl[0].toStdString(), sl[1].toInt());
        }
        file.close();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("用户取消读入！");
        msgBox.exec();
    }
}

void MainWindow::on_startButton_clicked()
{
    switch(ui->comboBox->currentIndex()){
    case 0:management.FCFS();break;
    case 1:management.SSTF();break;
    case 2:management.SCAN();break;
    default:break;
    }
    update();
}

void MainWindow::on_clearButton_clicked()
{
    management.clear();
    update();
}
