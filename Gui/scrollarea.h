#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include<QScrollArea>
#include<QVBoxLayout>
#include "Gui/inserisci.h"

class ScrollArea : public QScrollArea{
    Q_OBJECT
private:
    layoutInserisci* ins;
public:
    ScrollArea(QScrollArea* = nullptr);
    void pulisciTutto() const;
    void pulisciCheck() const;
};

#endif // SCROLLAREA_H
