#include "Gui/menuPrincipale.h"
#include <QApplication>
#include "Gui/controller.h"
#include "modello.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Controller w(new Modello());
    //w.setFixedSize(600,400);
    //w.setFixedHeight(400);
    w.show();

    return a.exec();
}
