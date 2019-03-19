#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include<QScrollArea>
#include<QVBoxLayout>
#include "Gui/inserisci.h"
#include <QWidget>

class ScrollArea : public QScrollArea{
    Q_OBJECT
private:
    layoutInserisci* ins;
    QWidget* parent;
public:
    ScrollArea(QScrollArea* = nullptr);
    QWidget* getParent() const;
    void pulisciTutto() const;
    void pulisciCheck() const;
    layoutInserisci* getLayoutInserisci() const;
};

#endif // SCROLLAREA_H
