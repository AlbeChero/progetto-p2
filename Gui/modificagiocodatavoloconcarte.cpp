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
    form->addRow("Regolamento", RegolamentoGTC);
    form->addRow("Numero di giocatori", NumGiocatoriGTC);
    form->addRow("Contenuto", ContenutoGTC);
    form->addRow("Sconto", ScontoGTC);

    Usato->addItem("No"); Usato->addItem("Si");
    edLimitata->addItem("No"); edLimitata->addItem("Si");

    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);
}

QLineEdit* modificaGiocoDaTavoloConCarte::getNomeGioco(){
     return NomeGioco;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getCasaPro(){
     return CasaPro;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getEta(){
     return Eta;
 }
QLineEdit*modificaGiocoDaTavoloConCarte::getAnno(){
     return Anno;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getPrezzo(){
     return Prezzo;
 }
QLineEdit* modificaGiocoDaTavoloConCarte::getPezziMagazzino(){
     return PezziMagazzino;
 }
QComboBox* modificaGiocoDaTavoloConCarte::getUsato(){
     return Usato;
 }

QPushButton* modificaGiocoDaTavoloConCarte::getmodEffettuata(){
     return modEffettuata;
 }
QPushButton* modificaGiocoDaTavoloConCarte::getannullaMod(){
     return annullaMod;
 }
QPushButton* modificaGiocoDaTavoloConCarte::getModImm(){
     return modImm;
 }

QLineEdit* modificaGiocoDaTavoloConCarte::getRegolamentoGTC(){
      return RegolamentoGTC;
  }
  QLineEdit* modificaGiocoDaTavoloConCarte::getNumGiocatoriGTC(){
      return NumGiocatoriGTC;
  }
  QLineEdit* modificaGiocoDaTavoloConCarte::getContenutoGTC(){
      return ContenutoGTC;
  }
  QLineEdit* modificaGiocoDaTavoloConCarte::getScontoGTC(){
      return ScontoGTC;
  }
  QComboBox* modificaGiocoDaTavoloConCarte::getEdLimitata(){
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
