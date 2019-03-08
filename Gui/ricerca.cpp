#include "ricerca.h"
#include <QLabel>
#include <QListWidget>

layoutRicerca::layoutRicerca(QWidget* p):
    QWidget(p),
    cercaNome(new QLineEdit(this)),
    cercaCasaProduttrice(new QLineEdit(this)),
    cercaEta(new QLineEdit(this)),
    cercaAnnoPubblicazione(new QLineEdit(this)),
    cercaPrezzo(new QLineEdit(this)),
    tipoGioco(new QComboBox(this))
{
    tipoGioco->addItem("Scegli il tipo di oggetto");
    tipoGioco->addItem("Videogioco");
    tipoGioco->addItem("Gioco da tavolo");
    tipoGioco->addItem("Gioco di carte");
    tipoGioco->addItem("Carte collezionabili");

    cercaNome->setPlaceholderText("Nome..");
    cercaEta->setPlaceholderText("Eta..");
    cercaPrezzo->setPlaceholderText("Prezzo..");
    cercaCasaProduttrice->setPlaceholderText("Casa produzione..");
    cercaAnnoPubblicazione->setPlaceholderText("Anno pubblicazione..");

    QVBoxLayout * layoutPrincipaleRicerca = new QVBoxLayout(this);
    QVBoxLayout *layoutSelOggetto = new QVBoxLayout();
    QVBoxLayout *layoutSottoRicerca = new QVBoxLayout();
    QHBoxLayout *layoutBottoniRicerca = new QHBoxLayout();
    QFormLayout* form = new QFormLayout();

    QListWidget *lista = new QListWidget();
    QPushButton *bottoneCerca = new QPushButton("CERCA");
    QPushButton *bottoneElimina = new QPushButton("Elimina");
    QPushButton *bottoneModifica = new QPushButton("Modifica");

    layoutSelOggetto->addWidget(tipoGioco);
    form->addRow("NOME",cercaNome);
    form->addRow("CASA DI PRODUZIONE",cercaCasaProduttrice);
    form->addRow("PEGI", cercaEta);
    form->addRow("ANNO",cercaAnnoPubblicazione);
    form->addRow("PREZZO",cercaPrezzo);

    layoutBottoniRicerca->addWidget(bottoneElimina);
    layoutBottoniRicerca->addWidget(bottoneModifica);
    layoutSottoRicerca->addWidget(lista);
    layoutPrincipaleRicerca->addLayout(layoutSelOggetto);
    layoutPrincipaleRicerca->addLayout(form);
    layoutPrincipaleRicerca->addWidget(bottoneCerca);
    layoutPrincipaleRicerca->addLayout(layoutSottoRicerca);
    layoutPrincipaleRicerca->addLayout(layoutBottoniRicerca);
}

void layoutRicerca::pulisciTutto() const{
    tipoGioco->setCurrentIndex(0);
    cercaNome->clear();
    cercaEta->clear();
    cercaPrezzo->clear();
    cercaCasaProduttrice->clear();
    cercaAnnoPubblicazione->clear();
}
