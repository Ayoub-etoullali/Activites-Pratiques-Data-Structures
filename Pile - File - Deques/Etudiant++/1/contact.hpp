#if !defined(CONTACT)
#define CONTACT
#include <string>

class Contact{
    int id;
    std::string tel,nom,email;
    public:
    Contact();
    Contact(std::string ,std::string ,std::string );
    std::string getTel();
    std::string getMail();
    std::string getNom();
    int getId();
    void setTel(std::string);
    void setMail(std::string);
    void setNom(std::string);
};

Contact::Contact(){ 
    this->id=rand(); 
    this->tel="";
    this->nom="";
    this->email="";
}
Contact::Contact(std::string nom,std::string tel,std::string mail){
    this->id=rand();
    this->tel=tel;
    this->nom=nom;
    this->email=mail;
}
std::string Contact::getTel(){
    return this->tel;
}
std::string Contact::getMail(){
    return this->email;
}
std::string Contact::getNom(){
    return this->nom;
}
int Contact::getId(){
    return this->id;
}
void Contact::setTel(std::string tel){
        this->tel=tel;
}
void Contact::setMail(std::string mail){
        this->email=mail;
}
void Contact::setNom(std::string nom){
        this->nom=nom;
}
#endif // CONTACT
