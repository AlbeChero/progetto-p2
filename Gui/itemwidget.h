#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include "listadiitemstoretoys.h"
#include <QListWidget>
#include <QScrollBar>

class itemWidget : public QListWidget{
    Q_OBJECT
private:
    QWidget* parent;
public:
    itemWidget(QWidget* =nullptr);
    void aggiungiGioco(ItemStoreToys*);
    ListaDiItemStoreToys* oggettoCorrente() const;
};

#endif // ITEMWIDGET_H
