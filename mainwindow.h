#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <DiskManagement.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    DiskManagement management;

private slots:
    void on_readButton_clicked();
    void on_startButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
