#include "scrollarea.h"
#include <QHBoxLayout>

ScrollArea::ScrollArea(QScrollArea* p) :
    ins(new layoutInserisci(this)),
    parent(p){
    setWidget(ins);
    setWidgetResizable(true);
}

void ScrollArea::pulisciTutto() const{
    ins->pulisciTutto();
}

void ScrollArea::pulisciCheck() const{
    ins->pulisciCheck();
}

QWidget* ScrollArea::getParent() const{
    return parent;
}

layoutInserisci* ScrollArea::getLayoutInserisci() const{
    return ins;
}
