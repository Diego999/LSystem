#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : myGLWidget(60, parent, "Premier Polygone avec OpenGL et Qt")
{
}

void MainWindow::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MainWindow::resizeGL(int width, int height)
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MainWindow::function(QVector3D old)
{
    qDebug() << old;
    glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(old.x(), old.y(), old.z());
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(turtle.state.getPosition().x(), turtle.state.getPosition().y(), turtle.state.getPosition().z());
    glEnd();
    qDebug() << "\t" << turtle.state.getPosition();
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -20.0f);
    QVector3D oldPosition;

    turtle.state.setDirection(QVector3D(0.0, 0.0, 1.0));
    turtle.state.setPosition(QVector3D(0.0, 0.0, 0.0));

    oldPosition = turtle.state.getPosition();
    turtle.forward();
    function(oldPosition);

    turtle.yawLeft();
    //turtle.pitchDown();
    oldPosition = turtle.state.getPosition();
    turtle.forward();
    function(oldPosition);

//    turtle.pitchDown();
//    oldPosition = turtle.state.getPosition();
//    turtle.forward();
//    function(oldPosition);

//    turtle.rollLeft();
//    turtle.pitchDown();
//    oldPosition = turtle.state.getPosition();
//    turtle.forward();
//    function(oldPosition);

//    turtle.yawLeft();
//    turtle.rollLeft();
//    turtle.pitchDown();
//    oldPosition = turtle.state.getPosition();
//    turtle.forward();
//    function(oldPosition);

//    turtle.rollLeft();
//    turtle.yawLeft();
//    oldPosition = turtle.state.getPosition();
//    turtle.forward();
//    function(oldPosition);

//    turtle.rollLeft();
//    oldPosition = turtle.state.getPosition();
//    turtle.forward();
//    function(oldPosition);

    exit(EXIT_FAILURE);
}
