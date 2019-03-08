#include "menuPrincipale.h"

menuPrincipale::menuPrincipale(QWidget* p):
    parent(p),
    barraMenu(new QMenuBar()),
    menu(new QMenu("File", barraMenu)),
    salva(new QAction("Salva", menu)),
    esci(new QAction("Esci", menu)),
    negozio(new QMenu("Negozio", menu)),
    ricerca(new QMenu("Ricerca", menu))
{
    //Assemblo il menu
    barraMenu->addMenu(menu);
    menu->addAction(salva);
    menu->addAction(esci);
    barraMenu->addMenu(negozio);
    barraMenu->addMenu(ricerca);

}

QMenuBar *menuPrincipale::getBarraMenu() const{
    return barraMenu;
}

QMenu *menuPrincipale::getMenu() const{
    return menu;
}

QAction *menuPrincipale::getSalva() const{
    return salva;
}

QAction *menuPrincipale::getEsci() const{
    return esci;
}

QMenu *menuPrincipale::getNegozio() const{
    return negozio;
}

QMenu *menuPrincipale::getRicerca() const{
    return ricerca;
}
