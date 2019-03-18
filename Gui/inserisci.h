#ifndef INSERISCI_H
#define INSERISCI_H

#include<QComboBox>
#include<QWidget>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QCheckBox>
#include<QFormLayout>
#include<QScrollBar>
#include<QScrollArea>
#include<QPushButton>

class layoutInserisci : public QWidget{
    Q_OBJECT
private:
    QWidget* parent;
    //Campi della classe astratta
    QLineEdit* NomeGioco;
    QLineEdit* CasaPro;
    QLineEdit* Eta;
    QLineEdit* Anno;
    QLineEdit* Prezzo;
    QLineEdit* PezziMagazzino;
    QComboBox* Usato;

    //Campi della classe Videogioco
    QComboBox* playStation;
    QComboBox* xbox;
    QLineEdit* Genere;
    QLineEdit* Sconto;
    QLineEdit* Contenuto;

    //Campi della classe Gioco da tavolo
    QLineEdit* NumGiocatori;
    QLineEdit* Tipologia;
    QLineEdit* Regolamento;
    QLineEdit* Contenuto1;
    QLineEdit* Sconto1;

    QComboBox* edLimitata; //Campo della seconda base astratta

    //Campi della classe Gioco da tavolo di carte
    QLineEdit* RegolamentoGTC;
    QLineEdit* NumGiocatoriGTC;
    QLineEdit* ContenutoGTC;
    QLineEdit* ScontoGTC;

    //Campi della classe Carte Collezionabili
    QLineEdit* NumCarteCC;
    QLineEdit* Edizione;
    QLineEdit* ScontoCC;

    QCheckBox* checkVideogioco;
    QCheckBox* checkGiocoTavolo;
    QCheckBox* checkGiocoCarte;
    QCheckBox* checkCarteCol;

    QFormLayout* formAstratta;
    QFormLayout* formVideo;
    QFormLayout* formGiocoTavolo;
    QFormLayout* formGTC;
    QFormLayout* formCC;

    QPushButton* bottoneInserisci;

public:
    layoutInserisci(QWidget* = nullptr);
    QLineEdit* getNomeGioco() const;
    QLineEdit* getCasaPro() const;
    QLineEdit* getEta() const;
    QLineEdit* getAnno() const;
    QLineEdit* getPrezzo() const;
    QLineEdit* getPezziMagazzino() const;
    QComboBox* getplayStation() const;
    QComboBox* getxbox() const;
    QComboBox* getUsato() const;
    QLineEdit* getGenere() const;
    QLineEdit* getSconto() const;
    QLineEdit* getContenuto() const;
    QLineEdit* getNumGiocatori() const;
    QLineEdit* getTipologia() const;
    QLineEdit* getRegolamento() const;
    QLineEdit* getContenuto1() const;
    QLineEdit* getSconto1() const;
    QComboBox* getedLimitata() const;
    QLineEdit* getRegolamentoGTC() const;
    QLineEdit* getNumGiocatoriGTC() const;
    QLineEdit* getContenutoGTC() const;
    QLineEdit* getScontoGTC() const;
    QLineEdit* getNumCarteCC() const;
    QLineEdit* getEdizione() const;
    QCheckBox* getCheckVideogioco() const;
    QCheckBox* getCheckGiocoTavolo() const;
    QCheckBox* getCheckGiocoCarte() const;
    QCheckBox* getCheckCarteCol() const;
    QPushButton* getBottoneIns() const;
    void pulisciTutto() const;
    void pulisciCheck() const;

public slots:
    void inserisciVideogioco() const;
    void inserisciGiocoDaTavolo() const;
    void inserisciGiocoDiCarte() const;
    void inserisciCarteColl() const;

    void selezionaSoloVideogioco() const;
    void selezionaSoloGiocoDaTavolo() const;
    void selezionaSoloCarte() const;
    void selezionaSoloCarteCol() const;
};

#endif // INSERISCI_H
