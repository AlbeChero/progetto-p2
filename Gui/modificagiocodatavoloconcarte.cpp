#include "modificagiocodatavoloconcarte.h"
#include<Gerarchia/itemstoretoys.h>

modificaGiocoDaTavoloConCarte::modificaGiocoDaTavoloConCarte(QWidget* p, GiocoDaTavoloConCarte* ogg):
    NomeGioco(new QLineEdit(this)),
    CasaPro(new QLineEdit(this)),
    Eta(new QLineEdit(this)),
    Anno(new QLineEdit(this)),
    Prezzo(new QLineEdit(this)),
    PezziMagazzino(new QLineEdit(this)),
    Usato(new QComboBox(this)),
    edLimitata(new QComboBox(this)),
    RegolamentoGTC(new QLineEdit(this)),
    NumGiocatoriGTC(new QLineEdit(this)),
    ContenutoGTC(new QLineEdit(this)),
    ScontoGTC(new QLineEdit(this)),
    form(new QFormLayout),
    modEffettuata(new QPushButton("Salva Modifica",this)),
    annullaMod(new QPushButton("Annulla", this)),
    modImm(new QPushButton("Cambia Immagine"))
{
    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addLayout(form);
    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    QHBoxLayout* layoutImm = new QHBoxLayout;

    modImm->setIconSize(QSize(180,180));
    modImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addLayout(layoutImm);
    layoutImm->addWidget(modImm);

    setMinimumSize(500,600);

    form->addRow("Nome gioco", NomeGioco);
    NomeGioco->setMaxLength(70);
    form->addRow("Casa Produzione", CasaPro);
     CasaPro->setMaxLength(70);
    form->addRow("Pegi", Eta); Eta->setValidator(new QIntValidator(0,99, Eta)); Eta->setMaxLength(2);
    form->addRow("Anno", Anno); Anno->setValidator(new QIntValidator(0, 2100, Anno)); Anno->setMaxLength(4);
    form->addRow("Prezzo originale", Prezzo); Prezzo->setValidator(new QDoubleValidator(0, 999.99, 2, Prezzo)); Prezzo->setMaxLength(5);
    form->addRow("Pezzi in magazzino", PezziMagazzino); PezziMagazzino->setValidator(new QIntValidator(0, 999,PezziMagazzino)); PezziMagazzino->setMaxLength(3);
    form->addRow("Usato", Usato);
    form->addRow("Edizione limitata", edLimitata);
    form->addRow("Regolamento", RegolamentoGTC); RegolamentoGTC->setMaxLength(70);
    form->addRow("Numero di giocatori", NumGiocatoriGTC); NumGiocatoriGTC->setValidator(new QIntValidator(0,99, NumGiocatoriGTC)); NumGiocatoriGTC->setMaxLength(2);
    form->addRow("Contenuto", ContenutoGTC); ContenutoGTC->setMaxLength(70);
    form->addRow("Sconto", ScontoGTC);

    Usato->addItem("Si"); Usato->addItem("No");
    edLimitata->addItem("Si"); edLimitata->addItem("No");

    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);

    connect(modImm ,SIGNAL(clicked()),this,SLOT(cambiaImm()));
}

void modificaGiocoDaTavoloConCarte::inserisciPercorso(std::string p){
    pathImmagine = QString::fromStdString(p);
    modImm->setIcon(QIcon(pathImmagine));
}
void modificaGiocoDaTavoloConCarte::cambiaImm(){
    QString pathImm = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/SalvataggioDati" , "File immagini(*.JPG;*.PNG)");
    if(pathImm != "") {
    pathImmagine = pathImm;
    modImm->setIcon(QIcon(pathImmagine));
    }
}
QLineEdit* modificaGiocoDaTavoloConCarte::getNomeGioco() const{
     return NomeGioco;
 }
QString modificaGiocoDaTavoloConCarte::getPath() const{
    return pathImmagine;
}
QLineEdit* modificaGiocoDaTavoloConCarte::getCasaPro() const{
     return CasaPro;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getEta() const{
     return Eta;
 }
QLineEdit*modificaGiocoDaTavoloConCarte::getAnno() const{
     return Anno;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getPrezzo() const{
     return Prezzo;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getPezziMagazzino() const{
     return PezziMagazzino;
 }
QComboBox* modificaGiocoDaTavoloConCarte::getUsato() const{
     return Usato;
 }

QPushButton* modificaGiocoDaTavoloConCarte::getmodEffettuata() const{
     return modEffettuata;
 }
QPushButton* modificaGiocoDaTavoloConCarte::getannullaMod() const{
     return annullaMod;
 }
QPushButton* modificaGiocoDaTavoloConCarte::getModImm() const{
     return modImm;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getRegolamentoGTC() const{
      return RegolamentoGTC;
  }
  QLineEdit* modificaGiocoDaTavoloConCarte::getNumGiocatoriGTC() const{
      return NumGiocatoriGTC;
  }
  QLineEdit* modificaGiocoDaTavoloConCarte::getContenutoGTC() const{
      return ContenutoGTC;
  }
  QLineEdit* modificaGiocoDaTavoloConCarte::getScontoGTC() const{
      return ScontoGTC;
  }
  QComboBox* modificaGiocoDaTavoloConCarte::getEdLimitata() const{
      return edLimitata;
  }

  void modificaGiocoDaTavoloConCarte::pulisciTutto(){
      NomeGioco->clear();
      CasaPro->clear();
      Eta->clear();
      Anno->clear();
      Prezzo->clear();
      PezziMagazzino->clear();
      Usato->setCurrentIndex(0);
      edLimitata->setCurrentIndex(0);
      RegolamentoGTC->clear();
      NumGiocatoriGTC->clear();
      ContenutoGTC->clear();
      ScontoGTC->clear();
  }
