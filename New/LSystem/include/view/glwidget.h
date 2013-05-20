#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QString>

class QTimer;

class GLWidget : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit GLWidget(int framesPerSecond = 0, QWidget *parent = 0, const QString& title = QString(tr("LSystem")));
    virtual ~GLWidget();
    void toggleFullScreen();

public slots:
    virtual void timeOutSlot();

protected:
    virtual void initializeGL() = 0;
    virtual void resizeGL(int width, int height) = 0;
    virtual void paintGL() = 0;
    virtual void keyPressEvent(QKeyEvent* keyEvent);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent *);

private:
    static void normalizeAngle(int& angle);

    void drawAxis(char letter);

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

    QTimer* timer;
    QPoint lastPos;

    bool fullScreen;
    qreal scale;
    qreal wheel;
    int xRot;
    int yRot;
    int zRot;
    qreal xTrans;
    qreal yTrans;
    qreal zTrans;
};

#endif // GLWIDGET_H
