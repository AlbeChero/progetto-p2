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

    modImm->setIconSize(QSize(180,180));
    modImm->setFixedSize(QSize(380,200));
    layoutPrincipale->addWidget(modImm);

    setFixedSize(400,600);

    formVideo->addRow("Nome gioco", NomeGioco);
    formVideo->addRow("Casa Produzione", CasaPro);
    formVideo->addRow("Pegi", Eta);
    formVideo->addRow("Anno", Anno);
    formVideo->addRow("Prezzo", Prezzo);
    Prezzo->setMaxLength(5);//Prova
    formVideo->addRow("Pezzi in magazzino", PezziMagazzino);

    formVideo->addRow("Usato", Usato);
    formVideo->addRow("Disponibile per PS4", playStation);
    formVideo->addRow("Disponibile per XboxOne", xbox);
    Usato->addItem("Si"); Usato->addItem("No");
    playStation->addItem("Si"); playStation->addItem("No");
    xbox->addItem("Si"); xbox->addItem("No");
    formVideo->addRow("Genere", Genere);
    formVideo->addRow("Sconto", Sconto);
    formVideo->addRow("Contenuto", Contenuto);


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
    pathImmagine = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Salvataggio Dati" , "File XML(*.JPG)");
    modImm->setIcon(QIcon(pathImmagine));
}
QString modificaVideogioco::getPath(){
    return pathImmagine;
}
QLineEdit* modificaVideogioco::getNomeGioco(){
        return NomeGioco;
    }
QLineEdit* modificaVideogioco::getCasaPro(){
        return CasaPro;
    }
QLineEdit* modificaVideogioco::getEta(){
        return Eta;
    }
QLineEdit* modificaVideogioco::getAnno(){
        return Anno;
    }
QLineEdit* modificaVideogioco::getPrezzo(){
        return Prezzo;
    }
QLineEdit* modificaVideogioco::getPezziMagazzino(){
        return PezziMagazzino;
    }
QComboBox* modificaVideogioco::getUsato(){
        return Usato;
    }

QComboBox* modificaVideogioco::getplayStation(){
        return playStation;
    }
QComboBox* modificaVideogioco::getxbox(){
        return xbox;
    }
QLineEdit* modificaVideogioco::getGenere(){
        return Genere;
    }
QLineEdit* modificaVideogioco::getSconto(){
        return Sconto;
    }
QLineEdit* modificaVideogioco::getContenuto(){
        return Contenuto;
    }
QPushButton* modificaVideogioco::getmodEffettuata(){
        return modEffettuata;
    }
QPushButton* modificaVideogioco::getannullaMod(){
        return annullaMod;
    }
QPushButton* modificaVideogioco::getBottImm(){
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

