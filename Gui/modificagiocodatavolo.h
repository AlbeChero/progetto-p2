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
    QLineEdit* getNomeGioco() const;
    QLineEdit* getCasaPro() const;
    QLineEdit* getEta() const;
    QLineEdit* getAnno() const;
    QLineEdit* getPrezzo() const;
    QLineEdit* getPezziMagazzino() const;
    QComboBox* getUsato() const;
    QLineEdit* getNumGiocatori() const;
    QLineEdit* getTipologia() const;
    QLineEdit* getRegolamento() const;
    QLineEdit* getContenuto1() const;
    QLineEdit* getSconto1() const;
    QPushButton* getmodEffettuata() const;
    QPushButton* getannullaMod() const;
    QPushButton* getModImm() const;
    QString getPath() const;
    void inserisciPercorso(std::string);
    void pulisciTutto();
public slots:
    void cambiaImm();
};

#endif // MODIFICAGIOCODATAVOLO_H
