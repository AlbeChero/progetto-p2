#ifndef RICERCA_H
#define RICERCA_H

#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QFormLayout>
#include <QRadioButton>
#include <modello.h>
#include <QComboBox>
#include <QFormLayout>
#include <QWidget>
#include <QCheckBox>
#include <QWidgetList>
#include <QPushButton>
#include <Gui/itemwidget.h>

class layoutRicerca : public QWidget{
    Q_OBJECT
private:
    QLineEdit *cercaNome;
    QLineEdit *cercaCasaProduttrice;
    QLineEdit *cercaEta;
    QLineEdit *cercaAnnoPubblicazione;
    QComboBox *tipoGioco;
    QPushButton *btnCerca;
    QPushButton *bottoneElimina;
    QPushButton *bottoneModifica;
    itemWidget *lista;
public:
    layoutRicerca(QWidget* = nullptr);
    QLineEdit *getCercaNome() const;
    QLineEdit *getCercaCasaProduttrice() const;
    QLineEdit *getCercaEta() const;
    QLineEdit *getCercaAnnoPubblicazione() const;
    QComboBox *getTipoGioco() const;
    QPushButton *getBtnRicerca() const;
    QPushButton *getBtnModifica() const;
    QPushButton *getBtnElimina() const;
    itemWidget* getLista() const;
    void pulisciTutto() const;
};

#endif // RICERCA_H
