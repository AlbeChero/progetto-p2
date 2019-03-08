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

class layoutRicerca : public QWidget{
    Q_OBJECT
private:
    QLineEdit *cercaNome;
    QLineEdit *cercaCasaProduttrice;
    QLineEdit *cercaEta;
    QLineEdit *cercaAnnoPubblicazione;
    QLineEdit *cercaPrezzo;
    QComboBox *tipoGioco;
public:
    layoutRicerca(QWidget* = nullptr);
    QLineEdit *getCercaNome() const;
    QLineEdit *getCercaCasaProduttrice() const;
    QLineEdit *getCercaEta;
    QLineEdit *getCercaAnnoPubblicazione() const;
    QLineEdit *getCercaPrezzo() const;
    QComboBox *getTipoGioco() const;
    void pulisciTutto() const;
};

#endif // RICERCA_H
