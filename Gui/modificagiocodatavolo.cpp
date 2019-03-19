#include "modificagiocodatavolo.h"

modificaGiocoDaTavolo::modificaGiocoDaTavolo(QWidget* parent, GiocoDaTavolo* ogg):
    NomeGioco(new QLineEdit(this)),
    CasaPro(new QLineEdit(this)),
    Eta(new QLineEdit(this)),
    Anno(new QLineEdit(this)),
    Prezzo(new QLineEdit(this)),
    PezziMagazzino(new QLineEdit(this)),
    Usato(new QComboBox(this)),
    NumGiocatori(new QLineEdit(this)),
    Tipologia(new QLineEdit(this)),
    Regolamento(new QLineEdit(this)),
    Contenuto1(new QLineEdit(this)),
    Sconto1(new QLineEdit(this)),
    formDaTavolo(new QFormLayout),
    modEffettuata(new QPushButton("Salva Modifica",this)),
    annullaMod(new QPushButton("Annulla", this)),
    modImm(new QPushButton("Cambia Immagine"))
{
    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addLayout(formDaTavolo);
    QHBoxLayout* layoutBottoni = new QHBoxLayout;

    modImm->setIconSize(QSize(180,180));
    modImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addWidget(modImm);

    setFixedSize(400,600);

    formDaTavolo->addRow("Nome gioco", NomeGioco);
    formDaTavolo->addRow("Casa Produzione", CasaPro);
    formDaTavolo->addRow("Pegi", Eta);
    formDaTavolo->addRow("Anno", Anno);
    formDaTavolo->addRow("Prezzo", Prezzo);
    formDaTavolo->addRow("Pezzi in magazzino", PezziMagazzino);
    formDaTavolo->addRow("Usato", Usato);
    formDaTavolo->addRow("NumGiocatori", NumGiocatori);
    formDaTavolo->addRow("Tipologia", Tipologia);
    formDaTavolo->addRow("Regolamento", Regolamento);
    formDaTavolo->addRow("Contenuto", Contenuto1);
    formDaTavolo->addRow("Sconto", Sconto1);

    Usato->addItem("Si"); Usato->addItem("No");

    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);

    connect(modImm ,SIGNAL(clicked()),this,SLOT(cambiaImm()));
}

void modificaGiocoDaTavolo::inserisciPercorso(std::string p){
    pathImmagine = QString::fromStdString(p);
    modImm->setIcon(QIcon(pathImmagine));
}
void modificaGiocoDaTavolo::cambiaImm(){
    pathImmagine = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Salvataggio Dati" , "File XML(*.JPG)");
    modImm->setIcon(QIcon(pathImmagine));
}
QString modificaGiocoDaTavolo::getPath() const{
    return pathImmagine;
}
QLineEdit* modificaGiocoDaTavolo::getNomeGioco(){
     return NomeGioco;
 }
 QLineEdit* modificaGiocoDaTavolo::getCasaPro(){
     return CasaPro;
 }
 QLineEdit* modificaGiocoDaTavolo::getEta(){
     return Eta;
 }
 QLineEdit* modificaGiocoDaTavolo::getAnno(){
     return Anno;
 }
 QLineEdit* modificaGiocoDaTavolo::getPrezzo(){
     return Prezzo;
 }
 QLineEdit* modificaGiocoDaTavolo::getPezziMagazzino(){
     return PezziMagazzino;
 }
 QComboBox* modificaGiocoDaTavolo::getUsato(){
     return Usato;
 }
 QLineEdit* modificaGiocoDaTavolo::getNumGiocatori(){
     return NumGiocatori;
 }
 QLineEdit* modificaGiocoDaTavolo::getTipologia(){
     return Tipologia;
 }
 QLineEdit* modificaGiocoDaTavolo::getRegolamento(){
     return Regolamento;
 }
 QLineEdit* modificaGiocoDaTavolo::getContenuto1(){
     return Contenuto1;
 }
 QLineEdit* modificaGiocoDaTavolo::getSconto1(){
     return Sconto1;
 }
 QPushButton* modificaGiocoDaTavolo::getmodEffettuata(){
     return modEffettuata;
 }
 QPushButton* modificaGiocoDaTavolo::getannullaMod(){
     return annullaMod;
 }
 QPushButton* modificaGiocoDaTavolo::getModImm(){
     return modImm;
 }
 void modificaGiocoDaTavolo::pulisciTutto(){
     NomeGioco->clear();
     CasaPro->clear();
     Eta->clear();
     Anno->clear();
     Prezzo->clear();
     PezziMagazzino->clear();
     Usato->setCurrentIndex(0);
     NumGiocatori->clear();
     Tipologia->clear();
     Regolamento->clear();
     Contenuto1->clear();
     Sconto1->clear();
 }
