#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    pongWidget = new PongWidget(this);

    setCentralWidget(pongWidget);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);

    QPainter painter(this);

    painter.fillRect(rect(), Qt::black);
}
