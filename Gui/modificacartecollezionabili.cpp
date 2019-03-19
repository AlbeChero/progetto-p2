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

    modImm->setIconSize(QSize(180,180));
    modImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addWidget(modImm);

    setFixedSize(400,600);

    form->addRow("Nome gioco", NomeGioco);
    form->addRow("Casa Produzione", CasaPro);
    form->addRow("Pegi", Eta);
    form->addRow("Anno", Anno);
    form->addRow("Prezzo", Prezzo);
    form->addRow("Pezzi in magazzino", PezziMagazzino);
    form->addRow("Usato", Usato);
    form->addRow("Edizione limitata", edLimitata);
    form->addRow("Numero di carte", NumCarteCC);
    form->addRow("Edizione", Edizione);
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
    pathImmagine = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Salvataggio Dati" , "File XML(*.JPG)");
    modImm->setIcon(QIcon(pathImmagine));
}
QString modificaCarteCollezionabili::getPath() const{
    return pathImmagine;
}
QLineEdit* modificaCarteCollezionabili::getNomeGioco(){
     return NomeGioco;
 }
QLineEdit* modificaCarteCollezionabili::getCasaPro(){
     return CasaPro;
 }
QLineEdit* modificaCarteCollezionabili::getEta(){
     return Eta;
 }
QLineEdit*modificaCarteCollezionabili::getAnno(){
     return Anno;
 }
QLineEdit* modificaCarteCollezionabili::getPrezzo(){
     return Prezzo;
 }
QLineEdit* modificaCarteCollezionabili::getPezziMagazzino(){
     return PezziMagazzino;
 }
QComboBox* modificaCarteCollezionabili::getUsato(){
     return Usato;
 }
QComboBox* modificaCarteCollezionabili::getEdLimitata(){
    return edLimitata;
}

QLineEdit* modificaCarteCollezionabili::getNumCarteCC(){
      return NumCarteCC;
  }
  QLineEdit* modificaCarteCollezionabili::getEdizione(){
      return Edizione;
  }
  QLineEdit* modificaCarteCollezionabili::getScontoCC(){
      return ScontoCC;
  }
QPushButton* modificaCarteCollezionabili::getModImm(){
       return modImm;
   }

QPushButton* modificaCarteCollezionabili::getmodEffettuata(){
    return modEffettuata;
}
QPushButton* modificaCarteCollezionabili::getannullaMod(){
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
