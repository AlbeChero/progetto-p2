#include "inserisci.h"

layoutInserisci::layoutInserisci(QWidget* p):
    parent(p),
    //Campi della classe astratta
    NomeGioco(new QLineEdit(this)),
    CasaPro(new QLineEdit(this)),
    Eta(new QLineEdit(this)),
    Anno(new QLineEdit(this)),
    Prezzo(new QLineEdit(this)),
    PezziMagazzino(new QLineEdit(this)),
    Usato(new QComboBox(this)),

    //Campi della classe Videogioco
    playStation(new QComboBox(this)),
    xbox(new QComboBox(this)),
    Genere(new QLineEdit(this)),
    Sconto(new QLineEdit(this)),
    Contenuto(new QLineEdit(this)),

    //Campi della classe Gioco da tavolo
    NumGiocatori(new QLineEdit(this)),
    Tipologia(new QLineEdit(this)),
    Regolamento(new QLineEdit(this)),
    Contenuto1(new QLineEdit(this)),
    Sconto1(new QLineEdit(this)),

    //Campo seconda base astratta
    edLimitata(new QComboBox(this)),

    //Campi della classe Gioco da tavolo di carte
    RegolamentoGTC(new QLineEdit(this)),
    NumGiocatoriGTC(new QLineEdit(this)),
    ContenutoGTC(new QLineEdit(this)),
    ScontoGTC(new QLineEdit(this)),

    //Campi della classe Carte Collezionabili
    NumCarteCC(new QLineEdit(this)),
    Edizione(new QLineEdit(this)),
    ScontoCC(new QLineEdit(this)),

    checkVideogioco(new QCheckBox("Videogioco", this)),
    checkGiocoTavolo(new QCheckBox("Gioco da Tavolo", this)),
    checkGiocoCarte(new QCheckBox("Gioco di Carte", this)),
    checkCarteCol(new QCheckBox("Carte Collezionabili", this)),

    formAstratta(new QFormLayout),
    formVideo(new QFormLayout),
    formGiocoTavolo(new QFormLayout),
    formGTC(new QFormLayout),
    formCC(new QFormLayout),

    bottoneInserisci(new QPushButton("INSERISCI")),
    btnInserisciImm(new QPushButton("Inserisci immagine"))
{

    QVBoxLayout *layoutPrincipaleRicerca = new QVBoxLayout(this);
    QHBoxLayout *layoutCheckOgg = new QHBoxLayout;
    QHBoxLayout *layoutImmagine = new QHBoxLayout;

    layoutImmagine->addWidget(btnInserisciImm);

    //Inserisco i checkbox per gli oggetti
    layoutCheckOgg->addWidget(checkVideogioco);
    layoutCheckOgg->addWidget(checkGiocoTavolo);
    layoutCheckOgg->addWidget(checkGiocoCarte);
    layoutCheckOgg->addWidget(checkCarteCol);

    //Setto a false i campi della base astratta
    NomeGioco->setEnabled(false);
    CasaPro->setEnabled(false);
    Eta->setEnabled(false);
    Anno->setEnabled(false);
    Prezzo->setEnabled(false);
    PezziMagazzino->setEnabled(false);
    Usato->setEnabled(false);
    //Setto a false i campi della classe videogioco
    playStation->setEnabled(false);
    xbox->setEnabled(false);
    Genere->setEnabled(false);
    Sconto->setEnabled(false);
    Contenuto->setEnabled(false);
    //Setto a false i campi della classe Gioco da tavolo
    NumGiocatori->setEnabled(false);
    Tipologia->setEnabled(false);
    Regolamento->setEnabled(false);
    Contenuto1->setEnabled(false);
    Sconto1->setEnabled(false);
    //Setto a false il campo della seconda base astratta
    edLimitata->setEnabled(false);
    //Setto a false i campi della classe Gioco da tavolo con carte
    RegolamentoGTC->setEnabled(false);
    NumGiocatoriGTC->setEnabled(false);
    ContenutoGTC->setEnabled(false);
    ScontoGTC->setEnabled(false);
    //Setto a false i campi della classe Carte collezionabili
    NumCarteCC->setEnabled(false);
    Edizione->setEnabled(false);
    ScontoCC->setEnabled(false);

    bottoneInserisci->setEnabled(false);
    btnInserisciImm->setEnabled(false);

    //Form campi base astratta
    formAstratta->addRow("Nome gioco", NomeGioco);
    formAstratta->addRow("Casa Produzione", CasaPro);
    formAstratta->addRow("Pegi", Eta);
    formAstratta->addRow("Anno", Anno);
    formAstratta->addRow("Prezzo", Prezzo);
    formAstratta->addRow("Pezzi in magazzino", PezziMagazzino);
    formAstratta->addRow("Usato", Usato);

    //Form videogiochi
    formVideo->addRow("Disponibile per PS4", playStation);
    formVideo->addRow("Disponibile per XboxOne", xbox);
    formVideo->addRow("Genere", Genere);
    formVideo->addRow("Sconto", Sconto);
    formVideo->addRow("Contenuto", Contenuto);

    //Form giochi da tavolo
    formGiocoTavolo->addRow("NumGiocatori", NumGiocatori);
    formGiocoTavolo->addRow("Tipologia", Tipologia);
    formGiocoTavolo->addRow("Regolamento", Regolamento);
    formGiocoTavolo->addRow("Contenuto1", Contenuto1);
    formGiocoTavolo->addRow("Sconto1", Sconto1);

    //Form Giochi da tavolo con carte
    formGTC->addRow("Edizione limitata", edLimitata);
    formGTC->addRow("Regolamento", RegolamentoGTC);
    formGTC->addRow("Numero di giocatori", NumGiocatoriGTC);
    formGTC->addRow("Contenuto", ContenutoGTC);
    formGTC->addRow("Sconto", ScontoGTC);

    //Form giochi di carte collezionabili
    formCC->addRow("Numero di carte", NumCarteCC);
    formCC->addRow("Edizione", Edizione);
    formCC->addRow("Sconto", ScontoCC);

    //Compilo tutte le check box
    Usato->addItem("No"); Usato->addItem("Si");
    playStation->addItem("No"); playStation->addItem("Si");
    xbox->addItem("No"); xbox->addItem("Si");
    edLimitata->addItem("No"); edLimitata->addItem("Si");

    btnInserisciImm->setIconSize(QSize(180,180));
    btnInserisciImm->setFixedSize(QSize(380,200));

    layoutPrincipaleRicerca->addLayout(layoutCheckOgg);
    layoutPrincipaleRicerca->addLayout(layoutImmagine);
    layoutPrincipaleRicerca->addLayout(formAstratta);
    layoutPrincipaleRicerca->addLayout(formVideo);
    layoutPrincipaleRicerca->addLayout(formGiocoTavolo);
    layoutPrincipaleRicerca->addLayout(formGTC);
    layoutPrincipaleRicerca->addLayout(formCC);
    layoutPrincipaleRicerca->addWidget(bottoneInserisci);

    setLayout(layoutPrincipaleRicerca);

    connect(checkVideogioco, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloVideogioco()));
    connect(checkGiocoTavolo, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloGiocoDaTavolo()));
    connect(checkGiocoCarte, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloCarte()));
    connect(checkCarteCol, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloCarteCol()));

    connect(checkVideogioco, SIGNAL(clicked(bool)), this , SLOT(inserisciVideogioco()));
    connect(checkGiocoTavolo, SIGNAL(clicked(bool)), this , SLOT(inserisciGiocoDaTavolo()));
    connect(checkGiocoCarte, SIGNAL(clicked(bool)), this , SLOT(inserisciGiocoDiCarte()));
    connect(checkCarteCol, SIGNAL(clicked(bool)), this , SLOT(inserisciCarteColl()));

    connect(btnInserisciImm, SIGNAL(clicked()), this, SLOT(inserisciImmagine()));

}

