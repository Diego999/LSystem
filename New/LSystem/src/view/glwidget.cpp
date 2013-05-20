#include "include/view/glwidget.h"

#include <QTimer>
#include <QKeyEvent>
#include <GL/glut.h>
#include <QDebug>
#include <cmath>
#include <QMessageBox>

GLWidget::GLWidget(int framesPerSecond, QWidget *parent, const QString& title)
    : QGLWidget(parent), timer(0), fullScreen(false), scale(1), wheel(0), xRot(0), yRot(0), zRot(0), xTrans(0), yTrans(0), zTrans(-6)
{
    setWindowTitle(title);

    if(framesPerSecond > 0)
    {
        int seconde = 1000;
        int timerInterval = seconde / framesPerSecond;

        timer = new QTimer(this);

        connect(timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        timer->start(timerInterval);
    }
}

GLWidget::~GLWidget()
{
    if(timer)
        delete timer;
}

void GLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GLWidget::resizeGL(int width, int height)
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

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xTrans, yTrans, zTrans);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    glScalef(scale, scale, scale);
    glTranslatef(0,-6,-20);
    drawAxis('X');
    drawAxis('Y');
    drawAxis('Z');
}

void GLWidget::drawAxis(char letter)
{
    int r = 0;
    int g = 0;
    int b = 0;

    switch(letter)
    {
    case 'x':
    case 'X':
        r = 1;
        break;
    case 'y':
    case 'Y':
        g = 1;
        break;
    case 'z':
    case 'Z':
        b = 1;
        break;
    }

    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3f(r, g, b);
        glVertex3f(-100*r, -100*g, -100*b);
        glVertex3f(100*r, 100*g, 100*b);
    glEnd();

    glColor3f(r,g,b);
    renderText(1.2*r,1.2*g,1.2*b,QString(letter),QFont("Arial",20,2));

    glBegin(GL_LINES);
        for(double k=0;k<=2.0*M_PI;k+=0.01)
        {
          glColor3f(r,g,b);
          glVertex3f(r,g,b);
          if(r == 1)
            glVertex3f(0.9,0.1*cos(k),0.1*sin(k));
          else if(g == 1)
            glVertex3f(0.1*cos(k),0.9,0.1*sin(k));
          else
            glVertex3f(0.1*cos(k),0.1*sin(k),0.9);
        }
    glEnd();

    glLineWidth(1);
}
void GLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
    case Qt::Key_Escape:
    case Qt::Key_Q:
        close();
        break;
    case Qt::Key_Space:
        toggleFullScreen();
        break;
    case Qt::Key_H:
        QMessageBox::information(this,tr("What you can do"),
                                 tr("Rotate with the mouse (left button rotation X,Y, right X,Z)\nZoom in/out with the wheel of the mouse\nUse the directional keys to move"));
        break;

    case Qt::Key_Up:
        yTrans -= 0.1;
        break;
    case Qt::Key_Down:
        yTrans += 0.1;
        break;
    case Qt::Key_Right:
        xTrans -= 0.1;
        break;
    case Qt::Key_Left:
        xTrans += 0.1;
        break;
    }
}

void GLWidget::wheelEvent(QWheelEvent* event)
{
    wheel += event->delta()/8;
    if(wheel <= -360)
        wheel = -345;
    scale = 1.0 + wheel/360.0;

    updateGL();
}

void GLWidget::timeOutSlot()
{
    updateGL();
}

void GLWidget::toggleFullScreen()
{
    fullScreen ? showNormal() : showFullScreen();
    fullScreen = !fullScreen;
}

void GLWidget::normalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton)
    {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton)
    {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}

void GLWidget::setXRotation(int angle)
{
    normalizeAngle(angle);
    if (angle != xRot)
    {
        xRot = angle;
        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    normalizeAngle(angle);
    if (angle != yRot)
    {
        yRot = angle;
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    normalizeAngle(angle);
    if (angle != zRot)
    {
        zRot = angle;
        updateGL();
    }
}
