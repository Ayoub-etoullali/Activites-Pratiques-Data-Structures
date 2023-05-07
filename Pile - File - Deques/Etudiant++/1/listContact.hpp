#if !defined(LISTCONTACT)
#define LISTCONTACT
#include "noeud.hpp"
#include <iostream>

class ListeContact{
    Noeud * tete,* queue;
    int nbrContacts;

    Noeud * getByNom(std::string);
    Noeud * getByTel(std::string);
    Noeud * getByMail(std::string);

    public:
    ListeContact();
    int getNbrContacts();
    void ajouterContact(Contact);
    void supprimerContact(std::string);
    void modifierContact(std::string,Contact);
    Contact getContactByNom(std::string);
    Contact getContactByMail(std::string);
    Contact getContactByTel(std::string);
    std::string toString();
};


Noeud * ListeContact::getByNom(std::string nom){
    
    if(!this->nbrContacts)return nullptr;
    Noeud * temp = this->tete;
    while(temp){
        if(temp->getContact().getNom() == nom)return temp;
        temp = temp->getSuivant();
    }
    return nullptr;
}
Noeud * ListeContact::getByTel(std::string tel){
    if(!this->nbrContacts)return nullptr;
    Noeud * temp = this->tete;
    while(temp){
        if(temp->getContact().getTel() == tel)return temp;
        temp = temp->getSuivant();
    }
    return nullptr;
}
Noeud * ListeContact::getByMail(std::string mail){
    if(!this->nbrContacts)return nullptr;
    Noeud * temp = this->tete;
    while(temp){
        if(temp->getContact().getMail() == mail)return temp;
        temp = temp->getSuivant();
    }
    return nullptr;
}
ListeContact::ListeContact(){
    this->tete = this->queue = nullptr;
    this->nbrContacts=0;
}
int ListeContact::getNbrContacts(){return this->nbrContacts;}

void ListeContact::ajouterContact(Contact cont){
    if(getByTel(cont.getTel()))return;
    if(this->nbrContacts++==0){
        this->tete=this->queue=new Noeud(cont);
        return;
    }
    Noeud * new_noeud = new Noeud(cont,this->queue);
    this->queue = new_noeud;
}

void ListeContact::supprimerContact(std::string nom){
    Noeud * found =getByNom(nom);
    if(!found)return;
    Noeud * pred =found->getPrecedent();
    Noeud * suiv =found->getSuivant();
    if(pred)
        pred->setSuivant(suiv);
    if(suiv)
        suiv->setPrecedent(pred);
    delete found;
}
void ListeContact::modifierContact(std::string nom,Contact cont){
    Noeud * found =getByNom(nom);
    if(!found)return;
    found ->getContact().setTel(cont.getTel());
    found ->getContact().setNom(cont.getNom());
    found ->getContact().setMail(cont.getMail());
}
Contact ListeContact::getContactByNom(std::string nom){
    Noeud * found = this->getByNom(nom);
    if(!found)return Contact();
        return found->getContact();
    }
Contact ListeContact::getContactByMail(std::string mail){
            Noeud * found = this->getByMail(mail);
    if(!found)return Contact();
        return found->getContact();
}
Contact ListeContact::getContactByTel(std::string tel){
            Noeud * found = this->getByTel(tel);
    if(!found)return Contact();
        return found->getContact();
}
// std::string ListeContact::toString(){
//     std::string res = "\n";
//     Noeud * temp = this->tete;
//     while(this->tete){
//         res.append(temp->getContact().getNom());
//         res.append(" ");
//         res.append(temp->getContact().getTel());
//         res.append(" ");
//         res.append(temp->getContact().getMail());
//         res.append("\n");
//         std::cout << res<<std::endl;
//         temp = temp->getSuivant();
//     }

//     return res;
// }


#endif // LISTCONTACT
