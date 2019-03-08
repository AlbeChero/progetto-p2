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
    annullaMod(new QPushButton("Annulla", this))
{

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addLayout(form);
    QHBoxLayout* layoutBottoni = new QHBoxLayout;

    QPushButton* bottImm = new QPushButton("Cambia Immagine");
    bottImm->setIconSize(QSize(180,180));
    bottImm->setIcon(QIcon(QString::fromStdString(ogg->getPath())));
    bottImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addWidget(bottImm);

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

    Usato->addItem("No"); Usato->addItem("Si");
    edLimitata->addItem("No"); edLimitata->addItem("Si");

    NomeGioco->insert(QString::fromStdString(ogg->getNome()));
    CasaPro->insert(QString::fromStdString(ogg->getCasaProduttrice()));
    Eta->insert(QString::fromStdString(std::to_string(ogg->getEta())));
    Anno->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
    Prezzo->insert(QString::fromStdString(std::to_string(ogg->getPrezzo())));
    PezziMagazzino->insert(QString::fromStdString(std::to_string(ogg->getPezziInMagazzino())));
    ogg->getUsato() ? Usato->setCurrentIndex(1) : Usato->setCurrentIndex(0);
    ogg->getEdizioneLimitata() ? edLimitata->setCurrentIndex(1) : edLimitata->setCurrentIndex(0);
    NumCarteCC->insert(QString::fromStdString(std::to_string(ogg->getNumCarte())));
    Edizione->insert(QString::fromStdString(ogg->getEdizione()));
    ScontoCC->insert(QString::fromStdString(std::to_string(ogg->getSconto())));

    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);

}
