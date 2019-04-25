#ifndef NEGOZIO_H
#define NEGOZIO_H

#include "itemWidget.h"

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QCheckBox>

class layoutNegozio : public QWidget{
    Q_OBJECT
private:
    //QVBoxLayout *layoutN;
    QWidget* parent;
    QPushButton *bottoneRimuovi;
    QPushButton *bottoneModifica;
    QCheckBox *checkbox1;
    QCheckBox *checkbox2;
    QCheckBox *checkbox3;
    QCheckBox *checkbox4;
    itemWidget *lista;

public:
    layoutNegozio(QWidget* =nullptr);
    QPushButton *getBtnRimuovi() const;
    QPushButton *getBtnModifica() const;
    QCheckBox *getCheckBox1() const;
    QCheckBox *getCheckBox2() const;
    QCheckBox *getCheckBox3() const;
    QCheckBox *getCheckBox4() const;
    itemWidget *getLista() const;
    void pulisciTutto() const;

public slots:
        void slotElementoSelezionato() const;
        void selezionaSoloVideogioco() const;
        void selezionaSoloGiocoDaTavolo() const;
        void selezionaSoloCarte() const;
        void selezionaSoloCarteCol() const;

};

#endif // NEGOZIO_H
