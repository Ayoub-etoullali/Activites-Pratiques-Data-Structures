#include "dir.h"
#include <string.h>

Contact::Contact(string name, string email, string phone = 0)
{
    this->name = name;
    this->email = email;
    this->phone = phone;
}

Contact::Contact(const Contact &contact)
{
    this->name = contact.name;
    this->email = contact.email;
    this->phone = contact.phone;
};

string Contact::toString() const
{
    
    return " \n name = " + this->name + " \n email = " + this->email + "\n phone  = " + this->phone + "\n------------------------------\n";
};

bool Contact::compare(const Contact &contact) const
{
    return (this->email == contact.email) ? true: false;
}

bool Contact::operator<(const Contact &contact) const
{
    return ((this->name < contact.name) == -1)? true : false;
}
void Contact::print() const
{
    std::cout << toString();
}