void layoutInserisci::inserisciImmagine(){
    pathImm = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Salvataggio Dati" , "File XML(*.JPG)");
    btnInserisciImm->setIcon(QIcon(pathImm));
}
QString layoutInserisci::getPathImm() const{
    return pathImm;
}
QPushButton* layoutInserisci::getBottoneIns() const{
    return bottoneInserisci;
}
QLineEdit* layoutInserisci::getNomeGioco() const{
    return NomeGioco;
}
QLineEdit* layoutInserisci::getCasaPro() const{
    return CasaPro;
}
QLineEdit* layoutInserisci::getEta() const{
    return Eta;
}
QLineEdit* layoutInserisci::getAnno() const{
    return Anno;
}
QLineEdit* layoutInserisci::getPrezzo() const{
    return Prezzo;
}
QLineEdit* layoutInserisci::getPezziMagazzino() const{
    return PezziMagazzino;
}
QComboBox* layoutInserisci::getUsato() const{
    return Usato;
}
QComboBox* layoutInserisci::layoutInserisci::getplayStation() const{
    return playStation;
}
QComboBox* layoutInserisci::layoutInserisci::getxbox() const{
    return xbox;
}
QLineEdit* layoutInserisci::layoutInserisci::getGenere() const{
    return Genere;
}
QLineEdit* layoutInserisci::layoutInserisci::getSconto() const{
    return Sconto;
}
QLineEdit* layoutInserisci::layoutInserisci::getContenuto() const{
    return Contenuto;
}
QLineEdit* layoutInserisci::getNumGiocatori() const{
    return NumGiocatori;
}
QLineEdit* layoutInserisci::getTipologia() const{
    return Tipologia;
}
QLineEdit* layoutInserisci::getRegolamento() const{
    return Regolamento;
}
QLineEdit* layoutInserisci::getContenuto1() const{
    return  Contenuto1;
}
QLineEdit* layoutInserisci::getSconto1() const{
    return Sconto1;
}
QComboBox* layoutInserisci::getedLimitata() const{
    return edLimitata;
}
QLineEdit* layoutInserisci::getRegolamentoGTC() const{
    return RegolamentoGTC;
}
QLineEdit* layoutInserisci::getNumGiocatoriGTC() const{
    return NumGiocatoriGTC;
}
QLineEdit* layoutInserisci::getContenutoGTC() const{
    return ContenutoGTC;
}
QLineEdit* layoutInserisci::getScontoGTC() const{
    return ScontoGTC;
}
QLineEdit* layoutInserisci::getNumCarteCC() const{
    return NumCarteCC;
}
QLineEdit* layoutInserisci::getEdizione() const{
    return Edizione;
}
QCheckBox* layoutInserisci::getCheckVideogioco() const{
    return checkVideogioco;
}
QCheckBox* layoutInserisci::getCheckGiocoTavolo() const{
    return checkGiocoTavolo;
}
QCheckBox* layoutInserisci::getCheckGiocoCarte() const{
    return checkGiocoCarte;
}
QCheckBox* layoutInserisci::getCheckCarteCol() const{
    return checkCarteCol;
}

