#if !defined(NOEUD)
#define NOEUD
#include "contact.hpp"

class Noeud{
    Contact contact;
    Noeud * suivant;
    Noeud * precedent;

    public:

    Noeud();
    Noeud(Contact);
    Noeud(Contact,Noeud *);
    Noeud(Contact,Noeud *,Noeud *);
    Noeud * getSuivant();
    Noeud * getPrecedent();
    Contact getContact();
    void setSuivant(Noeud *);
    void setPrecedent(Noeud *);
    void setContact(Contact );
};
Noeud::Noeud(){
    this->contact = Contact();
    this->suivant = nullptr;
    this->precedent = nullptr;
}
Noeud::Noeud(Contact cont){
    this->contact = cont;
    this->suivant = nullptr;
    this->precedent = nullptr;
}
Noeud::Noeud(Contact cont,Noeud * suivant){
    this->contact = cont;
    this->suivant = suivant;
    this->precedent = nullptr;
}
Noeud::Noeud(Contact cont,Noeud * suivant,Noeud * precedent){
    this->contact = cont;
    this->suivant = suivant;
    this->precedent = precedent;
}
Noeud * Noeud::getSuivant(){  return this->suivant;}
Noeud * Noeud::getPrecedent(){  return this->precedent;}
Contact Noeud::getContact(){return this->contact;}
void Noeud::setSuivant(Noeud *suiv){  this->suivant=suiv;}
void Noeud::setPrecedent(Noeud *pred){  this->precedent=pred;}
void Noeud::setContact(Contact cont){ this->contact=cont;}

#endif // NOEUD
