#include <iostream>
#include "annuaire.hpp"

using namespace std;


int main(){
    Annuaire an = Annuaire();
    an.ajouter("test","2352135325","test@mail.com");
    an.ajouter("Ahmed","12351235","ahmed@mail.com");  
    an.ajouter("Ismail","1241321","ismail@mail.com");  
    an.getByMail("ahmed@mail.com"); 
    cout<<endl;
    an.getByName("Ismail"); 
    cout<<endl;
    an.getByName("test"); 
    cout<<endl;
    an.getByTel("12351235"); 
    cout<<endl;
    an.supprimer("test");
    cout<<endl;
    an.getByName("test"); 
}