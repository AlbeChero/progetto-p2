#ifndef MODIFICACARTECOLLEZIONABILI_H
#define MODIFICACARTECOLLEZIONABILI_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>
#include<QFileDialog>

class modificaCarteCollezionabili : public QDialog{
     Q_OBJECT
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

    QString pathImmagine;

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
    QPushButton* getmodEffettuata();
    QPushButton* getannullaMod();
    void inserisciPercorso(std::string);
    QPushButton* getModImm();
    QString getPath() const;
    void pulisciTutto();
public slots:
    void cambiaImm();
};

#endif // MODIFICACARTECOLLEZIONABILI_H
