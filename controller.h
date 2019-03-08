#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "menuPrincipale.h"
#include "negozio.h"
#include "modello.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class controller : public QWidget{
    Q_OBJECT
private:
    menuPrincipale* menuPrincipale;
    QVBoxLayout *layoutPrincipale;
public:
    controller(Modello*,QWidget * = nullptr);
    ~controller();
};

#endif // CONTROLLER_H
