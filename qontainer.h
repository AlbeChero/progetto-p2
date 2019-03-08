ifndef QONTAINER_H
#define QONTAINER_H

#include<iostream>

template <class T> //Template di classe per la gestione del contenitore
class Container{
private:
    class Nodo;

    class SmartP{
        friend class constiterator;
    public:
        Nodo* punt;
        SmartP(Nodo* p = 0);
        SmartP(const SmartP&);
        ~SmartP();
        SmartP& operator=(const SmartP&);
        Nodo& operator*() const;
        Nodo* operator->() const;
        bool operator==(const SmartP&) const;
        bool operator!=(const SmartP&) const;
    };

    static SmartP copy(const SmartP&, const SmartP&);

    class Nodo{
    public:
        T info; //Qui metto i giochi all'interno della lista
        SmartP prev, next;
        int riferimenti; //Serve per lo Smart Pointer
        Nodo(const T& =0, const SmartP& = 0, const SmartP& =0);
    };

    SmartP primo;
    SmartP ultimo;

public:

    void insertFront(const T&); //Inserimento
    void insertBack(const T&); //Inserimento

    class constiterator { //ITERATORE COSTANTE
        //friend class Container<T>;
      private:
        SmartP pt;
        bool pte; // true if past-the-end
      public:
        constiterator();
        constiterator(const SmartP& =0, bool =false);
        constiterator(const constiterator&);
        constiterator& operator++();
        constiterator& operator--();
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const constiterator&) const;
        bool operator!=(const constiterator& x) const;
      };

    class iterator { //ITERATORE
        //friend class Container<T>;
      private:
        SmartP pt;
        bool pte; // true if past-the-end
      public:
        iterator();
        iterator(const SmartP&, bool =false);
        iterator(const iterator&);
        iterator& operator++();
        iterator& operator--();
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const iterator&) const;
        bool operator!=(const iterator& x) const;
      };

    iterator it_begin() const;
    iterator it_end() const;

    constiterator const_begin() const;
    constiterator const_end() const;

    SmartP& Rimozione(const T&);
    void Ricerca(const T&) const;
};


//=================================================================== #SMARTP

template<class T>
Container<T>::SmartP::SmartP(Nodo* p) : punt(p) { if(punt) punt->riferimenti++; } //Ogni volta che parte il costruttore deve aggiungere

template<class T>
Container<T>::SmartP::SmartP(const SmartP& s) : punt(s.punt) { if(punt) punt->riferimenti++; }

template<class T>
Container<T>::SmartP::~SmartP() {
    if(punt){
        punt->riferimenti--;
        if(punt->riferimenti == 0)
            delete punt;
    }
}

template<class T>
typename Container<T>::SmartP& Container<T>::SmartP::operator=(const SmartP& s){
    if(this != &s){
        Nodo* t = punt;
        punt = s.punt;
        if(punt) punt->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti == 0) delete t;
        }
    }
    return *this;
}

template<class T>
typename Container<T>::Nodo& Container<T>::SmartP::operator*() const{ return *punt; }

template<class T>
typename Container<T>::Nodo* Container<T>::SmartP::operator->() const{ return punt; }

template<class T>
bool Container<T>::SmartP::operator==(const SmartP& p) const{ return punt == p.punt; }

template<class T>
bool Container<T>::SmartP::operator!=(const SmartP& p) const{ return punt != p.punt; }

template<class T>
typename Container<T>::SmartP Container<T>::copy(const SmartP& fst, const SmartP& lst) {
    if(fst == nullptr) return lst = 0;
        SmartP f = new Nodo(fst->info,nullptr,nullptr), p = f;
        while(fst->next != nullptr) {
            p->next = new Nodo(fst->next->info,p,nullptr);
            fst = fst->next;
            p=p->next;
           }
    lst=p;
    return f;
}

//=================================================================== #CONTAINER

template<class T>
void Container<T>::insertFront(const T& t){
    primo = new Nodo(t, nullptr, primo);

        if(ultimo == nullptr){
            ultimo = primo;

        }
        else (primo->next)->prev = primo;
}

