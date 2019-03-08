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
    annullaMod(new QPushButton("Annulla", this))
{
    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addLayout(formDaTavolo);
    QHBoxLayout* layoutBottoni = new QHBoxLayout;

    QPushButton* bottImm = new QPushButton("Cambia Immagine");
    bottImm->setIconSize(QSize(180,180));
    bottImm->setIcon(QIcon(QString::fromStdString(ogg->getPath())));
    bottImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addWidget(bottImm);

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

    Usato->addItem("No"); Usato->addItem("Si");

    NomeGioco->insert(QString::fromStdString(ogg->getNome()));
    CasaPro->insert(QString::fromStdString(ogg->getCasaProduttrice()));
    Eta->insert(QString::fromStdString(std::to_string(ogg->getEta())));
    Anno->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
    Prezzo->insert(QString::fromStdString(std::to_string(ogg->getPrezzo())));
    PezziMagazzino->insert(QString::fromStdString(std::to_string(ogg->getPezziInMagazzino())));
    ogg->getUsato() ? Usato->setCurrentIndex(1) : Usato->setCurrentIndex(0);
    NumGiocatori->insert(QString::fromStdString(std::to_string(ogg->getNumGiocatori())));
    Tipologia->insert(QString::fromStdString(ogg->getTipologia()));
    Regolamento->insert(QString::fromStdString(ogg->getRegolamento()));
    Contenuto1->insert(QString::fromStdString(ogg->getContenuto()));
    Sconto1->insert(QString::fromStdString(std::to_string(ogg->getSconto())));

    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);
}
