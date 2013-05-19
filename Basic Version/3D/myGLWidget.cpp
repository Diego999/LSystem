#include "myGLWidget.h"

myGLWidget::myGLWidget(int framesPerSecond, QWidget *parent, char *name)
    : QGLWidget(parent)
{
    setWindowTitle(QString::fromUtf8(name));
    m_fullScreen = false;
    if(framesPerSecond == 0)
        m_Timer = NULL;
    else
    {
        int seconde = 1000; // 1 seconde = 1000 ms
        int timerInterval = seconde / framesPerSecond;
        m_Timer = new QTimer(this);
        connect(m_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        m_Timer->start( timerInterval );
    }
}

myGLWidget::~myGLWidget()
{
    if(m_Timer) delete m_Timer;
}

void myGLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_Space:
        toggleFullScreen();
        break;
    }
}

void myGLWidget::timeOutSlot()
{
    updateGL();
}

void myGLWidget::toggleFullScreen()
{
    m_fullScreen ? showNormal() : showFullScreen();
    m_fullScreen = !m_fullScreen;
}
