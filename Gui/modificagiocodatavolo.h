#ifndef MODIFICAGIOCODATAVOLO_H
#define MODIFICAGIOCODATAVOLO_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>
#include<QFileDialog>

class modificaGiocoDaTavolo : public QDialog{
     Q_OBJECT
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
    QPushButton* modImm;

    QString pathImmagine;
public:
    modificaGiocoDaTavolo(QWidget* = nullptr, GiocoDaTavolo* =nullptr);
    QLineEdit* getNomeGioco();
    QLineEdit* getCasaPro();
    QLineEdit* getEta();
    QLineEdit* getAnno();
    QLineEdit* getPrezzo();
    QLineEdit* getPezziMagazzino();
    QComboBox* getUsato();
    QLineEdit* getNumGiocatori();
    QLineEdit* getTipologia();
    QLineEdit* getRegolamento();
    QLineEdit* getContenuto1();
    QLineEdit* getSconto1();
    QPushButton* getmodEffettuata();
    QPushButton* getannullaMod();
    QPushButton* getModImm();
    QString getPath() const;
    void inserisciPercorso(std::string);
    void pulisciTutto();
public slots:
    void cambiaImm();
};

#endif // MODIFICAGIOCODATAVOLO_H