void layoutInserisci::pulisciTutto() const{
    NomeGioco->clear();
    CasaPro->clear();
    Eta->clear();
    Anno->clear();
    Prezzo->clear();
    PezziMagazzino->clear();
    Usato->setCurrentIndex(0);
    playStation->setCurrentIndex(0);
    xbox->setCurrentIndex(0);
    Genere->clear();
    Sconto->clear();
    Contenuto->clear();
    NumGiocatori->clear();
    Tipologia->clear();
    Regolamento->clear();
    Contenuto1->clear();
    Sconto1->clear();
    edLimitata->setCurrentIndex(0);
    RegolamentoGTC->clear();
    NumGiocatoriGTC->clear();
    ContenutoGTC->clear();
    ScontoGTC->clear();
    NumCarteCC->clear();
    Edizione->clear();
    ScontoCC->clear();
    btnInserisciImm->setIcon(QIcon());
}

void layoutInserisci::pulisciCheck() const{
    (checkVideogioco)->setEnabled(true);
    (checkGiocoTavolo)->setEnabled(true);
    (checkGiocoCarte)->setEnabled(true);
    (checkCarteCol)->setEnabled(true);

    (checkVideogioco)->setChecked(false);
    (checkGiocoTavolo)->setChecked(false);
    (checkGiocoCarte)->setChecked(false);
    (checkCarteCol)->setChecked(false);

    NomeGioco->setEnabled(false);
    CasaPro->setEnabled(false);
    Eta->setEnabled(false);
    Anno->setEnabled(false);
    Prezzo->setEnabled(false);
    PezziMagazzino->setEnabled(false);
    Usato->setEnabled(false);
    //Setto a false i campi della classe videogioco
    playStation->setEnabled(false);
    xbox->setEnabled(false);
    Genere->setEnabled(false);
    Sconto->setEnabled(false);
    Contenuto->setEnabled(false);
    //Setto a false i campi della classe Gioco da tavolo
    NumGiocatori->setEnabled(false);
    Tipologia->setEnabled(false);
    Regolamento->setEnabled(false);
    Contenuto1->setEnabled(false);
    Sconto1->setEnabled(false);
    //Setto a false il campo della seconda base astratta
    edLimitata->setEnabled(false);
    //Setto a false i campi della classe Gioco da tavolo con carte
    RegolamentoGTC->setEnabled(false);
    NumGiocatoriGTC->setEnabled(false);
    ContenutoGTC->setEnabled(false);
    ScontoGTC->setEnabled(false);
    //Setto a false i campi della classe Carte collezionabili
    NumCarteCC->setEnabled(false);
    Edizione->setEnabled(false);
    ScontoCC->setEnabled(false);

    bottoneInserisci->setEnabled(false);
    btnInserisciImm->setEnabled(false);
}

