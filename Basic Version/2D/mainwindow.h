#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QMainWindow>
#include <QtCore/qmath.h>
#include <QPen>
#include "turtle.h"
#include "lsystem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString                 sequence;

private:
    QTimer                  *timer;
    Turtle                  *turtle;
    LSystem                 *lsystem;
    QBrush                  brush;
    QPen                    pen;
    QImage                  image;

    void trace(QPainter *painter, QString sequence);
    qreal randReal(int low, int high);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
