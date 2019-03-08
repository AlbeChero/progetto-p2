#include "modificaVideogioco.h"
#include<QLabel>

modificaVideogioco::modificaVideogioco(QWidget* parent, Videogioco* video):
    NomeGioco(new QLineEdit(this)),
    CasaPro(new QLineEdit(this)),
    Eta(new QLineEdit(this)),
    Anno(new QLineEdit(this)),
    Prezzo(new QLineEdit(this)),
    PezziMagazzino(new QLineEdit(this)),
    Usato(new QComboBox(this)),
    playStation(new QComboBox(this)),
    xbox(new QComboBox(this)),
    Genere(new QLineEdit(this)),
    Sconto(new QLineEdit(this)),
    Contenuto(new QLineEdit(this)),
    formVideo(new QFormLayout),
    modEffettuata(new QPushButton("Salva Modifica",this)),
    annullaMod(new QPushButton("Annulla", this))
{

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addLayout(formVideo);
    QHBoxLayout* layoutBottoni = new QHBoxLayout;

    QPushButton* bottImm = new QPushButton("Cambia Immagine");
    bottImm->setIconSize(QSize(180,180));
    bottImm->setIcon(QIcon(QString::fromStdString(video->getPath())));
    bottImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addWidget(bottImm);

    setFixedSize(400,600);

    formVideo->addRow("Nome gioco", NomeGioco);
    NomeGioco->insert(QString::fromStdString(video->getNome()));
    formVideo->addRow("Casa Produzione", CasaPro);
    CasaPro->insert(QString::fromStdString(video->getCasaProduttrice()));
    formVideo->addRow("Pegi", Eta);
    Eta->insert(QString::fromStdString(std::to_string(video->getEta())));
    formVideo->addRow("Anno", Anno);
    Anno->insert(QString::fromStdString(std::to_string(video->getAnnoPubblicazione())));
    formVideo->addRow("Prezzo", Prezzo);
    Prezzo->setMaxLength(5);//Prova
    Prezzo->insert(QString::fromStdString(std::to_string(video->getPrezzo())));
    formVideo->addRow("Pezzi in magazzino", PezziMagazzino);
    PezziMagazzino->insert(QString::fromStdString(std::to_string(video->getPezziInMagazzino())));

    formVideo->addRow("Usato", Usato);
    formVideo->addRow("Disponibile per PS4", playStation);
    formVideo->addRow("Disponibile per XboxOne", xbox);
    Usato->addItem("Si"); Usato->addItem("No");
    playStation->addItem("Si"); playStation->addItem("No");
    xbox->addItem("Si"); xbox->addItem("No");

    formVideo->addRow("Genere", Genere);
    Genere->insert(QString::fromStdString(video->getGenere()));
    formVideo->addRow("Sconto", Sconto);
    Sconto->insert(QString::fromStdString(std::to_string(video->getSconto())));
    formVideo->addRow("Contenuto", Contenuto);
    Contenuto->insert(QString::fromStdString(video->getContenuto()));

    video->getUsato() ? Usato->setCurrentIndex(1) : Usato->setCurrentIndex(0);
    video->getPs4() ? Usato->setCurrentIndex(1) : Usato->setCurrentIndex(0);
    video->getXboxOne() ? Usato->setCurrentIndex(1) : Usato->setCurrentIndex(0);

    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);
}
