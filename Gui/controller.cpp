#include <Gui/controller.h>

#include <QList>
#include <QFileDialog>
#include <QMessageBox>
#include <QtGlobal>
#include <QDebug>
#include <iostream>
#include <QtGlobal>
#include <QDebug>
#include <QMessageBox>


Controller::Controller(Modello* m, QWidget *parent) : //Costruttore per la pagina principale
    QWidget(parent),
    scrollA(new ScrollArea),
    layoutPrincipale(new QVBoxLayout(this)),
    mainMenu(new menuPrincipale(this)),
    layoutNeg(new layoutNegozio(this)),
    layoutRic(new layoutRicerca(this)),
    modello(m),
    modiVideo(new modificaVideogioco(this)),
    modGTavolo(new modificaGiocoDaTavolo(this)),
    modColl(new modificaCarteCollezionabili(this)),
    modGCarte(new modificaGiocoDaTavoloConCarte(this)),
    file(QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Salvataggio dati" , "File XML(*.xml)")),
    NegAttivo(true),
    RicAttivo(false)
{
    layoutPrincipale->setMenuBar(mainMenu);
    layoutPrincipale->addWidget(layoutNeg);
    layoutPrincipale->addWidget(layoutRic);
    layoutPrincipale->addWidget(scrollA);
    modiVideo->hide();
    modGTavolo->hide();
    modColl->hide();
    modGCarte->hide();
    layoutRic->hide();
    scrollA->hide();
    setLayout(layoutPrincipale);
    caricaDati();

    //I due bottoni MODIFICA e RIMUOVI
    connect(layoutNeg->getBtnModifica(),SIGNAL(clicked()),this, SLOT(setN()));
    connect(layoutNeg->getBtnRimuovi(),SIGNAL(clicked()),this,SLOT(rimuoviOggetto()));
    //Connect per le modifiche degli oggetti
    connect(modiVideo->getmodEffettuata(), SIGNAL(clicked()), this, SLOT(salvaDatiVideogioco()));
    connect(modGTavolo->getmodEffettuata(), SIGNAL(clicked()), this, SLOT(salvaDatiVideogioco()));
    connect(modGCarte->getmodEffettuata(), SIGNAL(clicked()), this, SLOT(salvaDatiVideogioco()));
    connect(modColl->getmodEffettuata(), SIGNAL(clicked()), this, SLOT(salvaDatiVideogioco()));
    //Connect per annullare le modifiche
    connect(modiVideo->getannullaMod(), SIGNAL(clicked()), this, SLOT(annullaModVideo()));
    connect(modGTavolo->getannullaMod(), SIGNAL(clicked()), this, SLOT(annullaModGT()));
    connect(modGCarte->getannullaMod(), SIGNAL(clicked()), this, SLOT(annullaModGcarte()));
    connect(modColl->getannullaMod(), SIGNAL(clicked()), this, SLOT(annullaModColl()));
    //Connect per la ricerca oggetto
    connect(layoutRic->getBtnRicerca(), SIGNAL(clicked()), this, SLOT(avviaRicerca()));
    connect(layoutRic->getBtnModifica(), SIGNAL(clicked()), this, SLOT(setR()));
    connect(layoutRic->getBtnElimina(),SIGNAL(clicked()),this,SLOT(rimuoviOggetto()));

    connect(this, SIGNAL(mySignal(bool)), this, SLOT(modificaOggetto(bool))); //Passaggio del booleano per capire da quale lista pescare (Negozio oppure Ricerca)
}

void Controller::setN(){
    bool i = true;
    emit modificaOggetto(i);
}

void Controller::setR(){
    bool i = false;
    emit modificaOggetto(i);
}

void Controller::modificaOggetto(bool s){
    modiVideo->pulisciTutto();
    modGCarte->pulisciTutto();
    modGTavolo->pulisciTutto();
    modColl->pulisciTutto();


    ListaDiItemStoreToys* q = nullptr;
    ItemStoreToys* oggettoMod = nullptr;

    if(s == true){
    q = layoutNeg->getLista()->oggettoCorrente();
    oggettoMod = q->prelevaOgg();
    } else if(s == false){
        q = layoutRic->getLista()->oggettoCorrente();
        oggettoMod = q->prelevaOgg();
    }

    if(dynamic_cast<Videogioco*>(oggettoMod)){
        Videogioco* p = static_cast<Videogioco*>(oggettoMod);

        modiVideo->inserisciPercorso(p->getPath());
        modiVideo->getNomeGioco()->insert(QString::fromStdString(p->getNome()));
        modiVideo->getCasaPro()->insert(QString::fromStdString(p->getCasaProduttrice()));
        modiVideo->getEta()->insert(QString::fromStdString(std::to_string(p->getEta())));
        modiVideo->getAnno()->insert(QString::fromStdString(std::to_string(p->getAnnoPubblicazione())));
        modiVideo->getPrezzo()->insert(QString::fromStdString(std::to_string(p->getPrezzo())));
        modiVideo->getPezziMagazzino()->insert(QString::fromStdString(std::to_string(p->getPezziInMagazzino())));
        modiVideo->getGenere()->insert(QString::fromStdString(p->getGenere()));
        modiVideo->getSconto()->insert(QString::fromStdString(std::to_string(p->getSconto())));
        modiVideo->getContenuto()->insert(QString::fromStdString(p->getContenuto()));
        p->getUsato() ? modiVideo->getUsato()->setCurrentIndex(0) : modiVideo->getUsato()->setCurrentIndex(1);
        p->getPs4() ? modiVideo->getplayStation()->setCurrentIndex(0) : modiVideo->getplayStation()->setCurrentIndex(1);
        p->getXboxOne() ? modiVideo->getxbox()->setCurrentIndex(0) : modiVideo->getxbox()->setCurrentIndex(1);
        modiVideo->show();

    } else if(dynamic_cast<GiocoDaTavolo*>(oggettoMod)){
        GiocoDaTavolo* p = static_cast<GiocoDaTavolo*>(oggettoMod);
        modGTavolo->getModImm()->setIcon(QIcon(QString::fromStdString(p->getPath())));
        modGTavolo->getNomeGioco()->insert(QString::fromStdString(p->getNome()));
        modGTavolo->getCasaPro()->insert(QString::fromStdString(p->getCasaProduttrice()));
        modGTavolo->getEta()->insert(QString::fromStdString(std::to_string(p->getEta())));
        modGTavolo->getAnno()->insert(QString::fromStdString(std::to_string(p->getAnnoPubblicazione())));
        modGTavolo->getPrezzo()->insert(QString::fromStdString(std::to_string(p->getPrezzo())));
        modGTavolo->getPezziMagazzino()->insert(QString::fromStdString(std::to_string(p->getPezziInMagazzino())));
        p->getUsato() ? modGTavolo->getUsato()->setCurrentIndex(0) : modGTavolo->getUsato()->setCurrentIndex(1);
        modGTavolo->getNumGiocatori()->insert(QString::fromStdString(std::to_string(p->getNumGiocatori())));
        modGTavolo->getTipologia()->insert(QString::fromStdString(p->getTipologia()));
        modGTavolo->getRegolamento()->insert(QString::fromStdString(p->getRegolamento()));
        modGTavolo->getContenuto1()->insert(QString::fromStdString(p->getContenuto()));
        modGTavolo->getSconto1()->insert(QString::fromStdString(std::to_string(p->getSconto())));
        modGTavolo->show();

    } else if(dynamic_cast<GiocoDaTavoloConCarte*>(oggettoMod)){
        GiocoDaTavoloConCarte* p = static_cast<GiocoDaTavoloConCarte*>(oggettoMod);

        modGCarte->getModImm()->setIcon(QIcon(QString::fromStdString(p->getPath())));
        modGCarte->getNomeGioco()->insert(QString::fromStdString(p->getNome()));
        modGCarte->getCasaPro()->insert(QString::fromStdString(p->getCasaProduttrice()));
        modGCarte->getEta()->insert(QString::fromStdString(std::to_string(p->getEta())));
        modGCarte->getAnno()->insert(QString::fromStdString(std::to_string(p->getAnnoPubblicazione())));
        modGCarte->getPezziMagazzino()->insert(QString::fromStdString(std::to_string(p->getPezziInMagazzino())));
        modGCarte->getPrezzo()->insert(QString::fromStdString(std::to_string(p->getPrezzo())));
        p->getUsato() ? modGCarte->getUsato()->setCurrentIndex(0) : modGCarte->getUsato()->setCurrentIndex(1);
        p->getEdizioneLimitata() ? modGCarte->getEdLimitata()->setCurrentIndex(0) : modGCarte->getEdLimitata()->setCurrentIndex(1);
        modGCarte->getRegolamentoGTC()->insert(QString::fromStdString(p->getRegolamento()));
        modGCarte->getNumGiocatoriGTC()->insert(QString::fromStdString(std::to_string(p->getNumGiocatori())));
        modGCarte->getContenutoGTC()->insert(QString::fromStdString(p->getContenuto()));
        modGCarte->getScontoGTC()->insert(QString::fromStdString(std::to_string(p->getSconto())));
        modGCarte->show();

    } else if(dynamic_cast<CarteCollezionabili*>(oggettoMod)){
        CarteCollezionabili* p = static_cast<CarteCollezionabili*>(oggettoMod);
        modColl->getModImm()->setIcon(QIcon(QString::fromStdString(p->getPath())));
        modColl->getNomeGioco()->insert(QString::fromStdString(p->getNome()));
        modColl->getCasaPro()->insert(QString::fromStdString(p->getCasaProduttrice()));
        modColl->getEta()->insert(QString::fromStdString(std::to_string(p->getEta())));
        modColl->getAnno()->insert(QString::fromStdString(std::to_string(p->getAnnoPubblicazione())));
        modColl->getPezziMagazzino()->insert(QString::fromStdString(std::to_string(p->getPezziInMagazzino())));
        modColl->getPrezzo()->insert(QString::fromStdString(std::to_string(p->getPrezzo())));
        p->getUsato() ? modColl->getUsato()->setCurrentIndex(0) : modColl->getUsato()->setCurrentIndex(1);
        modColl->getScontoCC()->insert(QString::fromStdString(std::to_string(p->getSconto())));
        modColl->getNumCarteCC()->insert(QString::fromStdString(std::to_string(p->getNumCarte())));
        modColl->getEdizione()->insert(QString::fromStdString(p->getEdizione()));
        p->getEdizioneLimitata() ? modColl->getEdLimitata()->setCurrentIndex(0) : modColl->getEdLimitata()->setCurrentIndex(1);
        modColl->show();
    }
}

void Controller::salvaDatiVideogioco(){

    ListaDiItemStoreToys* q = nullptr;
    ItemStoreToys* oggettoMod = nullptr;

    if(NegAttivo == true && RicAttivo == false){
         q = layoutNeg->getLista()->oggettoCorrente();
         oggettoMod = q->prelevaOgg(); }
    else if(NegAttivo == false && RicAttivo == true){
        q = layoutRic ->getLista()->oggettoCorrente();
        oggettoMod = q->prelevaOgg();
    }

    if(dynamic_cast<Videogioco*>(oggettoMod)){
        Videogioco* p = static_cast<Videogioco*>(oggettoMod);
        p->setNome(modiVideo->getNomeGioco()->text().toStdString());
        p->setCasaProduzione(modiVideo->getCasaPro()->text().toStdString());
        p->setAnnoPubblicazione(modiVideo->getAnno()->text().toUInt());
        p->setEta(modiVideo->getEta()->text().toUInt());
        p->setPrezzo(modiVideo->getPrezzo()->text().toDouble());
        p->setPezziMagazzino(modiVideo->getPezziMagazzino()->text().toUInt());
        p->setUsato(modiVideo->getUsato()->currentIndex());
        p->setPath(modiVideo->getPath().toStdString());
        p->setPs4(modiVideo->getplayStation()->currentIndex());
        p->setXboX(modiVideo->getxbox()->currentIndex());
        p->setGenere(modiVideo->getGenere()->text().toStdString());

        modiVideo->pulisciTutto();
        modello->salvataggio();
        caricaDati();
        modiVideo->close();
    }else if(dynamic_cast<GiocoDaTavolo*>(oggettoMod)){
        GiocoDaTavolo* p = static_cast<GiocoDaTavolo*>(oggettoMod);
        p->setNome(modGTavolo->getNomeGioco()->text().toStdString());
        p->setCasaProduzione(modGTavolo->getCasaPro()->text().toStdString());
        p->setAnnoPubblicazione(modGTavolo->getAnno()->text().toUInt());
        p->setEta(modGTavolo->getEta()->text().toUInt());
        p->setPrezzo(modGTavolo->getPrezzo()->text().toDouble());
        p->setPezziMagazzino(modGTavolo->getPezziMagazzino()->text().toUInt());
        p->setUsato(modGTavolo->getUsato()->currentIndex());
        p->setNumGiocatori(modGTavolo->getNumGiocatori()->text().toUInt());
        p->setTipologia(modGTavolo->getTipologia()->text().toStdString());
        p->setRegolamento(modGTavolo->getTipologia()->text().toStdString());
        p->setContenuto(modGTavolo->getContenuto1()->text().toStdString());
        //MANCO LO SCONTO

        modGTavolo->pulisciTutto();
        modello->salvataggio();
        caricaDati();
        modGTavolo->close();
    } else if(dynamic_cast<GiocoDaTavoloConCarte*>(oggettoMod)){
        GiocoDaTavoloConCarte* p = static_cast<GiocoDaTavoloConCarte*>(oggettoMod);
        p->setNome(modGCarte->getNomeGioco()->text().toStdString());
        p->setCasaProduzione(modGCarte->getCasaPro()->text().toStdString());
        p->setAnnoPubblicazione(modGCarte->getAnno()->text().toUInt());
        p->setEta(modGCarte->getEta()->text().toUInt());
        p->setPrezzo(modGCarte->getPrezzo()->text().toDouble());
        p->setPezziMagazzino(modGCarte->getPezziMagazzino()->text().toUInt());
        p->setUsato(modGCarte->getUsato()->currentIndex());
        p->setNumGicoatori(modGCarte->getNumGiocatoriGTC()->text().toUInt());
        p->setEdizioneLimitata(modGCarte->getEdLimitata()->currentIndex());
        p->setNumGicoatori(modGCarte->getNumGiocatoriGTC()->text().toUInt());
        p->setContenuto(modGCarte->getContenutoGTC()->text().toStdString());

        modGCarte->pulisciTutto();
        modello->salvataggio();
        caricaDati();
        modGCarte->close();
    } else if(dynamic_cast<CarteCollezionabili*>(oggettoMod)){
        CarteCollezionabili* p = static_cast<CarteCollezionabili*>(oggettoMod);
        p->setNome(modColl->getNomeGioco()->text().toStdString());
        p->setCasaProduzione(modColl->getCasaPro()->text().toStdString());
        p->setAnnoPubblicazione(modColl->getAnno()->text().toUInt());
        p->setEta(modColl->getEta()->text().toUInt());
        p->setPrezzo(modColl->getPrezzo()->text().toDouble());
        p->setPezziMagazzino(modColl->getPezziMagazzino()->text().toUInt());
        p->setUsato(modColl->getUsato()->currentIndex());
        p->setNumCarte(modColl->getNumCarteCC()->text().toInt());
        p->setEdizione(modColl->getEdizione()->text().toStdString());
        p->setEdizioneLimitata(modColl->getEdLimitata()->currentIndex());

        modColl->pulisciTutto();
        modello->salvataggio();
        caricaDati();
        modColl->close();
    }

}

void Controller::avviaRicerca(){

       layoutRic->getLista()->clear();
       int indice = layoutRic->getTipoGioco()->currentIndex();

       std::string Nome = layoutRic->getCercaNome()->text().toStdString();
       std::string CasaProduttrice = layoutRic->getCercaCasaProduttrice()->text().toStdString();
       unsigned int Eta = layoutRic->getCercaEta()->text().toUInt();
       unsigned int AnnoP = layoutRic->getCercaAnnoPubblicazione()->text().toUInt();

       if(Nome == "" || CasaProduttrice == "" || Eta == 0 || AnnoP == 0){
           QMessageBox::warning(this, "Attenzione", "Tutti i campi della ricerca devono essere compilati");
           return;
       }

       ItemStoreToys* ogg = nullptr;

       switch(indice){

           case(0):{
                QMessageBox::warning(this, "Attenzione", "Selezionare il tipo di oggetto che si desidera cercare!");
                break;
       }
           case(1):{
                 ogg = new Videogioco(Nome, CasaProduttrice, AnnoP, Eta);
           break;
       }
           case(2):{
                ogg = new GiocoDaTavolo(Nome, CasaProduttrice, Eta, AnnoP);
           break;
       }
           case(3):{
                 ogg = new GiocoDaTavoloConCarte(Nome, CasaProduttrice, AnnoP, Eta);
           break;
       }
           case(4):{
                 ogg = new CarteCollezionabili(Nome, CasaProduttrice, AnnoP, Eta);
           break;
       }
   }
       //ItemStoreToys* PorcaPuttana = nullptr;
       //PorcaPuttana = modello->getLista()->Ricerca(ogg);

     if(indice != 0){

       if(modello->getLista()->Ricerca(ogg)){

           modello->setNuovoPercorso(file.toStdString());
           modello->caricamento();
           bool sent = false;

           Container<ItemStoreToys*>::constiterator aux = modello->cbegin();
           Container<ItemStoreToys*>::constiterator auxEnd = modello->cend();

           for(; aux!=auxEnd && !sent; ++aux){
               if(*ogg == *(*aux)){
                   layoutRic->getLista()->aggiungiGioco(*aux);
                   sent = true;
               }
           }

           visualizzaRicerca();
       }
       else{
         QMessageBox::warning(this, "Risultato ricerca:", "Nessun oggetto trovato!");
       }
     }

}



void Controller::rimuoviOggetto(){

    ListaDiItemStoreToys* q = nullptr;
    ItemStoreToys* oggetto = nullptr;

    if(NegAttivo && !RicAttivo){
    q = layoutNeg->getLista()->oggettoCorrente();
    oggetto = q->prelevaOgg(); }
    else if(!NegAttivo && RicAttivo){
        q = layoutRic->getLista()->oggettoCorrente();
        oggetto = q->prelevaOgg();
    }

    modello->rimozione(oggetto);
    modello->salvataggio();
    modello->caricamento();
    caricaDati();
    QMessageBox::warning(this, "Esito positivo!", "L'oggetto è stato rimosso dal catalogo!");
}

void Controller::annullaModVideo(){
    modiVideo->pulisciTutto();
    modiVideo->close();
}

void Controller::annullaModGT(){
    modGTavolo->pulisciTutto();
    modGTavolo->close();
}

void Controller::annullaModGcarte(){
    modGCarte->pulisciTutto();
    modGCarte->close();
}

void Controller::annullaModColl(){
    modColl->pulisciTutto();
    modColl->close();
}

Modello* Controller::getModello() {
    return modello;
}

//Controller::~Controller(){}

void Controller::visualizzaRicerca(){
    layoutNeg->hide();
    layoutRic->show();
    scrollA->hide();

    RicAttivo = true;
    NegAttivo = false;

    scrollA->pulisciTutto();
    scrollA->pulisciCheck();
    layoutRic->pulisciTutto();
    layoutNeg->pulisciTutto();
}

void Controller::visualizzaNegozio(){
    layoutNeg->show();
    layoutRic->hide();
    scrollA->hide();

    RicAttivo = false;
    NegAttivo = true;

    layoutRic->getLista()->clear();

    scrollA->pulisciTutto();
    scrollA->pulisciCheck();
    layoutRic->pulisciTutto();
    layoutNeg->pulisciTutto();
}

void Controller::visualizzaInserisci(){
    layoutNeg->hide();
    layoutRic->hide();
    scrollA->show();

    RicAttivo = false;
    NegAttivo = false;

    layoutRic->getLista()->clear();

    scrollA->pulisciTutto();
    scrollA->pulisciCheck();
    layoutRic->pulisciTutto();
    layoutNeg->pulisciTutto();
}

void Controller::caricaDati(){

    if(file!=""){
        layoutNeg->getLista()->clear();
        modello->setNuovoPercorso(file.toStdString());
        modello->caricamento();

        Container<ItemStoreToys*>::constiterator aux = modello->cbegin();
        Container<ItemStoreToys*>::constiterator auxEnd = modello->cend();

        for(; aux != auxEnd; ++aux){
          layoutNeg->getLista()->aggiungiGioco(*aux);
        }

        modello->setDatiSalvati(true);
        visualizzaNegozio();
    }
}