template<class T>
void Container<T>::insertBack(const T& t){
    ultimo = new Nodo(t, ultimo, nullptr);

        if(primo == nullptr){
            primo = ultimo;
            }
        else (ultimo->prev)->next = ultimo;
}

template<class T>
typename Container<T>::constiterator Container<T>::const_begin() const{ return constiterator(primo); }

template<class T>
typename Container<T>::constiterator Container<T>::const_end() const{
    if( primo == nullptr ) return constiterator(nullptr);
    return constiterator(ultimo, true);
}

template<class T>
typename Container<T>::iterator Container<T>::it_begin() const{
    return iterator(primo);
}

template<class T>
typename Container<T>::iterator Container<T>::it_end() const{
    if( primo == nullptr ) return iterator(nullptr);
    return iterator(ultimo->next, true);
}

template<class T>
typename Container<T>::SmartP& Container<T>::Rimozione(const T& x){
    SmartP prossimo = x->next;
    x->prev->next = x->next;
    x->next->prev = x->prev;
    delete x;
    return prossimo;
}

template<class T> //SITUAZIONE TEMPORANEA CON IL COUT, DA RIVEDERE CON L'IMPLEMENTAZIONE DELLA GUI
void Container<T>::Ricerca(const T& t) const{
    iterator it = it_begin();
    for(; it!=it_end(); ++it){
        if(*(*it) == *t){ std::cout<<"Oggetto trovato"<<std::endl; return; }
    }
    std::cout<<"Non trovato"<<std::endl;
}

//====================================================================== #NODO

template <class T>
Container<T>::Nodo::Nodo(const T& t, const SmartP& p, const SmartP& n): info(t), prev(p), next(n), riferimenti(0) {}

//======================================================================= CONSTITERATOR

template<class T>
Container<T>::constiterator::constiterator() : pt(nullptr), pte(false) {}

template<class T>
Container<T>::constiterator::constiterator(const SmartP& p, bool pastEnd) : pt(p), pte(pastEnd) {}

template<class T>
Container<T>::constiterator::constiterator(const constiterator& cit) : pt(cit.pt), pte(cit.pte) {}

template<class T>
typename Container<T>::constiterator& Container<T>::constiterator::operator++(){
    if(!pte && pt != 0){
        if(pt->next == nullptr) {
            pt = (pt->next).punt;
            pte=true;
        }
        else pt = (pt->next).punt;
    }
    return *this;
}

template<class T>
typename Container<T>::constiterator& Container<T>::constiterator::operator --(){
    if(pte){
        pt = pt->prev;
        pte = false;
    }
    else{
        if(pt) pt = pt->next;
    }
    return *this;
}

template<class T>
const T& Container<T>::constiterator::operator* () const { return (pt->info); }

template<class T>
const T* Container<T>::constiterator::operator->() const { return &(pt->info); }

template<class T>
bool Container<T>::constiterator::operator==(const constiterator& x) const{ return pt == x.pt; }

template<class T>
bool Container<T>::constiterator::operator!=(const constiterator& x) const{ return pt != x.pt; }

//============================================================================= #ITERATOR

template<class T>
Container<T>::iterator::iterator() : pt(nullptr), pte(false) {}

template<class T>
Container<T>::iterator::iterator(const SmartP& p, bool passEnd) : pt(p), pte(passEnd) {}

template<class T>
Container<T>::iterator::iterator(const iterator& it) : pt(it.pt), pte(it.pte) {}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator++(){
    if(!pte && pt != 0){
        if(pt->next == nullptr) {
            pt = pt->next;
            pte = true;
        }
        else pt = pt->next;
    }
    return *this;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator--(){
    if(pte){
        pt = pt->prev;
        pte = false;
    }
    else{
        if(pt) pt = pt->next;
    }
    return *this;
}

template<class T>
const T& Container<T>::iterator::operator* () const { return pt->info; }

template<class T>
const T* Container<T>::iterator::operator->() const { return &(pt->info); }

template<class T>
bool Container<T>::iterator::operator==(const iterator& x) const{ return pt == x.pt; }

template<class T>
bool Container<T>::iterator::operator!=(const iterator& x) const{ return pt != x.pt; }

#endif // QONTAINER_H
