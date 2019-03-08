#include "negozio.h"
#include<QListWidget>

QPushButton *layoutNegozio::getBtnAggiungi() const{
    return bottoneAggiungi;
}

QPushButton *layoutNegozio::getBtnRimuovi() const{
    return bottoneRimuovi;
}

QPushButton *layoutNegozio::getBtnModifica() const{
    return bottoneModifica;
}

QCheckBox *layoutNegozio::getCheckBox1() const{
    return checkbox1;
}

QCheckBox *layoutNegozio::getCheckBox2() const{
    return checkbox2;
}

QCheckBox *layoutNegozio::getCheckBox3() const{
    return checkbox3;
}

QCheckBox *layoutNegozio::getCheckBox4() const{
    return checkbox4;
}

layoutNegozio::layoutNegozio(QWidget* p) :
    parent(p),
    bottoneAggiungi(new QPushButton("Aggiungi")),
    bottoneRimuovi(new QPushButton("Rimuovi")),
    bottoneModifica(new QPushButton("Modifica")),
    checkbox1(new QCheckBox("Videogioco", this)),
    checkbox2(new QCheckBox("Gioco da tavolo", this)),
    checkbox3(new QCheckBox("Gioco di carte", this)),
    checkbox4(new QCheckBox("Carte collezionabili", this))
{
    const QSize btnSize = QSize(100, 50);
    bottoneAggiungi->setFixedSize(btnSize);
    bottoneRimuovi->setFixedSize(btnSize);
    bottoneModifica->setFixedSize(btnSize);
    bottoneAggiungi->setStyleSheet("font: bold; font-size: 15px;");
    bottoneRimuovi->setStyleSheet("font: bold; font-size: 15px;");
    bottoneModifica->setStyleSheet("font: bold; font-size: 15px;");
    checkbox1->setStyleSheet("font: bold; font-size: 15px;");
    checkbox2->setStyleSheet("font: bold; font-size: 15px;");
    checkbox3->setStyleSheet("font: bold; font-size: 15px;");
    checkbox4->setStyleSheet("font: bold; font-size: 15px;");

    QHBoxLayout *layoutNegozio = new QHBoxLayout();
    QVBoxLayout *layoutPulsanti = new QVBoxLayout();
    QHBoxLayout *sottoNegozio = new QHBoxLayout();

    layoutNegozio->addWidget(new QListWidget()); //Temporanea
    layoutPulsanti->addWidget(bottoneAggiungi);
    layoutPulsanti->addWidget(bottoneRimuovi);
    layoutPulsanti->addWidget(bottoneModifica);

    layoutNegozio->addLayout(layoutPulsanti);

    sottoNegozio->addWidget(checkbox1);
    sottoNegozio->addWidget(checkbox2);
    sottoNegozio->addWidget(checkbox3);
    sottoNegozio->addWidget(checkbox4);

    layoutNegozio->addLayout(sottoNegozio);

}

layoutNegozio::~layoutNegozio(){
    delete parent;
    delete bottoneAggiungi;
    delete bottoneModifica;
    delete bottoneRimuovi;
    delete checkbox1;
    delete checkbox2;
    delete checkbox3;
    delete checkbox4;
}
