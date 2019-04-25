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
    QLineEdit* getNomeGioco() const;
    QLineEdit* getCasaPro() const;
    QLineEdit* getEta() const;
    QLineEdit* getAnno() const;
    QLineEdit* getPrezzo() const;
    QLineEdit* getPezziMagazzino() const;
    QComboBox* getUsato() const;
    QLineEdit* getRegolamentoGTC() const;
    QLineEdit* getNumGiocatoriGTC() const;
    QLineEdit* getContenutoGTC() const;
    QLineEdit* getScontoGTC() const;
    QComboBox* getEdLimitata() const;
    QPushButton* getmodEffettuata() const;
    QPushButton* getannullaMod() const;
    QPushButton* getModImm() const;
    QString getPath() const;
    void inserisciPercorso(std::string);
    void pulisciTutto();
public slots:
    void cambiaImm();
};

#endif // MODIFICAGIOCODATAVOLOCONCARTE_H
