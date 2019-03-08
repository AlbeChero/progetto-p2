#include "itemWidget.h"

itemWidget::itemWidget(QWidget* p) : parent(p){
    setIconSize(QSize(150,150));
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);
}

void itemWidget::aggiungiGioco(ItemStoreToys* gioco){
    ListaDiItemStoreToys* oggetto = new ListaDiItemStoreToys(parent, gioco);
    addItem(oggetto);
}
