#ifndef MODIFICACARTECOLLEZIONABILI_H
#define MODIFICACARTECOLLEZIONABILI_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>

class modificaCarteCollezionabili : public QDialog{
private:
    QLineEdit* NomeGioco;
    QLineEdit* CasaPro;
    QLineEdit* Eta;
    QLineEdit* Anno;
    QLineEdit* Prezzo;
    QLineEdit* PezziMagazzino;
    QComboBox* Usato;

    QComboBox* edLimitata;
    QLineEdit* NumCarteCC;
    QLineEdit* Edizione;
    QLineEdit* ScontoCC;

    QFormLayout* form;
    QPushButton* modEffettuata;
    QPushButton* annullaMod;
    QPushButton* modImm;

public:
    modificaCarteCollezionabili(QWidget* =nullptr, CarteCollezionabili* = nullptr);
    QLineEdit* getNomeGioco();
    QLineEdit* getCasaPro();
    QLineEdit* getEta();
    QLineEdit* getAnno();
    QLineEdit* getPrezzo();
    QLineEdit* getPezziMagazzino();
    QComboBox* getUsato();
    QComboBox* getEdLimitata();
    QLineEdit* getNumCarteCC();
    QLineEdit* getEdizione();
    QLineEdit* getScontoCC();
    QPushButton* getModImm();
    void pulisciTutto();
};

#endif // MODIFICACARTECOLLEZIONABILI_H
