#ifndef MODIFICAGIOCODATAVOLOCONCARTE_H
#define MODIFICAGIOCODATAVOLOCONCARTE_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>

class modificaGiocoDaTavoloConCarte : public QDialog{
private:
    QLineEdit* NomeGioco;
    QLineEdit* CasaPro;
    QLineEdit* Eta;
    QLineEdit* Anno;
    QLineEdit* Prezzo;
    QLineEdit* PezziMagazzino;
    QComboBox* Usato;
    QComboBox* edLimitata;
    QLineEdit* RegolamentoGTC;
    QLineEdit* NumGiocatoriGTC;
    QLineEdit* ContenutoGTC;
    QLineEdit* ScontoGTC;
    QFormLayout* form;
    QPushButton* modEffettuata;
    QPushButton* annullaMod;
public:
    modificaGiocoDaTavoloConCarte(QWidget* =nullptr, GiocoDaTavoloConCarte* =nullptr);
};

#endif // MODIFICAGIOCODATAVOLOCONCARTE_H
