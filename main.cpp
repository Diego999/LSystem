#include <QApplication>
#include "include/view/view.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDebug>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    View v("../../res/SierpinskiTriangle.xml");
    v.show();
    return app.exec();
}
