//X -> F-[[X]+X]+F[+FX]-X
//F -> FF
#include "mainwindow.h"
#include <iostream>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow()
{
    setWindowTitle("L-System");
    setGeometry(QRect(QPoint(100,100), QPoint(800, 600)));

    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));

    qsrand((uint)QTime::currentTime().msec());

    lsystem = new LSystem();
    lsystem->getRules("rules.txt");
    sequence = lsystem->substitute("F+F+F+F", 4);

    qreal angle = 90.0;
    qreal step  = 3.0;
    qreal startAngle = 0.0;
    QPointF origine(0.0, 0.0);

    turtle = new Turtle(origine, startAngle, step, angle);

    pen = QPen(QColor(0, 102, 51), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    timer->start(200);
}

MainWindow::~MainWindow()
{
    if(turtle)  delete turtle;
    if(lsystem) delete lsystem;
}

void MainWindow::trace(QPainter *painter, QString sequence)
{
    QPointF oldPosition;
    QPointF newPosition;

    for(int i=0;i<sequence.length();i++)
    {
        switch(sequence.at(i).toLatin1())
        {
        case 'F':
            oldPosition = turtle->state.getPosition();
            newPosition = turtle->Move();
            painter->drawLine(oldPosition, newPosition);
            break;
        case 'f':
            turtle->Move();
            break;
        case '-':
            turtle->TurnRight();
            break;
        case '+':
            turtle->TurnLeft();
            break;
        case '[':
            turtle->StatePush();
            break;
        case ']':
            turtle->StatePop();
            break;
        default:
            break;
        }
    }
}

qreal MainWindow::randReal(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low) * 1.0;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);
    painter.fillRect(this->rect(), Qt::black);
    if(sequence.length() > 0 && turtle)
    {
        turtle->state.setAngle(0.0);
        turtle->state.setPosition(QPointF(100.0, 500.0));
        turtle->stepAngle = 90.0;//randReal(10, 30) * 1.0;
        trace(&painter, sequence);
    }
    painter.end();
}
