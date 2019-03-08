#-------------------------------------------------
#
# Project created by QtCreator 2019-02-14T12:38:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QONTAINER
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    Gerarchia/itemstoretoys.cpp \
    Gui/controller.cpp \
    Gui/negozio.cpp \
    Gui/menuPrincipale.cpp \
    Gui/ricerca.cpp \
    Gui/inserisci.cpp \
    Gui/scrollarea.cpp \
    Gui/modificaVideogioco.cpp \
    modello.cpp \
    Gui/listadiitemstoretoys.cpp \
    Gui/itemWidget.cpp \
    Gui/modificagiocodatavolo.cpp \
    Gui/modificagiocodatavoloconcarte.cpp \
    Gui/modificacartecollezionabili.cpp

HEADERS += \
    modello.h \
    Gui/controller.h \
    Gui/menuPrincipale.h \
    Gui/negozio.h \
    Gerarchia/itemstoretoys.h \
    Gerarchia/qontainer.h \
    Gui/ricerca.h \
    Gui/inserisci.h \
    Gui/scrollarea.h \
    Gui/modificaVideogioco.h \
    Gui/listadiitemstoretoys.h \
    Gui/itemWidget.h \
    Gui/modificagiocodatavolo.h \
    Gui/modificagiocodatavoloconcarte.h \
    Gui/modificacartecollezionabili.h

FORMS += \
        qontainer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Salvataggio dati/Dati.xml \
    Salvataggio dati/Dati.xml \
    Salvataggio dati/Immagini/fifa.jpg \
    Salvataggio dati/Immagini/cod4.png \
    Salvataggio dati/Dati.xml \
    Salvataggio dati/Immagini/fifa.jpg \
    Salvataggio dati/Immagini/cod4.png

RESOURCES += \
    risorse.qrc
