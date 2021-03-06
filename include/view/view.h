#ifndef VIEW_H
#define VIEW_H

#include "glwidget.h"
#include "include/parser/sequenceparser.h"

#include <QVector3D>
#include <QPoint>

class Turtle;

class View : public GLWidget
{
    Q_OBJECT

public:
    View(const QString& filePath, QWidget *parent = 0);
    ~View();

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    void drawLine(const qreal r = 1.0, const qreal g = 1.0, const qreal b = 1.0) const;

    Turtle* turtle;
    SequenceParser sequenceParser;
};

#endif // VIEW_H
