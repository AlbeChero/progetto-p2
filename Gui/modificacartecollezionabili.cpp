#include "modificacartecollezionabili.h"

modificaCarteCollezionabili::modificaCarteCollezionabili(QWidget* p, CarteCollezionabili* ogg):
    NomeGioco(new QLineEdit(this)),
    CasaPro(new QLineEdit(this)),
    Eta(new QLineEdit(this)),
    Anno(new QLineEdit(this)),
    Prezzo(new QLineEdit(this)),
    PezziMagazzino(new QLineEdit(this)),
    Usato(new QComboBox(this)),
    edLimitata(new QComboBox(this)),
    NumCarteCC(new QLineEdit(this)),
    Edizione(new QLineEdit(this)),
    ScontoCC(new QLineEdit(this)),
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

    form->addRow("Nome gioco", NomeGioco); NomeGioco->setMaxLength(70);
    form->addRow("Casa Produzione", CasaPro); CasaPro->setMaxLength(70);
    form->addRow("Pegi", Eta); Eta->setValidator(new QIntValidator(0,99, Eta)); Eta->setMaxLength(2);
    form->addRow("Anno", Anno); Anno->setValidator(new QIntValidator(0, 2100, Anno)); Anno->setMaxLength(4);
    form->addRow("Prezzo originale", Prezzo); Prezzo->setValidator(new QDoubleValidator(0, 999.99, 2, Prezzo)); Prezzo->setMaxLength(5);
    form->addRow("Pezzi in magazzino", PezziMagazzino);  PezziMagazzino->setValidator(new QIntValidator(0, 999,PezziMagazzino)); PezziMagazzino->setMaxLength(3);
    form->addRow("Usato", Usato);
    form->addRow("Edizione limitata", edLimitata);
    form->addRow("Numero di carte", NumCarteCC); NumCarteCC->setValidator(new QIntValidator(0,99, NumCarteCC)); NumCarteCC->setMaxLength(2);
    form->addRow("Edizione", Edizione); Edizione->setMaxLength(70);
    form->addRow("Sconto", ScontoCC);

    Usato->addItem("Si"); Usato->addItem("No");
    edLimitata->addItem("Si"); edLimitata->addItem("No");



    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);

    connect(modImm ,SIGNAL(clicked()),this,SLOT(cambiaImm()));

}

void modificaCarteCollezionabili::inserisciPercorso(std::string p){
    pathImmagine = QString::fromStdString(p);
    modImm->setIcon(QIcon(pathImmagine));
}
void modificaCarteCollezionabili::cambiaImm(){
    QString pathImm = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/SalvataggioDati" , "File immagini(*.JPG;*.PNG)");
    if(pathImm != "") {
        pathImmagine = pathImm;
        modImm->setIcon(QIcon(pathImmagine));
    }
}
QString modificaCarteCollezionabili::getPath() const{
    return pathImmagine;
}
QLineEdit* modificaCarteCollezionabili::getNomeGioco() const{
     return NomeGioco;
 }
QLineEdit* modificaCarteCollezionabili::getCasaPro() const{
     return CasaPro;
 }
QLineEdit* modificaCarteCollezionabili::getEta() const{
     return Eta;
 }
QLineEdit*modificaCarteCollezionabili::getAnno() const{
     return Anno;
 }
QLineEdit* modificaCarteCollezionabili::getPrezzo()  const{
     return Prezzo;
 }
QLineEdit* modificaCarteCollezionabili::getPezziMagazzino() const{
     return PezziMagazzino;
 }
QComboBox* modificaCarteCollezionabili::getUsato() const{
     return Usato;
 }
QComboBox* modificaCarteCollezionabili::getEdLimitata() const{
    return edLimitata;
}

QLineEdit* modificaCarteCollezionabili::getNumCarteCC() const{
      return NumCarteCC;
  }
  QLineEdit* modificaCarteCollezionabili::getEdizione() const{
      return Edizione;
  }
  QLineEdit* modificaCarteCollezionabili::getScontoCC() const{
      return ScontoCC;
  }
QPushButton* modificaCarteCollezionabili::getModImm() const{
       return modImm;
   }

QPushButton* modificaCarteCollezionabili::getmodEffettuata() const{
    return modEffettuata;
}
QPushButton* modificaCarteCollezionabili::getannullaMod() const{
    return annullaMod;
}

void modificaCarteCollezionabili::pulisciTutto(){
    NomeGioco->clear();
    CasaPro->clear();
    Eta->clear();
    Anno->clear();
    Prezzo->clear();
    PezziMagazzino->clear();
    Usato->setCurrentIndex(0);
    NumCarteCC->clear();
    edLimitata->setCurrentIndex(0);
    Edizione->clear();
    ScontoCC->clear();
}
