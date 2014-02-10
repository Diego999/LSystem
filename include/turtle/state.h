#ifndef STATE_H
#define STATE_H

#include <QVector3D>
#include <QMatrix4x4>

class State
{
public:
    State(const QVector3D& position = QVector3D(0.0,0.0,0.0), const QVector3D& direction = QVector3D(1.0,0.0,0.0));

    void forward(qreal stepLength);
    void setDefaultPositionAndDirection();

    void setPosition(const QVector3D& newPosition);
    void setDirection(const QVector3D& newDirection);

    QVector3D getOldPosition() const;
    QVector3D getPosition() const;
    QVector3D getDirection() const;

private:
    QVector3D position;
    QVector3D direction;

    QVector3D defaultPosition;
    QVector3D defaultDirection;

    QVector3D oldPosition;
};

#endif // STATE_H
