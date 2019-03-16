#include"itemstoretoys.h"
using std::cin;

//CAMPI STATICI

const unsigned int ItemStoreToys::PezziMassimi = 100; //non è più modificabile

//============================================================

ItemStoreToys::ItemStoreToys(std::string N, std::string House, unsigned int Age ,unsigned int Anno, double Costo, unsigned int PezzMag, bool Uso, std::string Path) :
                Nome(N), CasaProduttrice(House), Eta(Age), AnnoPubblicazione(Anno), Prezzo(Costo), PezziInMagazzino(PezzMag), usato(Uso), pathImm(Path) {}

void ItemStoreToys::itemsVenduti(unsigned int n) { PezziInMagazzino -= n; } //Metodo che mi serve per decrementare il num di pezzi in magazzino

void ItemStoreToys::itemsComprati(unsigned int n) { if(PezziInMagazzino + n <= PezziMassimi) PezziInMagazzino += n; } //Se posso mantenere tutti i nuovi n pezzi in magazzino bene, se no non fa nulla, non li compra

void ItemStoreToys::prezzoSeUsato(){  Prezzo = Prezzo - ((Prezzo*50)/100); } //se l'oggetto è usato devi togliere dal prezzo il 50%

void ItemStoreToys::setNome(std::string s) { Nome = s; }

void ItemStoreToys::setCasaProduzione(std::string s) { CasaProduttrice = s; }

void ItemStoreToys::setEta(unsigned int i) { Eta = i; }

void ItemStoreToys::setAnnoPubblicazione(unsigned int i) { AnnoPubblicazione = i; }

void ItemStoreToys::setPrezzo(double p) { Prezzo = p; }

void ItemStoreToys::setPezziMagazzino(unsigned int p) { PezziInMagazzino = p; }

void ItemStoreToys::setUsato(bool b) { if(b==false) usato = true;  else usato = false; }

bool ItemStoreToys::operator==(const ItemStoreToys& it) const{
    return Nome == it.Nome && CasaProduttrice == it.CasaProduttrice && Eta == it.Eta && AnnoPubblicazione == it.AnnoPubblicazione;
}

void ItemStoreToys::setPath(std::string s){ pathImm = s; }

unsigned int ItemStoreToys::getEta() const{ return Eta; }

std::string ItemStoreToys::getNome() const { return Nome; }

double ItemStoreToys::getPrezzo() const{ return Prezzo; }

std::string ItemStoreToys::getCasaProduttrice() const{ return CasaProduttrice; }

unsigned int ItemStoreToys::getPezziInMagazzino() const{ return PezziInMagazzino; }

bool ItemStoreToys::getUsato() const{ return usato; }

unsigned int ItemStoreToys::getAnnoPubblicazione() const{ return AnnoPubblicazione; }

std::string ItemStoreToys::getPath() const{ return pathImm; }

std::string ItemStoreToys::infoOggetto() const{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << getPrezzo();
    std::string str = "";
    return str.append("Tipologia prodotto: " + getTipo())
            .append("\nNome: " + getNome())
            .append("\nCasaProduttrice: " + getCasaProduttrice())
            .append("\nAnno pubblicazione: " + std::to_string(getAnnoPubblicazione()))
            .append("\nPegi: " + std::to_string(getEta()))
            .append("\nPezzi in magazzino: " + std::to_string(getPezziInMagazzino()))
            .append("\nPrezzo: " + stream.str().append("€"))
            .append("\nUsato: ").append(getUsato() ? "Si" : "No");
}

//============================================================

Videogioco::Videogioco(std::string N, std::string House, unsigned int Age ,unsigned int Anno, double Costo, unsigned int PezzMag, bool Uso, std::string Path,
                       bool ps4, bool xbox, std::string Contenut, std::string Gen, unsigned int Scont)
    : ItemStoreToys(N, House, Anno, Age, Costo, PezzMag, Uso, Path), Ps4(ps4), XboxOne(xbox), Genere(Gen), Sconto(Scont), Contenuto(Contenut) {}

double Videogioco::prezzoScontato() const{ return (Sconto!=0 ? getPrezzo()- (getPrezzo()*Sconto) / 100 : getPrezzo()); }

std::string Videogioco::getContenuto() const{ return Contenuto; }

void Videogioco::modificaSconto(unsigned int sc) { Sconto = sc; }

std::string Videogioco::getTipo() const{ return "Videogioco";}

Videogioco* Videogioco::clone() const{ return new Videogioco(*this); }

