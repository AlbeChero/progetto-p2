#include<modello.h>

#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include<iostream>

void Modello::setNuovoPercorso(std::string p){
    Path = p;
    delete lista;
    datiSalvati = false;
    lista = new Container<ItemStoreToys*>();
}

void Modello::setDatiSalvati(bool p){ datiSalvati = p; }

bool Modello::getDatiSalvati() const{ return datiSalvati; }

Container<ItemStoreToys*>::iterator Modello::begin(){
    return lista->it_begin();
}

Container<ItemStoreToys*>::iterator Modello::end(){
    return lista->it_end();
}

Container<ItemStoreToys*>::constiterator Modello::cbegin() const{
    return lista->const_begin();
}

Container<ItemStoreToys*>::constiterator Modello::cend() const{
    return lista->const_end();
}

void Modello::salvataggio(){
    QSaveFile file(QString::fromStdString(Path));

    if(!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QXmlStreamWriter lettore(&file);

    lettore.setAutoFormatting(true); // Per leggibilità del file XML
    lettore.writeStartDocument();  // Scrive le intestazioni XML
    lettore.writeComment("!!!Non modificate");

    lettore.writeStartElement("root");

    auto it = cbegin();
    while(it != cend()){
        const ItemStoreToys* daSalvare = *it;
        const QString tipologiaOgg = QString::fromStdString(daSalvare->getTipo());
        lettore.writeEmptyElement(tipologiaOgg);
        lettore.writeAttribute("Nome", QString::fromStdString(daSalvare->getNome()));
        lettore.writeAttribute("CasaProduttrice", QString::fromStdString(daSalvare->getCasaProduttrice()));
        lettore.writeAttribute("Eta", QString("%1").arg(daSalvare->getEta()));
        lettore.writeAttribute("AnnoPubblicazione", QString("%1").arg(daSalvare->getAnnoPubblicazione()));
        lettore.writeAttribute("Prezzo", QString("%1").arg(daSalvare->getPrezzo()));
        lettore.writeAttribute("PezziInMagazzino", QString("%1").arg(daSalvare->getPezziInMagazzino()));
        lettore.writeAttribute("Usato", daSalvare->getUsato() ? "true" : "false");
        lettore.writeAttribute("pathImm", QString::fromStdString(daSalvare->getPath()));

        if(tipologiaOgg == "Videogioco"){
            const Videogioco* oggVideogioco = static_cast<const Videogioco*>(daSalvare);
            lettore.writeAttribute("Ps4", oggVideogioco->getPs4() ? "true" : "false");
            lettore.writeAttribute("XboxOne", oggVideogioco->getXboxOne() ? "true" : "false");
            lettore.writeAttribute("Genere", QString::fromStdString(oggVideogioco->getGenere()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggVideogioco->getSconto()));
            lettore.writeAttribute("Contenuto", QString::fromStdString(oggVideogioco->getContenuto()));
        } else if(tipologiaOgg == "GiocoDaTavolo"){
            const GiocoDaTavolo* oggGiocoDaTavolo = static_cast<const GiocoDaTavolo*>(daSalvare);
            lettore.writeAttribute("NumGiocatori", QString("%1").arg(oggGiocoDaTavolo->getNumGiocatori()));
            lettore.writeAttribute("Tipologia", QString::fromStdString(oggGiocoDaTavolo->getTipologia()));
            lettore.writeAttribute("Regolamento", QString::fromStdString(oggGiocoDaTavolo->getRegolamento()));
            lettore.writeAttribute("Contenuto", QString::fromStdString(oggGiocoDaTavolo->getContenuto()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggGiocoDaTavolo->getSconto()));
        } else if(tipologiaOgg == "GiocoDaTavoloConCarte"){
            const GiocoDaTavoloConCarte* oggGiocoDaTavoloConCarte = static_cast<const GiocoDaTavoloConCarte*>(daSalvare);
            lettore.writeAttribute("edizioneLimitata", oggGiocoDaTavoloConCarte->getEdizioneLimitata() ? "True" : "False");
            lettore.writeAttribute("Regolamento", QString::fromStdString(oggGiocoDaTavoloConCarte->getRegolamento()));
            lettore.writeAttribute("NumGiocatori", QString("%1").arg(oggGiocoDaTavoloConCarte->getNumGiocatori()));
            lettore.writeAttribute("Contenuto", QString::fromStdString(oggGiocoDaTavoloConCarte->getContenuto()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggGiocoDaTavoloConCarte->getSconto()));
        } else if(tipologiaOgg == "CarteCollezionabili"){
            const CarteCollezionabili* oggCarteCollezionabili = static_cast<const CarteCollezionabili*>(daSalvare);
            lettore.writeAttribute("edizioneLimitata", oggCarteCollezionabili->getEdizioneLimitata() ? "True" : "False");
            lettore.writeAttribute("NumCarte", QString("%1").arg(oggCarteCollezionabili->getNumCarte()));
            lettore.writeAttribute("Edizione", QString::fromStdString(oggCarteCollezionabili->getEdizione()));
            lettore.writeAttribute("Sconto", QString("%1").arg(oggCarteCollezionabili->getSconto()));
        }

        ++it;
    }

    lettore.writeEndElement();
    lettore.writeEndDocument();
    datiSalvati = true;
    file.commit();
}

void Modello::caricamento(){
    QFile fileSalvataggio(QString::fromStdString(Path));

    if(!fileSalvataggio.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è stato possibile aprire il file" << fileSalvataggio.errorString();
        return ;
    }

    QXmlStreamReader lettore(&fileSalvataggio);
    if(lettore.readNextStartElement()){
        if(lettore.name() == "root"){
            while(lettore.readNextStartElement()){
                const QXmlStreamAttributes attributo = lettore.attributes();

                std::string Nome = attributo.hasAttribute("Nome") ? attributo.value("Nome").toString().toStdString() : "";
                std::string CasaProduttrice = attributo.hasAttribute("CasaProduttrice") ? attributo.value("CasaProduttrice").toString().toStdString() : "";
                unsigned int Pegi = attributo.hasAttribute("Eta") ? attributo.value("Eta").toUInt() : 0;
                unsigned int Anno = attributo.hasAttribute("AnnoPubblicazione") ? attributo.value("AnnoPubblicazione").toUInt() : 0;
                std::string path= attributo.hasAttribute("pathImm")? attributo.value("pathImm").toString().toStdString(): "";
                double Prezzo = attributo.hasAttribute("Prezzo") ? attributo.value("Prezzo").toDouble() : 0;
                unsigned int PezziInMagazzino = attributo.hasAttribute("PezziInMagazzino") ? attributo.value("PezziInMagazzino").toUInt() : 0;
                bool Usato = attributo.hasAttribute("Usato") ? attributo.value("Usato").toString()=="true" ? true : false : false;
                std::string pathImm = attributo.hasAttribute("pathImm") ? attributo.value("pathImm").toString().toStdString() : "";

                ItemStoreToys* daInserire = nullptr;

                if(lettore.name() == "Videogioco"){
                    bool Ps4 = attributo.hasAttribute("Ps4") ? attributo.value("Ps4").toString()=="true"? true: false : false;
                    bool XboxOne = attributo.hasAttribute("XboxOne") ? attributo.value("XboxOne").toString()=="true"? true: false : false;
                    std::string Genere = attributo.hasAttribute("Genere") ? attributo.value("Genere").toString().toStdString() : "";
                    std::string Contenuto = attributo.hasAttribute("Contenuto") ? attributo.value("Contenuto").toString().toStdString() : "";
                    unsigned int Sconto = attributo.hasAttribute("Sconto") ? attributo.value("Sconto").toUInt() : 0;

                    daInserire = new Videogioco(Nome, CasaProduttrice, Anno, Pegi, Prezzo, PezziInMagazzino, Usato, pathImm, Ps4, XboxOne, Contenuto, Genere, Sconto);
                } else if(lettore.name() == "GiocoDaTavolo"){
                    unsigned int NumGiocatori = attributo.hasAttribute("NumGiocatori") ? attributo.value("NumGiocatori").toUInt() : 0;
                    std::string Tipologia = attributo.hasAttribute("Tipologia") ? attributo.value("Tipologia").toString().toStdString() : "";
                    std::string Regolamento = attributo.hasAttribute("Regolamento") ? attributo.value("Regolamento").toString().toStdString() : "";
                    std::string Contenuto = attributo.hasAttribute("Contenuto") ? attributo.value("Contenuto").toString().toStdString() : "";
                    unsigned int Sconto = attributo.hasAttribute("Sconto") ? attributo.value("Sconto").toUInt() : 0;

                    daInserire = new GiocoDaTavolo(Nome, CasaProduttrice, Pegi, Anno, Prezzo, Sconto, PezziInMagazzino, Usato, pathImm, NumGiocatori, Tipologia, Regolamento, Contenuto);
                } else if(lettore.name() == "GiocoDaTavoloConCarte"){
                    bool edizioneLimitata = attributo.hasAttribute("edizioneLimitata") ? attributo.value("edizioneLimitata").toString()=="true"? true : false : false;
                    std::string Regolamento = attributo.hasAttribute("Regolamento") ? attributo.value("Regolamento").toString().toStdString() : "";
                    unsigned int NumGiocatori = attributo.hasAttribute("NumGiocatori") ? attributo.value("NumGiocatori").toUInt() : 0;
                    std::string Contenuto = attributo.hasAttribute("Contenuto") ? attributo.value("Contenuto").toString().toStdString() : "";
                    unsigned int Sconto = attributo.hasAttribute("Sconto") ? attributo.value("Sconto").toUInt() : 0;

                    daInserire = new GiocoDaTavoloConCarte(Nome, CasaProduttrice, Anno, Pegi, Prezzo, Sconto, PezziInMagazzino, Usato, pathImm, edizioneLimitata, Regolamento, NumGiocatori, Contenuto);
                } else if(lettore.name() == "CarteCollezionabili"){
                    bool edizioneLimitata = attributo.hasAttribute("edizioneLimitata") ? attributo.value("edizioneLimitata").toString()=="true"? true: false : false;
                    int NumCarte = attributo.hasAttribute("NumCarte") ? attributo.value("NumCarte").toInt() : 0;
                    std::string Edizione = attributo.hasAttribute("Edizione") ? attributo.value("Edizione").toString().toStdString() : "";
                    unsigned int Sconto = attributo.hasAttribute("Sconto") ? attributo.value("Sconto").toUInt() : 0;

                    daInserire = new CarteCollezionabili(Nome, CasaProduttrice, Anno, Pegi, Prezzo, Sconto, PezziInMagazzino, edizioneLimitata, pathImm, Usato, NumCarte, Edizione);
                }

                if(daInserire!=nullptr)
                    lista->insertBack(daInserire);

                if(!lettore.isEndDocument())
                    lettore.skipCurrentElement();
            }
        }
    }
    datiSalvati=true;
    fileSalvataggio.close();
}

Modello::Modello(std::string p):
    lista(new Container<ItemStoreToys*>),
    Path(p),
    datiSalvati(true) {}

Container<ItemStoreToys*>* Modello::getLista() const{ return lista; }
