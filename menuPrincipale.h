#ifndef QONTAINER_H
#define QONTAINER_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>

//#include "controller.h"

class controller;

class menuPrincipale : public QMenuBar{
    Q_OBJECT

private:
    QWidget* parent;
    QMenuBar *barraMenu;
    QMenu *menu;
    QAction *salva;
    QAction *esci;
    QMenu *negozio;
    QMenu *ricerca;
public:
    menuPrincipale(QWidget *parent = nullptr);
    QMenuBar *getBarraMenu() const;
    QMenu *getMenu() const;
    QAction *getSalva() const;
    QAction *getEsci() const;
    QMenu *getNegozio() const;
    QMenu *getRicerca() const;
};

#endif // QONTAINER_H
