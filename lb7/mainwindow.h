#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent* ) override;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPoint center_sqr = QPoint(10,10);

private:
    Ui::MainWindow *ui;
    int size_sqr = 50;
    bool active = false;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H
