#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL>
#include <QGLWidget>

class myGLWidget : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit myGLWidget(int framesPerSecond = 0, QWidget *parent = 0, char *name = 0);
    ~myGLWidget();
    virtual void initializeGL() = 0;
    virtual void resizeGL(int width, int height) = 0;
    virtual void paintGL() = 0;
    virtual void keyPressEvent( QKeyEvent *keyEvent );
    void toggleFullScreen();

public slots:
    virtual void timeOutSlot();

private:
    QTimer *m_Timer;
    bool m_fullScreen;
};

#endif // MYGLWIDGET_H
