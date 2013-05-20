#include <QApplication>
#include "include/view/view.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    View v("M",4);
    v.show();
    return app.exec();
}
