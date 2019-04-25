#include "modificaVideogioco.h"
#include<QLabel>

modificaVideogioco::modificaVideogioco(QWidget* parent):
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
    annullaMod(new QPushButton("Annulla", this)),
    modImm(new QPushButton("Cambia Immagine")),
    pathImmagine()
{

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addLayout(formVideo);
    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    QHBoxLayout* layoutImm = new QHBoxLayout;

    modImm->setIconSize(QSize(180,180));
    modImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addLayout(layoutImm);
    layoutImm->addWidget(modImm);

    setMinimumSize(500,600);

    formVideo->addRow("Nome gioco", NomeGioco);
    NomeGioco->setMaxLength(70);
    formVideo->addRow("Casa Produzione", CasaPro);
    CasaPro->setMaxLength(70);
    formVideo->addRow("Pegi", Eta);
    Eta->setValidator(new QIntValidator(0,99, Eta)); Eta->setMaxLength(2);
    formVideo->addRow("Anno", Anno);
    Anno->setValidator(new QIntValidator(0, 2100, Anno)); Anno->setMaxLength(4);
    formVideo->addRow("Prezzo originale", Prezzo);
    Prezzo->setMaxLength(5);
    QDoubleValidator* p = new QDoubleValidator(0, 999.99, 2, Prezzo);
    p->setNotation(QDoubleValidator::ScientificNotation);
    Prezzo->setValidator(p);
    formVideo->addRow("Pezzi in magazzino", PezziMagazzino);
    PezziMagazzino->setValidator(new QIntValidator(0, 999,PezziMagazzino)); PezziMagazzino->setMaxLength(3);

    formVideo->addRow("Usato", Usato);
    formVideo->addRow("Disponibile per PS4", playStation);
    formVideo->addRow("Disponibile per XboxOne", xbox);
    Usato->addItem("Si"); Usato->addItem("No");
    playStation->addItem("Si"); playStation->addItem("No");
    xbox->addItem("Si"); xbox->addItem("No");
    formVideo->addRow("Genere", Genere); Genere->setMaxLength(70);
    formVideo->addRow("Sconto", Sconto); Sconto->setValidator(new QIntValidator(0,99, Sconto)); Sconto->setMaxLength(5);
    formVideo->addRow("Contenuto", Contenuto); Contenuto->setMaxLength(70);


    layoutBottoni->addWidget(modEffettuata);
    layoutBottoni->addWidget(annullaMod);
    layoutPrincipale->addLayout(layoutBottoni);

    layoutPrincipale->insertStretch(2,1);

    connect(modImm ,SIGNAL(clicked()),this,SLOT(cambiaImm()));
    connect(modEffettuata, SIGNAL(clicked()), this, SLOT(close()));
}

void modificaVideogioco::inserisciPercorso(std::string p){
    pathImmagine = QString::fromStdString(p);
    modImm->setIcon(QIcon(pathImmagine));
}
void modificaVideogioco::cambiaImm(){
    QString pathImm = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/SalvataggioDati" , "File immagini(*.JPG;*.PNG)");
    if(pathImm != "") {
    pathImmagine = pathImm;
    modImm->setIcon(QIcon(pathImmagine));
    }
}
QString modificaVideogioco::getPath() const{
    return pathImmagine;
}
QLineEdit* modificaVideogioco::getNomeGioco() const{
        return NomeGioco;
    }
QLineEdit* modificaVideogioco::getCasaPro() const{
        return CasaPro;
    }
QLineEdit* modificaVideogioco::getEta() const{
        return Eta;
    }
QLineEdit* modificaVideogioco::getAnno() const{
        return Anno;
    }
QLineEdit* modificaVideogioco::getPrezzo() const{
        return Prezzo;
    }
QLineEdit* modificaVideogioco::getPezziMagazzino() const{
        return PezziMagazzino;
    }
QComboBox* modificaVideogioco::getUsato() const{
        return Usato;
    }

QComboBox* modificaVideogioco::getplayStation() const{
        return playStation;
    }
QComboBox* modificaVideogioco::getxbox() const{
        return xbox;
    }
QLineEdit* modificaVideogioco::getGenere() const{
        return Genere;
    }
QLineEdit* modificaVideogioco::getSconto() const{
        return Sconto;
    }
QLineEdit* modificaVideogioco::getContenuto() const{
        return Contenuto;
    }
QPushButton* modificaVideogioco::getmodEffettuata() const{
        return modEffettuata;
    }
QPushButton* modificaVideogioco::getannullaMod() const{
        return annullaMod;
    }
QPushButton* modificaVideogioco::getBottImm() const{
        return modImm;
    }
void modificaVideogioco::pulisciTutto(){
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
}
