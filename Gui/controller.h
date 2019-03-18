#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Gui/menuPrincipale.h"
#include "Gui/negozio.h"
#include "Gui/ricerca.h"
#include "Gui/inserisci.h"
#include "Gui/modificaVideogioco.h"
#include "Gui/modificagiocodatavolo.h"
#include "Gui/modificagiocodatavoloconcarte.h"
#include "Gui/modificacartecollezionabili.h"
#include "modello.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qmenubar.h>
#include <qwidget.h>
#include <Gui/scrollarea.h>
#include "modificaVideogioco.h"
#include "modificacartecollezionabili.h"
#include "modificagiocodatavolo.h"
#include "modificagiocodatavoloconcarte.h"

class Controller : public QWidget{
    Q_OBJECT
private:
    ScrollArea *scrollA;
    QVBoxLayout *layoutPrincipale;
    menuPrincipale *mainMenu;
    layoutNegozio *layoutNeg;
    layoutRicerca *layoutRic;
    layoutInserisci *layoutIns;
    Modello* modello;
    modificaVideogioco* modiVideo;
    modificaGiocoDaTavolo* modGTavolo;
    modificaCarteCollezionabili* modColl;
    modificaGiocoDaTavoloConCarte* modGCarte;
    QString file;
    bool NegAttivo;
    bool RicAttivo;
public:
    Controller(Modello* ,QWidget * = nullptr);
    //~Controller();
    Modello *getModello();
    void caricaDati();
public slots:
    void visualizzaRicerca();
    void visualizzaNegozio();
    void visualizzaInserisci();
    void salvaDatiVideogioco();
    void modificaOggetto(bool);
    void rimuoviOggetto();
    void inserisciNuovo();
    void annullaModVideo();
    void annullaModGT();
    void annullaModGcarte();
    void annullaModColl();
    void avviaRicerca();
    void setN();
    void setR();
signals:
    void mySignal(bool);
};

#endif // CONTROLLER_H
