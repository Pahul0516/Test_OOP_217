#include <QtWidgets/QApplication>
#include <qdebug.h>
#include <teste.h>
#include "GUI.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    gui g;
    g.show();
    rulare_teste();
  

    return a.exec();
}
