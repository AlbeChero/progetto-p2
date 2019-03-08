#include "listadiitemstoretoys.h"

ListaDiItemStoreToys::ListaDiItemStoreToys(QWidget* p , ItemStoreToys* o) : parent(p) , oggetto(o) {
    update();
}

ItemStoreToys* ListaDiItemStoreToys::prelevaOgg() const{ return oggetto; }

void ListaDiItemStoreToys::update(){

    QString path = QString::fromStdString(oggetto->getPath());
    QPixmap p(path);
    setIcon(p.scaled(500,600,Qt::AspectRatioMode::KeepAspectRatio)); //Per l'immagine

    setText(QString::fromStdString(oggetto->infoOggetto())); //Per il testo
}
