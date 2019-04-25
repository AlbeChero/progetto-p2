#ifndef ITEMSTORETOYS_H
#define ITEMSTORETOYS_H

#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>

//====================================================================================== GERARCHIA

class ItemStoreToys{
private:
     std::string Nome;
     std::string CasaProduttrice;
     unsigned int Eta;
     unsigned int AnnoPubblicazione;
     double Prezzo;
     unsigned int PezziInMagazzino;
     bool usato;
     std::string pathImm;
     unsigned int Sconto;
     static const unsigned int PezziMassimi;
public:
     ItemStoreToys(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, bool =0, std::string ="0", unsigned int =0);

     void itemsVenduti(unsigned int);
     void itemsComprati(unsigned int);
     virtual std::string getContenuto() const = 0; //METODO virtuale puro
     virtual bool operator==(const ItemStoreToys&) const; //METODO virtual puro
     virtual std::string getTipo() const = 0; //METODO vituale puro
     virtual std::string infoOggetto();
     void prezzoSeUsato();
     virtual ~ItemStoreToys() = default;

     void setNome(std::string);
     void setCasaProduzione(std::string);
     void setEta(unsigned int);
     void setAnnoPubblicazione(unsigned int);
     void setPrezzo(double);
     void setPezziMagazzino(unsigned int);
     void setUsato(bool);
     void setPath(std::string);
     void setSconto(unsigned int);

     std::string getNome() const;
     std::string getCasaProduttrice() const;
     unsigned int getEta() const;
     unsigned int getAnnoPubblicazione() const;
     double getPrezzo() const;
     unsigned int getPezziInMagazzino() const;
     bool getUsato() const;
     std::string getPath() const;
     unsigned int getSconto() const;
};

class Videogioco: public ItemStoreToys{
private:
    bool Ps4;
    bool XboxOne;
    std::string Genere;
    std::string Contenuto;
public:
    Videogioco(std::string ="0", std::string ="0", unsigned int =0 ,unsigned int =0, double =0, unsigned int =0, bool =0, std::string ="0", unsigned int =0,
               bool =0, bool =0, std::string ="0", std::string ="0");

    virtual std::string getTipo() const;
    virtual bool operator==(const ItemStoreToys&) const;
    virtual std::string infoOggetto();

    void setPs4(bool);
    void setXboX(bool);
    void setGenere(std::string);
    void setContenuto(std::string);

    bool getPs4() const;
    bool getXboxOne() const;
    std::string getGenere() const;
    virtual std::string getContenuto() const;
};

class GiocoDaTavolo : public ItemStoreToys{
private:
    unsigned int NumGiocatori;
    std::string Tipologia;
    std::string Regolamento;
    std::string Contenuto;

public:
    GiocoDaTavolo(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0,
                  bool =0, std::string ="0", unsigned int =0, unsigned int =0, std::string ="0", std::string ="0", std::string ="0");
    virtual std::string getTipo() const;
    virtual bool operator==(const ItemStoreToys&) const;
    virtual std::string infoOggetto();

    void setNumGiocatori(unsigned int);
    void setTipologia(std::string);
    void setRegolamento(std::string);
    void setContenuto(std::string);

    unsigned int getNumGiocatori() const;
    std::string getTipologia() const;
    std::string getRegolamento() const;
    virtual std::string getContenuto() const;
};

class GiocoDiCarte : public ItemStoreToys{ //BASE ASTRATTA
private:
    bool edizioneLimitata;
public:
    GiocoDiCarte(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, bool =0, std::string ="0", unsigned int =0, bool =0);
    void setEdizioneLimitata(bool);
    virtual bool operator==(const ItemStoreToys&) const;
    virtual std::string getTipo() const = 0;
    virtual std::string infoOggetto();

    bool getEdizioneLimitata() const;
};

class GiocoDaTavoloConCarte : public GiocoDiCarte{
private:
         std::string Regolamento;
         unsigned int NumGiocatori;
         std::string Contenuto;
public:
         GiocoDaTavoloConCarte(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0,
                               unsigned int =0, bool =0, std::string ="0", unsigned int=0, bool =0, std::string ="0", unsigned int =0, std::string ="0");
         virtual std::string getTipo() const;
         virtual bool operator==(const ItemStoreToys&) const;
         virtual std::string infoOggetto();

         void setRegolamento(std::string);
         void setNumGicoatori(unsigned int);
         void setContenuto(std::string);

         std::string getRegolamento() const;
         unsigned int getNumGiocatori() const;
         virtual std::string getContenuto() const;
};

class CarteCollezionabili : public GiocoDiCarte{
private:
        int NumCarte;
        std::string Edizione;
public:
        CarteCollezionabili(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, bool =0, std::string ="0",
                            unsigned int =0, bool =0, int =0, std::string ="0");
        virtual std::string getContenuto() const;
        virtual std::string getTipo() const;
        virtual bool operator==(const ItemStoreToys&) const;
        virtual std::string infoOggetto();

        void setNumCarte(int);
        void setEdizione(std::string);

        int getNumCarte() const;
        std::string getEdizione() const;
};

#endif
