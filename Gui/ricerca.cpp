#include "ricerca.h"
#include <QLabel>
#include <QListWidget>

layoutRicerca::layoutRicerca(QWidget* p):
    QWidget(p),
    cercaNome(new QLineEdit(this)),
    cercaCasaProduttrice(new QLineEdit(this)),
    cercaEta(new QLineEdit(this)),
    cercaAnnoPubblicazione(new QLineEdit(this)),
    tipoGioco(new QComboBox(this)),
    btnCerca(new QPushButton("CERCA")),
    bottoneElimina(new QPushButton("ELIMINA")),
    bottoneModifica(new QPushButton("MODIFICA")),
    lista(new itemWidget())
{
    tipoGioco->addItem("Scegli il tipo di oggetto");
    tipoGioco->addItem("Videogioco");
    tipoGioco->addItem("Gioco da tavolo");
    tipoGioco->addItem("Gioco di carte");
    tipoGioco->addItem("Carte collezionabili");

    bottoneElimina->setEnabled(false);
    bottoneModifica->setEnabled(false);

    cercaNome->setPlaceholderText("Nome..");
    cercaEta->setPlaceholderText("Eta..");
    cercaCasaProduttrice->setPlaceholderText("Casa produzione..");
    cercaAnnoPubblicazione->setPlaceholderText("Anno pubblicazione..");

    QVBoxLayout * layoutPrincipaleRicerca = new QVBoxLayout(this);
    QVBoxLayout *layoutSelOggetto = new QVBoxLayout();
    QVBoxLayout *layoutSottoRicerca = new QVBoxLayout();
    QHBoxLayout *layoutBottoniRicerca = new QHBoxLayout();
    QFormLayout* form = new QFormLayout();


    layoutSelOggetto->addWidget(tipoGioco);
    form->addRow("NOME",cercaNome);
    form->addRow("CASA DI PRODUZIONE",cercaCasaProduttrice);
    form->addRow("PEGI", cercaEta);
    form->addRow("ANNO",cercaAnnoPubblicazione);

    layoutBottoniRicerca->addWidget(bottoneElimina);
    layoutBottoniRicerca->addWidget(bottoneModifica);
    layoutSottoRicerca->addWidget(lista);
    layoutPrincipaleRicerca->addLayout(layoutSelOggetto);
    layoutPrincipaleRicerca->addLayout(form);
    layoutPrincipaleRicerca->addWidget(btnCerca);
    layoutPrincipaleRicerca->addLayout(layoutSottoRicerca);
    layoutPrincipaleRicerca->addLayout(layoutBottoniRicerca);

    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(slotElementoSelezionato()));
}

QPushButton* layoutRicerca::getBtnRicerca() const{
    return btnCerca;
}

QPushButton* layoutRicerca::getBtnElimina() const{
    return bottoneElimina;
}

QPushButton* layoutRicerca::getBtnModifica() const{
    return bottoneModifica;
}

QLineEdit * layoutRicerca::getCercaNome() const{
    return cercaNome;
}

QLineEdit* layoutRicerca::getCercaCasaProduttrice() const{
    return cercaCasaProduttrice;
}

QLineEdit* layoutRicerca::getCercaEta() const{
    return cercaEta;
}

QLineEdit *layoutRicerca::getCercaAnnoPubblicazione() const{
    return cercaAnnoPubblicazione;
}
QComboBox *layoutRicerca::getTipoGioco() const{
    return tipoGioco;
}
itemWidget* layoutRicerca::getLista() const{
    return lista;
}

void layoutRicerca::pulisciTutto() const{
    tipoGioco->setCurrentIndex(0);
    cercaNome->clear();
    cercaEta->clear();
    cercaCasaProduttrice->clear();
    cercaAnnoPubblicazione->clear();
}

void layoutRicerca::slotElementoSelezionato() const{
    bottoneElimina->setEnabled(true);
    bottoneModifica->setEnabled(true);

}
