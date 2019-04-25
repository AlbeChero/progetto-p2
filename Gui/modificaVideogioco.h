#ifndef MODIFICA_H
#define MODIFICA_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>
#include<QFileDialog>

class modificaVideogioco : public QDialog{
    Q_OBJECT
private:
    QLineEdit* NomeGioco;
    QLineEdit* CasaPro;
    QLineEdit* Eta;
    QLineEdit* Anno;
    QLineEdit* Prezzo;
    QLineEdit* PezziMagazzino;
    QComboBox* Usato;
    QString path;

    QComboBox* playStation;
    QComboBox* xbox;
    QLineEdit* Genere;
    QLineEdit* Sconto;
    QLineEdit* Contenuto;

    QFormLayout* formVideo;

    QPushButton* modEffettuata;
    QPushButton* annullaMod;
    QPushButton* modImm;
    QString pathImmagine;
public:
    modificaVideogioco(QWidget* = nullptr);
    QLineEdit* getNomeGioco() const;
    QLineEdit* getCasaPro() const;
    QLineEdit* getEta() const;
    QLineEdit* getAnno() const;
    QLineEdit* getPrezzo() const;
    QLineEdit* getPezziMagazzino() const;
    QComboBox* getUsato() const;
    QString getPath() const;

    QComboBox* getplayStation() const;
    QComboBox* getxbox() const;
    QLineEdit* getGenere() const;
    QLineEdit* getSconto() const;
    QLineEdit* getContenuto() const;

    QPushButton* getmodEffettuata() const;
    QPushButton* getannullaMod() const;
    QPushButton* getBottImm() const;
    void inserisciPercorso(std::string);
    void pulisciTutto();
public slots:
    void cambiaImm();
};

#endif // MODIFICA_H
