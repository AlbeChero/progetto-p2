#ifndef MODIFICAGIOCODATAVOLOCONCARTE_H
#define MODIFICAGIOCODATAVOLOCONCARTE_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>
#include<QFileDialog>

class modificaGiocoDaTavoloConCarte : public QDialog{
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
    QLineEdit* RegolamentoGTC;
    QLineEdit* NumGiocatoriGTC;
    QLineEdit* ContenutoGTC;
    QLineEdit* ScontoGTC;
    QFormLayout* form;
    QPushButton* modEffettuata;
    QPushButton* annullaMod;
    QPushButton* modImm;
    QString pathImmagine;
public:
    modificaGiocoDaTavoloConCarte(QWidget* =nullptr, GiocoDaTavoloConCarte* =nullptr);
    QLineEdit* getNomeGioco();
    QLineEdit* getCasaPro();
    QLineEdit* getEta();
    QLineEdit* getAnno();
    QLineEdit* getPrezzo();
    QLineEdit* getPezziMagazzino();
    QComboBox* getUsato();
    QLineEdit* getRegolamentoGTC();
    QLineEdit* getNumGiocatoriGTC();
    QLineEdit* getContenutoGTC();
    QLineEdit* getScontoGTC();
    QComboBox* getEdLimitata();
    QPushButton* getmodEffettuata();
    QPushButton* getannullaMod();
    QPushButton* getModImm();
    QString getPath() const;
    void inserisciPercorso(std::string);
    void pulisciTutto();
public slots:
    void cambiaImm();
};

#endif // MODIFICAGIOCODATAVOLOCONCARTE_H
