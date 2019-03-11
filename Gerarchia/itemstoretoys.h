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
     static const unsigned int PezziMassimi;
public:
     ItemStoreToys(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, bool =0, std::string ="0");

     void itemsVenduti(unsigned int);
     void itemsComprati(unsigned int);
     virtual double prezzoScontato() const = 0; //METODO virtuale puro
     virtual std::string getContenuto() const = 0; //METODO virtuale puro
     virtual void modificaSconto(unsigned int) = 0; //METODO virtuale puro
     //virtual ItemStoreToys* clone() const = 0; //METODO virtuale puro
     virtual bool operator==(const ItemStoreToys&) const; //METODO virtual puro
     virtual std::string getTipo() const = 0; //METODO vituale puro
     virtual std::string infoOggetto() const;
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

     std::string getNome() const;
     std::string getCasaProduttrice() const;
     unsigned int getEta() const;
     unsigned int getAnnoPubblicazione() const;
     double getPrezzo() const;
     unsigned int getPezziInMagazzino() const;
     bool getUsato() const;
     std::string getPath() const;
};

class Videogioco: public ItemStoreToys{
private:
    bool Ps4;
    bool XboxOne;
    std::string Genere;
    unsigned int Sconto;
    std::string Contenuto;
public:
    Videogioco(std::string ="0", std::string ="0", unsigned int =0 ,unsigned int =0, double =0, unsigned int =0, bool =0, std::string ="0",
               bool =0, bool =0, std::string ="0", std::string ="0", unsigned int =0);
    virtual double prezzoScontato() const;
    virtual void modificaSconto(unsigned int);
    virtual std::string getTipo() const;
    virtual bool operator==(const ItemStoreToys&) const;
    Videogioco* clone() const;
    virtual std::string infoOggetto() const;

    void setPs4(bool);
    void setXboX(bool);
    void setGenere(std::string);
    void setContenuto(std::string);

    bool getPs4() const;
    bool getXboxOne() const;
    std::string getGenere() const;
    unsigned int getSconto() const;
    virtual std::string getContenuto() const;
};

class GiocoDaTavolo : public ItemStoreToys{
private:
    unsigned int NumGiocatori;
    std::string Tipologia;
    std::string Regolamento;
    std::string Contenuto;
    unsigned int Sconto;

public:
    GiocoDaTavolo(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0,
                  unsigned int =0, bool =0, std::string ="0", unsigned int =0, std::string ="0", std::string ="0", std::string ="0");
    virtual double prezzoScontato() const;
    virtual void modificaSconto(unsigned int);
    virtual std::string getTipo() const;
    GiocoDaTavolo* clone() const;
    virtual bool operator==(const ItemStoreToys&) const;
    virtual std::string infoOggetto() const;

    void setNumGiocatori(unsigned int);
    void setTipologia(std::string);
    void setRegolamento(std::string);
    void setContenuto(std::string);

    unsigned int getNumGiocatori() const;
    std::string getTipologia() const;
    std::string getRegolamento() const;
    virtual std::string getContenuto() const;
    unsigned int getSconto() const;
};

class GiocoDiCarte : public ItemStoreToys{ //BASE ASTRATTA
private:
    bool edizioneLimitata;
public:
    GiocoDiCarte(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, bool =0, std::string ="0", bool =0);
    void setEdizioneLimitata(bool);
    virtual bool operator==(const ItemStoreToys&) const;
    virtual std::string getTipo() const = 0;
    virtual std::string infoOggetto() const;

    bool getEdizioneLimitata() const;
};

class GiocoDaTavoloConCarte : public GiocoDiCarte{
private:
         std::string Regolamento;
         unsigned int NumGiocatori;
         std::string Contenuto;
         unsigned int Sconto;
public:
         GiocoDaTavoloConCarte(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0,
                               unsigned int =0, bool =0, std::string ="0", bool =0, std::string ="0", unsigned int =0, std::string ="0");
         virtual double prezzoScontato() const;
         virtual void modificaSconto(unsigned int);
         GiocoDaTavoloConCarte* clone() const;
         virtual std::string getTipo() const;
         virtual bool operator==(const ItemStoreToys&) const;
         virtual std::string infoOggetto() const;

         void setRegolamento(std::string);
         void setNumGicoatori(unsigned int);
         void setContenuto(std::string);

         std::string getRegolamento() const;
         unsigned int getNumGiocatori() const;
         virtual std::string getContenuto() const;
         unsigned int getSconto() const;
};

class CarteCollezionabili : public GiocoDiCarte{
private:
        int NumCarte;
        std::string Edizione;
        unsigned int Sconto;
public:
        CarteCollezionabili(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, unsigned int =0, bool =0, std::string ="0",
                            bool =0, int =0, std::string ="0");
        virtual double prezzoScontato() const;
        virtual std::string getContenuto() const;
        virtual void modificaSconto(unsigned int);
        CarteCollezionabili* clone() const;
        virtual std::string getTipo() const;
        virtual bool operator==(const ItemStoreToys&) const;
        virtual std::string infoOggetto() const;

        void setNumCarte(int);
        void setEdizione(std::string);

        int getNumCarte() const;
        std::string getEdizione() const;
        unsigned int getSconto() const;
};

#endif
