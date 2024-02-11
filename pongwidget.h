#ifndef PONGWIDGET_H
#define PONGWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QRect>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

class PongWidget : public QWidget {
    Q_OBJECT
public:
    PongWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void updateGame();
private:
    QRect screen;
    QRect leftRaquette;
    QRect rightRaquette;
    QRect ball;
    QTimer *gameTimer;
    short angle;
    double speed = 10;
};


#endif // PONGWIDGET_H
