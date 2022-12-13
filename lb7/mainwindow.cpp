#include "mainwindow.h"
#include "ui_mainwindow.h"



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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint point_click = event->pos();
    qDebug() << point_click;

   if (
           ((point_click.x() >= center_sqr.x()) && (point_click.x() <= center_sqr.x() + this->size_sqr))
          &&
           ((point_click.y() >= center_sqr.y()) && (point_click.y() <= center_sqr.y() + this->size_sqr))
       )
   {
       qDebug() << "popal";
       this->active = true;
   }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(this->active == true)
    {
        this->center_sqr = event->pos();
        repaint();

    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     this->active =false;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);

    QBrush brush;
    brush.setColor(Qt:: red);
    brush.setStyle(Qt::SolidPattern);


    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(this->center_sqr.x(), this->center_sqr.y(),this->size_sqr, this->size_sqr );
    painter.end();
}
