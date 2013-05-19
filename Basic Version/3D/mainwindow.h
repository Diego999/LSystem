#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myGLWidget.h"
#include "turtle.h"
#include <GL/glu.h>

class MainWindow : public myGLWidget
{
    Q_OBJECT
private:
    Turtle turtle;
public:
    explicit MainWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void function(QVector3D old);
};

#endif // MAINWINDOW_H