void layoutInserisci::inserisciVideogioco() const{
    checkVideogioco->isChecked() ? (NomeGioco->setEnabled(true),CasaPro->setEnabled(true),Eta->setEnabled(true),Anno->setEnabled(true),Prezzo->setEnabled(true),PezziMagazzino->setEnabled(true), Usato->setEnabled(true),
                                    playStation->setEnabled(true), xbox->setEnabled(true), Genere->setEnabled(true), Sconto->setEnabled(true), Contenuto->setEnabled(true), bottoneInserisci->setEnabled(true), btnInserisciImm->setEnabled(true)) :
                                   (NomeGioco->setEnabled(false),CasaPro->setEnabled(false),Eta->setEnabled(false),Anno->setEnabled(false),Prezzo->setEnabled(false),PezziMagazzino->setEnabled(false),Usato->setEnabled(false),
                                    playStation->setEnabled(false), xbox->setEnabled(false), Genere->setEnabled(false), Sconto->setEnabled(false), Contenuto->setEnabled(false),  bottoneInserisci->setEnabled(false), btnInserisciImm->setEnabled(false), pulisciTutto());
}

void layoutInserisci::inserisciGiocoDaTavolo() const{
    checkGiocoTavolo->isChecked() ? (NomeGioco->setEnabled(true),CasaPro->setEnabled(true),Eta->setEnabled(true),Anno->setEnabled(true),Prezzo->setEnabled(true),PezziMagazzino->setEnabled(true),Usato->setEnabled(true), NumGiocatori->setEnabled(true),
                                     Tipologia->setEnabled(true), Regolamento->setEnabled(true), Contenuto1->setEnabled(true), Sconto1->setEnabled(true), bottoneInserisci->setEnabled(true), btnInserisciImm->setEnabled(true)) :
                                   (NomeGioco->setEnabled(false),CasaPro->setEnabled(false),Eta->setEnabled(false),Anno->setEnabled(false),Prezzo->setEnabled(false),PezziMagazzino->setEnabled(false),Usato->setEnabled(false),
                                    NumGiocatori->setEnabled(false), Tipologia->setEnabled(false), Regolamento->setEnabled(false), Contenuto1->setEnabled(false), Sconto1->setEnabled(false), bottoneInserisci->setEnabled(false), btnInserisciImm->setEnabled(false), pulisciTutto());
}

