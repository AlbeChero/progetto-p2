#ifndef MODIFICA_H
#define MODIFICA_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<Gerarchia/itemstoretoys.h>
#include<QPushButton>

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

    QComboBox* playStation;
    QComboBox* xbox;
    QLineEdit* Genere;
    QLineEdit* Sconto;
    QLineEdit* Contenuto;

    QFormLayout* formVideo;

    QPushButton* modEffettuata;
    QPushButton* annullaMod;
    QPushButton* modImm;
public:
    modificaVideogioco(QWidget* = nullptr);
    QLineEdit* getNomeGioco();
    QLineEdit* getCasaPro();
    QLineEdit* getEta();
    QLineEdit* getAnno();
    QLineEdit* getPrezzo();
    QLineEdit* getPezziMagazzino();
    QComboBox* getUsato();

    QComboBox* getplayStation();
    QComboBox* getxbox();
    QLineEdit* getGenere();
    QLineEdit* getSconto();
    QLineEdit* getContenuto();

    QPushButton* getmodEffettuata();
    QPushButton* getannullaMod();
    QPushButton* getBottImm();

    void pulisciTutto();
};

#endif // MODIFICA_H
