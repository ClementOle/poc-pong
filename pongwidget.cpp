#include "PongWidget.h"

PongWidget::PongWidget(QWidget *parent): QWidget(parent) {
    setFocus();
    setFixedSize(600, 600);
    leftRaquette = QRect(50, 250, 20, 100);
    rightRaquette = QRect(parent->rect().right() - 100, parent->rect().top() + 250, 20, 100);
    ball = QRect(1, 250, 10, 10);
    screen = this->geometry();
    angle = 15;
    gameTimer = new QTimer(this);
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateGame()));
    gameTimer->start(1000/60);
}

void PongWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(leftRaquette, Qt::white);
    painter.fillRect(rightRaquette, Qt::white);
    painter.fillRect(ball, Qt::white);
}

void PongWidget::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_Up:
            leftRaquette.translate(0, -10);
            break;
        case Qt::Key_Down:
            leftRaquette.translate(0, 10);
            break;
        case Qt::Key_Z:
            rightRaquette.translate(0, -10);
            break;
        case Qt::Key_S:
            rightRaquette.translate(0, 10);
            break;
        case Qt::Key_Space:
            if(speed == 0) {
                speed = 10;
            } else {
                speed = 0;
            }
            break;
    }

    update();
}

void PongWidget::updateGame() {

    if (ball.right() >= screen.width()
        || ball.left() <= 0
        || (leftRaquette.contains(ball) && leftRaquette.right() >= ball.left() && leftRaquette.left() <= ball.right())
        || (rightRaquette.contains(ball) && rightRaquette.right() >= ball.left() && rightRaquette.left() <= ball.right())) {
        angle = 180 - angle; // Inverser l'angle pour rebondir
    } else if (ball.bottom() >= screen.height()
               || ball.top() <= 0
               || (leftRaquette.contains(ball) && leftRaquette.right() <= ball.left() && leftRaquette.left() >= ball.right())
               || (rightRaquette.contains(ball) && rightRaquette.right() <= ball.left() && rightRaquette.left() >= ball.right())) {
        angle = -angle; // Inverser l'angle pour rebondir
    }

    double radian = angle * M_PI / 180.0;
    int dx = speed * std::cos(radian);
    int dy = speed * std::sin(radian);

    ball.translate(dx, dy);

    update();
 }

