#include "menuPrincipale.h"
#include <QVBoxLayout>

menuPrincipale::menuPrincipale(QWidget* p):
    parent(p),
    menu(new QMenu("File", this)),
    salva(new QAction("Salva", menu)),
    esci(new QAction("Esci", menu)),
    caricamento(new QAction("Carica dati", menu)),
    negozio(new QAction("Negozio", p)),
    ricerca(new QAction("Ricerca", p)),
    inserisci(new QAction("Inserisci", p))
{
    //Assemblo il menu
    addMenu(menu);
    menu->addAction(salva);
    menu->addAction(caricamento);
    menu->addAction(esci);
    addAction(negozio);
    addAction(ricerca);
    addAction(inserisci);

    connect(negozio, SIGNAL(triggered()), parent, SLOT(visualizzaNegozio()));
    connect(ricerca, SIGNAL(triggered()), parent, SLOT(visualizzaRicerca()));
    connect(inserisci, SIGNAL(triggered()), parent, SLOT(visualizzaInserisci()));
    connect(caricamento, SIGNAL(triggered()), parent, SLOT(caricaDati()));

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

QAction *menuPrincipale::getNegozio() const{
    return negozio;
}

QAction *menuPrincipale::getRicerca() const{
    return ricerca;
}
