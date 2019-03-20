#include "negozio.h"
#include<QListWidget>

itemWidget* layoutNegozio::getLista() const{ return lista; }

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
    QWidget(p),
    bottoneRimuovi(new QPushButton("Rimuovi", this)),
    bottoneModifica(new QPushButton("Modifica", this)),
    checkbox1(new QCheckBox("Videogioco", this)),
    checkbox2(new QCheckBox("Gioco da tavolo", this)),
    checkbox3(new QCheckBox("Gioco di carte", this)),
    checkbox4(new QCheckBox("Carte collezionabili", this)),
    lista(new itemWidget(this))
{
    const QSize btnSize = QSize(100, 50);
    bottoneRimuovi->setFixedSize(btnSize);
    bottoneModifica->setFixedSize(btnSize);
    bottoneRimuovi->setStyleSheet("font: bold; font-size: 15px;");
    bottoneModifica->setStyleSheet("font: bold; font-size: 15px;");
    checkbox1->setStyleSheet("font: bold; font-size: 15px;");
    checkbox2->setStyleSheet("font: bold; font-size: 15px;");
    checkbox3->setStyleSheet("font: bold; font-size: 15px;");
    checkbox4->setStyleSheet("font: bold; font-size: 15px;");

    QVBoxLayout *layoutN = new QVBoxLayout(this);
    QHBoxLayout *layoutN1 = new QHBoxLayout();
    QVBoxLayout *layoutPulsanti = new QVBoxLayout();
    QHBoxLayout *sottoNegozio = new QHBoxLayout();

    layoutN1->addWidget(lista);
    lista->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    layoutPulsanti->addWidget(bottoneRimuovi);
    layoutPulsanti->addWidget(bottoneModifica);

    bottoneRimuovi->setEnabled(false);
    bottoneModifica->setEnabled(false);

    layoutN1->addLayout(layoutPulsanti);

    sottoNegozio->addWidget(checkbox1);
    sottoNegozio->addWidget(checkbox2);
    sottoNegozio->addWidget(checkbox3);
    sottoNegozio->addWidget(checkbox4);

    layoutN->addLayout(layoutN1);
    layoutN->addLayout(sottoNegozio);

    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(slotElementoSelezionato()));

    connect(checkbox1, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloVideogioco()));
    connect(checkbox2, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloGiocoDaTavolo()));
    connect(checkbox3, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloCarte()));
    connect(checkbox4, SIGNAL(clicked(bool)), this, SLOT(selezionaSoloCarteCol()));
}

void layoutNegozio::pulisciTutto() const{
    checkbox1->setEnabled(true);
    checkbox2->setEnabled(true);
    checkbox3->setEnabled(true);
    checkbox4->setEnabled(true);

    checkbox1->setChecked(false);
    checkbox2->setChecked(false);
    checkbox3->setChecked(false);
    checkbox4->setChecked(false);
}

void layoutNegozio::slotElementoSelezionato() const{
    bottoneModifica->setEnabled(true);
    bottoneRimuovi->setEnabled(true);
}

void layoutNegozio::selezionaSoloVideogioco() const{
    checkbox1->isChecked() ? (checkbox2->setEnabled(false), checkbox3->setEnabled(false), checkbox4->setEnabled(false)) :
                                   (checkbox2->setEnabled(true), checkbox3->setEnabled(true), checkbox4->setEnabled(true));
}

void layoutNegozio::selezionaSoloGiocoDaTavolo() const{
    checkbox2->isChecked() ? (checkbox1->setEnabled(false), checkbox3->setEnabled(false), checkbox4->setEnabled(false)) :
                                    (checkbox1->setEnabled(true), checkbox3->setEnabled(true), checkbox4->setEnabled(true));
}

void layoutNegozio::selezionaSoloCarte() const{
    checkbox3->isChecked() ? (checkbox1->setEnabled(false), checkbox2->setEnabled(false), checkbox4->setEnabled(false)) :
                                   (checkbox1->setEnabled(true), checkbox2->setEnabled(true), checkbox4->setEnabled(true));
}

void layoutNegozio::selezionaSoloCarteCol() const{
    checkbox4->isChecked() ? (checkbox1->setEnabled(false), checkbox2->setEnabled(false), checkbox3->setEnabled(false)) :
                                 (checkbox1->setEnabled(true), checkbox2->setEnabled(true), checkbox3->setEnabled(true));
}

