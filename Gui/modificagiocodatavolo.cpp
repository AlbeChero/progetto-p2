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
    QHBoxLayout* layoutImm = new QHBoxLayout;

    modImm->setIconSize(QSize(180,180));
    modImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addLayout(layoutImm);
    layoutImm->addWidget(modImm);

    setMinimumSize(500,600);

    formDaTavolo->addRow("Nome gioco", NomeGioco); NomeGioco->setMaxLength(70);
    formDaTavolo->addRow("Casa Produzione", CasaPro); CasaPro->setMaxLength(70);
    formDaTavolo->addRow("Pegi", Eta);
    Eta->setValidator(new QIntValidator(0,99, Eta)); Eta->setMaxLength(2);
    formDaTavolo->addRow("Anno", Anno);
    Anno->setValidator(new QIntValidator(0, 2100, Anno)); Anno->setMaxLength(4);
    formDaTavolo->addRow("Prezzo originale", Prezzo);
    Prezzo->setValidator(new QDoubleValidator(0, 999.99, 2, Prezzo)); Prezzo->setMaxLength(5);
    formDaTavolo->addRow("Pezzi in magazzino", PezziMagazzino);
    PezziMagazzino->setValidator(new QIntValidator(0, 999,PezziMagazzino)); PezziMagazzino->setMaxLength(3);
    formDaTavolo->addRow("Usato", Usato);
    formDaTavolo->addRow("NumGiocatori", NumGiocatori); NumGiocatori->setValidator(new QIntValidator(0,99, NumGiocatori)); NumGiocatori->setMaxLength(5);
    formDaTavolo->addRow("Tipologia", Tipologia); Tipologia->setMaxLength(70);
    formDaTavolo->addRow("Regolamento", Regolamento); Regolamento->setMaxLength(70);
    formDaTavolo->addRow("Contenuto", Contenuto1); Contenuto1->setMaxLength(70);
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
    QString pathImm = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/SalvataggioDati" , "File immagini(*.JPG;*.PNG)");
    if(pathImm != "") {
    pathImmagine = pathImm;
    modImm->setIcon(QIcon(pathImmagine));
    }
}
QString modificaGiocoDaTavolo::getPath() const{
    return pathImmagine;
}
QLineEdit* modificaGiocoDaTavolo::getNomeGioco() const{
     return NomeGioco;
 }
 QLineEdit* modificaGiocoDaTavolo::getCasaPro() const{
     return CasaPro;
 }
 QLineEdit* modificaGiocoDaTavolo::getEta() const{
     return Eta;
 }
 QLineEdit* modificaGiocoDaTavolo::getAnno() const{
     return Anno;
 }
 QLineEdit* modificaGiocoDaTavolo::getPrezzo() const{
     return Prezzo;
 }
 QLineEdit* modificaGiocoDaTavolo::getPezziMagazzino() const{
     return PezziMagazzino;
 }
 QComboBox* modificaGiocoDaTavolo::getUsato() const{
     return Usato;
 }
 QLineEdit* modificaGiocoDaTavolo::getNumGiocatori() const{
     return NumGiocatori;
 }
 QLineEdit* modificaGiocoDaTavolo::getTipologia() const{
     return Tipologia;
 }
 QLineEdit* modificaGiocoDaTavolo::getRegolamento() const{
     return Regolamento;
 }
 QLineEdit* modificaGiocoDaTavolo::getContenuto1() const{
     return Contenuto1;
 }
 QLineEdit* modificaGiocoDaTavolo::getSconto1() const{
     return Sconto1;
 }
 QPushButton* modificaGiocoDaTavolo::getmodEffettuata() const{
     return modEffettuata;
 }
 QPushButton* modificaGiocoDaTavolo::getannullaMod() const{
     return annullaMod;
 }
 QPushButton* modificaGiocoDaTavolo::getModImm() const{
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
