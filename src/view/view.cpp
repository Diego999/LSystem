#include "include/view/view.h"
#include "include/turtle/turtle.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <QDebug>

View::View(const QString& filePath, QWidget *parent) : GLWidget(60 , parent, "LSystem"), starter(starter), deep(deep), sequenceParser(filePath)
{
    QVector3D startPosition(0,0,0);
    QVector3D startDirection(0,1,0);
    turtle = new Turtle(startPosition, startDirection, sequenceParser.getStepLength(), sequenceParser.getAngle());
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

    QString sequence = sequenceParser.substitute(sequenceParser.getAxiom(), sequenceParser.getDeep());

    for(QString::const_iterator it = sequence.constBegin(); it != sequence.constEnd(); ++it)
    {
        switch(it->toAscii())
        {
        case 'A':
        case 'B':
            turtle->endTransform();
            turtle->forward();
            drawLine(1,1,1);
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
