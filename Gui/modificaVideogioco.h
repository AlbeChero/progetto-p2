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
    QLineEdit* getNomeGioco();
    QLineEdit* getCasaPro();
    QLineEdit* getEta();
    QLineEdit* getAnno();
    QLineEdit* getPrezzo();
    QLineEdit* getPezziMagazzino();
    QComboBox* getUsato();
    QString getPath();

    QComboBox* getplayStation();
    QComboBox* getxbox();
    QLineEdit* getGenere();
    QLineEdit* getSconto();
    QLineEdit* getContenuto();

    QPushButton* getmodEffettuata();
    QPushButton* getannullaMod();
    QPushButton* getBottImm();
    void inserisciPercorso(std::string);
    void pulisciTutto();
public slots:
    void cambiaImm();
};

#endif // MODIFICA_H
