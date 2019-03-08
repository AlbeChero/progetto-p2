#ifndef LISTADIITEMSTORETOYS_H
#define LISTADIITEMSTORETOYS_H
#include<QListWidgetItem>
#include<Gerarchia/itemstoretoys.h>

class ListaDiItemStoreToys : public QListWidgetItem{
private:
    QWidget* parent;
    ItemStoreToys* oggetto;
public:
    ListaDiItemStoreToys(QWidget*, ItemStoreToys* =nullptr);
    ItemStoreToys* prelevaOgg() const;
    void update();
};

#endif // LISTADIITEMSTORETOYS_H