void layoutInserisci::inserisciGiocoDiCarte() const{
    checkGiocoCarte->isChecked() ? (NomeGioco->setEnabled(true),CasaPro->setEnabled(true),Eta->setEnabled(true),Anno->setEnabled(true),Prezzo->setEnabled(true),PezziMagazzino->setEnabled(true),Usato->setEnabled(true),
                                    edLimitata->setEnabled(true), RegolamentoGTC->setEnabled(true), NumGiocatoriGTC->setEnabled(true), ContenutoGTC->setEnabled(true), ScontoGTC->setEnabled(true), bottoneInserisci->setEnabled(true), btnInserisciImm->setEnabled(true)) :
                                    (NomeGioco->setEnabled(false),CasaPro->setEnabled(false),Eta->setEnabled(false),Anno->setEnabled(false),Prezzo->setEnabled(false),PezziMagazzino->setEnabled(false),Usato->setEnabled(false),
                                     edLimitata->setEnabled(false), RegolamentoGTC->setEnabled(false), NumGiocatoriGTC->setEnabled(false), ContenutoGTC->setEnabled(false), ScontoGTC->setEnabled(false), bottoneInserisci->setEnabled(false), btnInserisciImm->setEnabled(false), pulisciTutto());
}

void layoutInserisci::inserisciCarteColl() const{
    checkCarteCol->isChecked() ? (NomeGioco->setEnabled(true),CasaPro->setEnabled(true),Eta->setEnabled(true),Anno->setEnabled(true),Prezzo->setEnabled(true),PezziMagazzino->setEnabled(true),Usato->setEnabled(true),
                                  edLimitata->setEnabled(true), NumCarteCC->setEnabled(true), Edizione->setEnabled(true), ScontoCC->setEnabled(true), bottoneInserisci->setEnabled(true), btnInserisciImm->setEnabled(true)) :
                                 (NomeGioco->setEnabled(false),CasaPro->setEnabled(false),Eta->setEnabled(false),Anno->setEnabled(false),Prezzo->setEnabled(false),PezziMagazzino->setEnabled(false),Usato->setEnabled(false),
                                  edLimitata->setEnabled(false), NumCarteCC->setEnabled(false), Edizione->setEnabled(false), ScontoCC->setEnabled(false), bottoneInserisci->setEnabled(false), btnInserisciImm->setEnabled(false),pulisciTutto());
}

void layoutInserisci::selezionaSoloVideogioco() const{
    checkVideogioco->isChecked() ? (checkGiocoTavolo->setEnabled(false), checkGiocoCarte->setEnabled(false), checkCarteCol->setEnabled(false)) :
                                   (checkGiocoTavolo->setEnabled(true), checkGiocoCarte->setEnabled(true), checkCarteCol->setEnabled(true));
}

void layoutInserisci::selezionaSoloGiocoDaTavolo() const{
    checkGiocoTavolo->isChecked() ? (checkVideogioco->setEnabled(false), checkGiocoCarte->setEnabled(false), checkCarteCol->setEnabled(false)) :
                                    (checkVideogioco->setEnabled(true), checkGiocoCarte->setEnabled(true), checkCarteCol->setEnabled(true));
}

void layoutInserisci::selezionaSoloCarte() const{
    checkGiocoCarte->isChecked() ? (checkVideogioco->setEnabled(false), checkGiocoTavolo->setEnabled(false), checkCarteCol->setEnabled(false)) :
                                   (checkVideogioco->setEnabled(true), checkGiocoTavolo->setEnabled(true), checkCarteCol->setEnabled(true));
}

void layoutInserisci::selezionaSoloCarteCol() const{
    checkCarteCol->isChecked() ? (checkVideogioco->setEnabled(false), checkGiocoTavolo->setEnabled(false), checkGiocoCarte->setEnabled(false)) :
                                 (checkVideogioco->setEnabled(true), checkGiocoTavolo->setEnabled(true), checkGiocoCarte->setEnabled(true));
}
