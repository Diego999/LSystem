#include "include/view/view.h"
#include "include/turtle/turtle2D.h"
#include "include/turtle/turtle3D.h"

#include <GL/glu.h>
#include <QDebug>

View::View(const QString& starter, const int deep, bool is3D, QWidget *parent) : GLWidget(60 , parent, "LSystem"), starter(starter), deep(deep), sequenceParser(":/rules")
{
    QVector3D startPosition(0,0,0);
    QVector3D startDirection(0,1,0);
    if(is3D)
        turtle = new Turtle3D(startPosition, startDirection);
    else
        turtle = new Turtle2D(startPosition, startDirection);
}

View::~View()
{
    delete turtle;
}

void View::initializeGL()
{
    GLWidget::initializeGL();
}

void View::resizeGL(int width, int height)
{
    GLWidget::resizeGL(width,height);
}

void View::paintGL()
{
    GLWidget::paintGL();
    glLineWidth(5);

    turtle->reinitialize();

    QString sequence = sequenceParser.substitute(starter, deep);

    qreal r = 150.0/255.0;
    qreal g = 90.0/255.0;
    qreal b = 45.0/255.0;

    for(QString::const_iterator it = sequence.constBegin(); it != sequence.constEnd(); ++it)
    {
        switch(it->toAscii())
        {
        case 'M':
            r = 0;
            g = 1;
            b = 0;
            turtle->endTransform();
            turtle->forward();
            drawLine(r,g,b);
            break;
        case 'S':
            r = 150.0/255.0;
            g = 90.0/255.0;
            b = 45.0/255.0;
            turtle->endTransform();
            turtle->forward();
            drawLine(r,g,b);
            break;
        case '+':
            turtle->yawLeft();
            break;
        case '-':
            turtle->yawRight();
            break;
        case '&':
            turtle->pitchDown();
            break;
        case '^':
            turtle->pitchUp();
            break;
        case '\\':
            turtle->rollLeft();
            break;
        case '/':
            turtle->rollRight();
            break;
        case '|':
            turtle->yawAround();
            break;
        case '[':
            turtle->statePush();
            break;
        case ']':
            turtle->statePop();
            break;
        default:
            break;
        }
    }
}

void View::drawLine(const qreal r, const qreal g, const qreal b) const
{
    QVector3D v1 = turtle->getOldPosition();
    QVector3D v2 = turtle->getPosition();

    glBegin(GL_LINES);
        glColor3f(r,g,b);
        glVertex3f(v1.x(), v1.y(), v1.z());
        glVertex3f(v2.x(), v2.y(), v2.z());
    glEnd();
}
