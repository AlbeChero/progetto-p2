#include "menuPrincipale.h"
#include <QVBoxLayout>

menuPrincipale::menuPrincipale(QWidget* p):
    parent(p),
    negozio(new QAction("Negozio", p)),
    ricerca(new QAction("Ricerca", p)),
    inserisci(new QAction("Inserisci", p))
{
    //Assemblo il menu
    addAction(negozio);
    addAction(ricerca);
    addAction(inserisci);

    connect(negozio, SIGNAL(triggered()), parent, SLOT(visualizzaNegozio()));
    connect(ricerca, SIGNAL(triggered()), parent, SLOT(visualizzaRicerca()));
    connect(inserisci, SIGNAL(triggered()), parent, SLOT(visualizzaInserisci()));
}


QAction *menuPrincipale::getNegozio() const{
    return negozio;
}

QAction *menuPrincipale::getRicerca() const{
    return ricerca;
}
