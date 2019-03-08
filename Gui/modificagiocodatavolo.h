#ifndef MODIFICAGIOCODATAVOLO_H
#define MODIFICAGIOCODATAVOLO_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>

class modificaGiocoDaTavolo : public QDialog{
private:
    QLineEdit* NomeGioco;
    QLineEdit* CasaPro;
    QLineEdit* Eta;
    QLineEdit* Anno;
    QLineEdit* Prezzo;
    QLineEdit* PezziMagazzino;
    QComboBox* Usato;

    QLineEdit* NumGiocatori;
    QLineEdit* Tipologia;
    QLineEdit* Regolamento;
    QLineEdit* Contenuto1;
    QLineEdit* Sconto1;

    QFormLayout* formDaTavolo;
    QPushButton* modEffettuata;
    QPushButton* annullaMod;
public:
    modificaGiocoDaTavolo(QWidget* = nullptr, GiocoDaTavolo* =nullptr);
};

#endif // MODIFICAGIOCODATAVOLO_H
