#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H

#include <qmenubar.h>
#include <qwidget.h>
#include <QAction>
#include <QFileDialog>
#include <QLineEdit>

class menuPrincipale : public QMenuBar{
    Q_OBJECT
private:
    QWidget* parent;
    QAction *negozio;
    QAction *ricerca;
    QAction *inserisci;
    QAction *carica;
public:
    menuPrincipale(QWidget *parent = nullptr);
    QMenu *getMenu() const;
    QAction *getNegozio() const;
    QAction *getRicerca() const;
};

#endif // MENUPRINCIPALE_H
