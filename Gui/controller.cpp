#include <Gui/controller.h>
#include <iostream>
#include <QList>
#include <QFileDialog>
#include <QMessageBox>

Controller::Controller(Modello* m, QWidget *parent) : //Costruttore per la pagina principale
    QWidget(parent),
    scrollA(new ScrollArea),
    layoutPrincipale(new QVBoxLayout(this)),
    mainMenu(new menuPrincipale(this)),
    layoutNeg(new layoutNegozio(this)),
    layoutRic(new layoutRicerca(this)),
    modello(m)
{
    layoutPrincipale->setMenuBar(mainMenu);
    layoutPrincipale->addWidget(layoutNeg);
    layoutPrincipale->addWidget(layoutRic);
    layoutPrincipale->addWidget(scrollA);
    layoutRic->hide();
    scrollA->hide();
    setLayout(layoutPrincipale);

    connect(layoutNeg->getBtnModifica(),SIGNAL(clicked()),this,SLOT(modificaOggetto()));
}

void Controller::modificaOggetto(){
    ListaDiItemStoreToys* q = layoutNeg->getLista()->oggettoCorrente();
    ItemStoreToys* oggettoMod = q->prelevaOgg();
    if(dynamic_cast<Videogioco*>(oggettoMod)){
        Videogioco* p = static_cast<Videogioco*>(oggettoMod);
        modificaVideogioco* dialog = new modificaVideogioco(this, p);
        dialog->show();
    } else if(dynamic_cast<GiocoDaTavolo*>(oggettoMod)){
        GiocoDaTavolo* p = static_cast<GiocoDaTavolo*>(oggettoMod);
        modificaGiocoDaTavolo* dialog = new modificaGiocoDaTavolo(this, p);
        dialog->show();
    } else if(dynamic_cast<GiocoDaTavoloConCarte*>(oggettoMod)){
        GiocoDaTavoloConCarte* p = static_cast<GiocoDaTavoloConCarte*>(oggettoMod);
        modificaGiocoDaTavoloConCarte* dialog = new modificaGiocoDaTavoloConCarte(this, p);
        dialog->show();
    } else if(dynamic_cast<CarteCollezionabili*>(oggettoMod)){
        CarteCollezionabili* p = static_cast<CarteCollezionabili*>(oggettoMod);
        modificaCarteCollezionabili* dialog = new modificaCarteCollezionabili(this, p);
        dialog->show();
    }
}

Modello* Controller::getModello() {
    return modello;
}

Controller::~Controller(){}

void Controller::visualizzaRicerca() const{
    layoutNeg->hide();
    layoutRic->show();
    scrollA->hide();

    scrollA->pulisciTutto();
    scrollA->pulisciCheck();
    layoutRic->pulisciTutto();
    layoutNeg->pulisciTutto();
}

void Controller::visualizzaNegozio() const{
    layoutNeg->show();
    layoutRic->hide();
    scrollA->hide();

    scrollA->pulisciTutto();
    scrollA->pulisciCheck();
    layoutRic->pulisciTutto();
    layoutNeg->pulisciTutto();
}

void Controller::visualizzaInserisci() const{
    layoutNeg->hide();
    layoutRic->hide();
    scrollA->show();

    scrollA->pulisciTutto();
    scrollA->pulisciCheck();
    layoutRic->pulisciTutto();
    layoutNeg->pulisciTutto();
}

void Controller::caricaDati(){
    QString file = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Salvataggio Dati" , "File XML(*.xml)");

    if(file!=""){
        layoutNeg->getLista()->clear();
        modello->setNuovoPercorso(file.toStdString());
        modello->caricamento();

        Container<ItemStoreToys*>::iterator aux = modello->begin();
        Container<ItemStoreToys*>::iterator auxEnd = modello->end();

        for(; aux != auxEnd; ++aux){
          layoutNeg->getLista()->aggiungiGioco(*aux);
        }

        modello->setDatiSalvati(true);
        visualizzaNegozio();
    }
}