void Videogioco::setPs4(bool b){ { if(b==false) Ps4 = true;  else Ps4 = false; } }

void Videogioco::setXboX(bool b){ if(b==false) XboxOne = true;  else XboxOne = false; }

void Videogioco::setGenere(std::string g){ Genere = g; }

void Videogioco::setContenuto(std::string c){ Contenuto = c; }

bool Videogioco::operator==(const ItemStoreToys& it) const{
    const Videogioco* punt = dynamic_cast<const Videogioco*>(&it);
    return punt && ItemStoreToys::operator==(it);
}

bool Videogioco::getPs4() const{ return Ps4; }

bool Videogioco::getXboxOne() const{ return XboxOne; }

std::string Videogioco::getGenere() const{ return Genere; }

unsigned int Videogioco::getSconto() const{ return Sconto; }

std::string Videogioco::infoOggetto() const{
    std::string og = ItemStoreToys::infoOggetto();
    return og.append("\nDisponibile per Ps4: ").append(getPs4() ? "Si" : "No")
            .append("\nDisponibile per XboxOne: ").append(getXboxOne() ? "Si" : "No")
            .append("\nGenere: " + getGenere());
}

//============================================================

GiocoDaTavolo::GiocoDaTavolo(std::string N, std::string House, unsigned int Age ,unsigned int Anno, double Costo, unsigned int Scont, unsigned int PezzMag, bool Uso, std::string Path,
                             unsigned int Num, std::string Tipo, std::string Regole, std::string Cont)
                        : ItemStoreToys(N, House, Age, Anno, Costo, PezzMag, Uso, Path), NumGiocatori(Num), Tipologia(Tipo), Regolamento(Regole), Contenuto(Cont), Sconto(Scont){}

double GiocoDaTavolo::prezzoScontato() const{ return (Sconto!=0 ? getPrezzo()- (getPrezzo()*Sconto) / 100 : getPrezzo()); }

std::string GiocoDaTavolo::getContenuto() const{ return Contenuto; }

void GiocoDaTavolo::modificaSconto(unsigned int sc) { Sconto = sc; }

GiocoDaTavolo* GiocoDaTavolo::clone() const{ return new GiocoDaTavolo(*this); }

std::string GiocoDaTavolo::getTipo() const{ return "GiocoDaTavolo";}

void GiocoDaTavolo::setNumGiocatori(unsigned int n) { NumGiocatori = n; }

void GiocoDaTavolo::setTipologia(std::string t) { Tipologia = t; }

void GiocoDaTavolo::setRegolamento(std::string r) { Regolamento = r; }

void GiocoDaTavolo::setContenuto(std::string c) { Contenuto = c; }

bool GiocoDaTavolo::operator==(const ItemStoreToys& it) const{
    const GiocoDaTavolo* punt = dynamic_cast<const GiocoDaTavolo*>(&it);
    return punt && ItemStoreToys::operator==(it);
}

unsigned int GiocoDaTavolo::getNumGiocatori() const{ return NumGiocatori; }

std::string GiocoDaTavolo::getTipologia() const{ return Tipologia; }

std::string GiocoDaTavolo::getRegolamento() const { return Regolamento; }

unsigned int GiocoDaTavolo::getSconto() const{ return Sconto; }

std::string GiocoDaTavolo::infoOggetto() const{
    std::string og = ItemStoreToys::infoOggetto();
    return og.append("\nTipologia: "+getTipologia())
            .append("\nNumero di giocatori:" + std::to_string(getNumGiocatori()))
            .append("\nRegolamento: "+getRegolamento());
}

//============================================================

GiocoDiCarte::GiocoDiCarte(std::string N, std::string House, unsigned int Age ,unsigned int Anno, double Costo, unsigned int PezzMag, bool Uso, std::string Path, bool edLimitata) : ItemStoreToys(N, House, Anno, Age, Costo, PezzMag, Uso, Path), edizioneLimitata(edLimitata) {}

void GiocoDiCarte::setEdizioneLimitata(bool b) { if(b == false) edizioneLimitata = true;  else edizioneLimitata = false; }

bool GiocoDiCarte::operator==(const ItemStoreToys& it) const{
    const GiocoDiCarte* punt = dynamic_cast<const GiocoDiCarte*>(&it);
    return punt && ItemStoreToys::operator==(it);
}

bool GiocoDiCarte::getEdizioneLimitata() const{ return edizioneLimitata; }

std::string GiocoDiCarte::infoOggetto() const{
    std::string og = ItemStoreToys::infoOggetto();
    return og.append("\nEdizione limitata: ").append(getEdizioneLimitata() ? "Si" : "No");
}

