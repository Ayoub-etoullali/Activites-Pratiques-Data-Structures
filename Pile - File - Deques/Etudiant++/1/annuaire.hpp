#if !defined(ANNUAIRE)
#define ANNUAIRE
#include "listContact.hpp"

class Annuaire{
    ListeContact listes[27];
    int nbrContacts;
    public:
    Annuaire();
    void ajouter(std::string ,std::string ,std::string );
    void supprimer(std::string );
    void modifier(std::string ,std::string ,std::string );
    void getByName(std::string );
    void getByTel(std::string );
    void getByMail(std::string );
    // void afficher();
};

Annuaire::Annuaire(){
    for(int i=0;i<26;i++) this->listes[i]=ListeContact();
    this->nbrContacts=0;
}
void Annuaire::ajouter(std::string nom,std::string tel,std::string mail){
    int index = toupper(nom[0])-65;
    listes[index].ajouterContact(Contact(nom,tel,mail));
}
void Annuaire::supprimer(std::string nom){
    int index = toupper(nom[0])-65;
    listes[index].supprimerContact(nom);
}
void Annuaire::modifier(std::string nom,std::string tel,std::string mail){
    int index = toupper(nom[0])-65;
    listes[index].modifierContact(nom,Contact(nom,tel,mail));
}
void Annuaire::getByName(std::string nom){
    int index = toupper(nom[0])-65;
    Contact contact = listes[index].getContactByNom(nom);
    if(contact.getId()!=0){
        std::cout <<"Id: "<<contact.getId() <<std::endl;
        std::cout <<"Nom: "<<contact.getNom()<< std::endl;
        std::cout <<"Tel: "<<contact.getTel()<<std::endl;
        std::cout <<"Mail: "<< contact.getMail()<<std::endl;
        return;
    }
    std::cout << "contact non trouvé" << std::endl;
}
void Annuaire::getByTel(std::string tel){
    for(ListeContact list:listes){
        Contact found = list.getContactByTel(tel);
        if(found.getId()!=0){
            std::cout <<"Id: "<<found.getId() <<std::endl;
            std::cout <<"Nom: "<<found.getNom()<< std::endl;
            std::cout <<"Tel: "<<found.getTel()<<std::endl;
            std::cout <<"Mail: "<< found.getMail()<<std::endl;
            return;
        }
        std::cout << "contact non trouvé" << std::endl;
    }
}
void Annuaire::getByMail(std::string mail){
    for(ListeContact list:listes){
        Contact found = list.getContactByMail(mail);
        if(found.getId()!= 0){
            std::cout <<"Id: "<<found.getId() <<std::endl;
            std::cout <<"Nom: "<<found.getNom()<< std::endl;
            std::cout <<"Tel: "<<found.getTel()<<std::endl;
            std::cout <<"Mail: "<< found.getMail()<<std::endl;
            return;
        }
        std::cout << "contact non trouvé" << std::endl;
    }
}
    // void Annuaire::afficher(){
    //     for(ListeContact list:listes)
    //         std::cout<< list.toString() <<std::endl;
    // }

#endif // ANNUAIRE
