#include "include/view/view.h"
#include "include/turtle/turtle.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <QDebug>

View::View(const QString& filePath, QWidget *parent) : GLWidget(60 , parent, "LSystem"),
    sequenceParser(filePath), turtle(sequenceParser.getStepLength(), sequenceParser.getAngle())
{

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

    turtle.reinitialize();

    QString sequence = sequenceParser.substitute(sequenceParser.getAxiom(), sequenceParser.getDeep());
    QStringList forwards = sequenceParser.getForwards();

    for(QString::const_iterator it = sequence.constBegin(); it != sequence.constEnd(); ++it)
    {
        if(forwards.contains(static_cast<QString>(it->toAscii())))
        {
            turtle.forward();
            drawLine(1,1,1);
        }
        else
            switch(it->toAscii())
            {
            case '+':
                turtle.turnLeft();
                break;
            case '-':
                turtle.turnRight();
                break;
            case '%':
                turtle.pitchDown();
                break;
            case '^':
                turtle.pitchUp();
                break;
            case '\\':
                turtle.rollLeft();
                break;
            case '/':
                turtle.rollRight();
                break;
            case '|':
                turtle.turnAround();
                break;
            case '[':
                //turtle.statePush();
                break;
            case ']':
                //turtle.statePop();
                break;
            default:
                break;
            }
    }

}

void View::drawLine(const qreal r, const qreal g, const qreal b) const
{
    QVector3D v1 = turtle.getOldPosition();
    QVector3D v2 = turtle.getPosition();

    glBegin(GL_LINES);
        glColor3f(r,g,b);
        glVertex3f(v1.x(), v1.y(), v1.z());
        glVertex3f(v2.x(), v2.y(), v2.z());
    glEnd();
}
