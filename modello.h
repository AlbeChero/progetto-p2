#ifndef MODELLO_H
#define MODELLO_H

#include <Gerarchia/qontainer.h> //Per il Template
#include <Gerarchia/itemstoretoys.h> //Per la gerarchia
#include <QVBoxLayout>

class Modello{
private:
    Container<ItemStoreToys*>* lista;
    std::string Path;
    bool datiSalvati;
public:
    Modello(std::string = ":/Salvataggio dati");
    //~Modello();

    void salvataggio(); //Salvataggio dei dati
    void caricamento(); //Caricamento dei dati
    void setNuovoPercorso(std::string);
    bool getDatiSalvati() const;
    void setDatiSalvati(bool);
    Container<ItemStoreToys*>::iterator begin();
    Container<ItemStoreToys*>::iterator end();
    Container<ItemStoreToys*>::constiterator cbegin() const;
    Container<ItemStoreToys*>::constiterator cend() const;

    Container<ItemStoreToys*>* getLista() const;
};

#endif // MODELLO_H
