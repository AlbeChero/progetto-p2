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
public:
    Controller(Modello* ,QWidget * = nullptr);
    //~Controller();
    Modello *getModello();
    void caricaDati();
public slots:
    void visualizzaRicerca() const;
    void visualizzaNegozio() const;
    void visualizzaInserisci() const;
    void salvaDatiVideogioco();
    void modificaOggetto();
    void rimuoviOggetto();
    void annullaModVideo();
    void annullaModGT();
    void annullaModGcarte();
    void annullaModColl();
};

#endif // CONTROLLER_H
