#include<typeinfo>
#include<string>
#include<vector>
#include<typeinfo>

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
     static const unsigned int PezziMassimi;
public:
     ItemStoreToys(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, bool =0);
     double getPrezzo() const { return Prezzo; }
     void itemsVenduti(unsigned int);
     void itemsComprati(unsigned int);
     virtual double prezzoScontato() const = 0; //METODO virtuale puro
     virtual std::string getContenuto() const = 0; //METODO virtuale puro
     virtual void modificaSconto(unsigned int) = 0; //METODO virtuale puro
     virtual ItemStoreToys* clone() const = 0; //METODO virtuale puro
     virtual bool operator==(const ItemStoreToys&) const; //METODO virtual puro
     void prezzoSeUsato();
     virtual ~ItemStoreToys() = default;

     void setNome();
     void setCasaProduzione();
     void setEta();
     void setAnnoPubblicazione();
     void setPrezzo();
     void setPezziMagazzino();
     void setUsato();
     std::string getNome() const;
};

class Videogioco: public ItemStoreToys{
private:
    bool Ps4;
    bool XboxOne;
    std::string Genere;
    unsigned int Sconto;
    std::string Contenuto;
public:
    Videogioco(std::string ="0", std::string ="0", unsigned int =0 ,unsigned int =0, double =0, unsigned int =0, bool =0,
               bool =0, bool =0, std::string ="0", std::string ="0", unsigned int =0);
    virtual double prezzoScontato() const;
    virtual std::string getContenuto() const;
    virtual void modificaSconto(unsigned int);
    virtual bool operator==(const ItemStoreToys&) const;
    Videogioco* clone() const;

    void setPs4();
    void setXboX();
    void setGenere();
    void setContenuto();
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
                  unsigned int =0, bool =0, unsigned int =0, std::string ="0", std::string ="0", std::string ="0");
    virtual double prezzoScontato() const;
    virtual std::string getContenuto() const;
    virtual void modificaSconto(unsigned int);
    GiocoDaTavolo* clone() const;
    virtual bool operator==(const ItemStoreToys&) const;

    void setNumGiocatori();
    void setTipologia();
    void setRegolamento();
    void setContenuto();
};

class GiocoDiCarte : public ItemStoreToys{ //BASE ASTRATTA
private:
    bool edizioneLimitata;
public:
    GiocoDiCarte(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, bool =0, bool =0);
    void setEdizioneLimitata();
    virtual bool operator==(const ItemStoreToys&) const;
};

class GiocoDaTavoloConCarte : public GiocoDiCarte{
private:
         std::string Regolamento;
         unsigned int NumGiocatori;
         std::string Contenuto;
         unsigned int Sconto;
public:
         GiocoDaTavoloConCarte(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0,
                               unsigned int =0, bool =0, bool =0, std::string ="0", unsigned int =0, std::string ="0");
         virtual double prezzoScontato() const;
         virtual std::string getContenuto() const;
         virtual void modificaSconto(unsigned int);
         GiocoDaTavoloConCarte* clone() const;
         virtual bool operator==(const ItemStoreToys&) const;

         void setRegolamento();
         void setNumGicoatori();
         void setContenuto();
};

class CarteCollezionabili : public GiocoDiCarte{
private:
        int NumCarte;
        std::string Edizione;
        unsigned int Sconto;
public:
        CarteCollezionabili(std::string ="0", std::string ="0", unsigned int =0, unsigned int =0, double =0, unsigned int =0, unsigned int =0, bool =0,
                            bool =0, int =0, std::string ="0");
        virtual double prezzoScontato() const;
        virtual std::string getContenuto() const;
        virtual void modificaSconto(unsigned int);
        CarteCollezionabili* clone() const;
        virtual bool operator==(const ItemStoreToys&) const;

        void setNumCarte();
        void setEdizione();
};