//============================================================

GiocoDaTavoloConCarte::GiocoDaTavoloConCarte(std::string N, std::string House, unsigned int Age ,unsigned int Anno, double Costo, unsigned int Scont, unsigned int PezzMag, bool Uso, std::string Path,
                                             bool edLimitata, std::string Regole, unsigned int N_giocatori, std::string cont)
                                            : GiocoDiCarte(N, House, Age, Anno, Costo, PezzMag, Uso, Path, edLimitata), Regolamento(Regole), NumGiocatori(N_giocatori), Contenuto(cont), Sconto(Scont) {}

double GiocoDaTavoloConCarte::prezzoScontato() const{ return (Sconto!=0 ? getPrezzo()- (getPrezzo()*Sconto) / 100 : getPrezzo()); }

std::string GiocoDaTavoloConCarte::getContenuto() const{ return Contenuto; }

void GiocoDaTavoloConCarte::modificaSconto(unsigned int sc) { Sconto = sc; }

GiocoDaTavoloConCarte* GiocoDaTavoloConCarte::clone() const{ return new GiocoDaTavoloConCarte(*this); }

std::string GiocoDaTavoloConCarte::getTipo() const{ return "GiocoDaTavoloConCarte";}

void GiocoDaTavoloConCarte::setRegolamento(std::string s) { Regolamento = s; }

void GiocoDaTavoloConCarte::setNumGicoatori(unsigned int n) { NumGiocatori = n; }

void GiocoDaTavoloConCarte::setContenuto(std::string c) { Contenuto = c; }

bool GiocoDaTavoloConCarte::operator==(const ItemStoreToys& it) const{
    const GiocoDaTavoloConCarte* punt = dynamic_cast<const GiocoDaTavoloConCarte*>(&it);
    return punt && GiocoDiCarte::operator==(it);
}

std::string GiocoDaTavoloConCarte::getRegolamento() const{ return Contenuto; }

unsigned int GiocoDaTavoloConCarte::getNumGiocatori() const { return NumGiocatori; }

unsigned int GiocoDaTavoloConCarte::getSconto() const{ return Sconto; }

std::string GiocoDaTavoloConCarte::infoOggetto() const{
    std::string og = GiocoDiCarte::infoOggetto();
    return og.append("\nRegolamento: "+ getRegolamento())
            .append("\nNumero di giocatori: " + std::to_string(getNumGiocatori()))
            .append("\nContenuto: " + getContenuto());
}

//=============================================================

CarteCollezionabili::CarteCollezionabili(std::string N, std::string House, unsigned int Age ,unsigned int Anno, double Costo, unsigned int Scont, unsigned int PezzMag, bool edLimitata,  std::string Path, bool Uso,
                                           int NCarte, std::string Edition)
                                        : GiocoDiCarte(N, House, Age, Anno, Costo, PezzMag, Uso, Path, edLimitata), NumCarte(NCarte), Edizione(Edition), Sconto(Scont) {}

double CarteCollezionabili::prezzoScontato() const{ return (Sconto!=0 ? getPrezzo()- (getPrezzo()*Sconto) / 100 : getPrezzo()); }

std::string CarteCollezionabili::getContenuto() const{ auto s = std::to_string(NumCarte); return s; } //conversione da int a string

void CarteCollezionabili::modificaSconto(unsigned int sc) { Sconto = sc; }

std::string CarteCollezionabili::getTipo() const{ return "CarteCollezionabili";}

CarteCollezionabili* CarteCollezionabili::clone() const{ return new CarteCollezionabili(*this); }

void CarteCollezionabili::setNumCarte(int n) { NumCarte = n; }

void CarteCollezionabili::setEdizione(std::string e) { Edizione = e; }

bool CarteCollezionabili::operator==(const ItemStoreToys& it) const{
    const CarteCollezionabili* punt = dynamic_cast<const CarteCollezionabili*>(&it);
    return punt && GiocoDiCarte::operator==(it);
}

int CarteCollezionabili::getNumCarte() const{ return NumCarte; }

std::string CarteCollezionabili::getEdizione() const { return Edizione; }

unsigned int CarteCollezionabili::getSconto() const{ return Sconto; }

std::string CarteCollezionabili::infoOggetto() const{
    std::string og = GiocoDiCarte::infoOggetto();
    return og.append("\nNumero di carte: " + std::to_string(getNumCarte()))
            .append("\nEdizione: " + getEdizione());
}
