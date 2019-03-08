#include "scrollarea.h"
#include <QHBoxLayout>

ScrollArea::ScrollArea(QScrollArea* parent) :
    QScrollArea(parent),
    ins(new layoutInserisci(this)){
    setWidget(ins);
    setWidgetResizable(true);
}

void ScrollArea::pulisciTutto() const{
    ins->pulisciTutto();
}

void ScrollArea::pulisciCheck() const{
    ins->pulisciCheck();
}
