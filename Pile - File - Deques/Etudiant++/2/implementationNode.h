#include <iostream>
#include "dir.h"

Node::Node(string name, string email, string phone = "")
{
    contact = new Contact(name, email, phone);
    next = nullptr;
    previous = nullptr;
}

Node::Node(const Contact &contact)
{
    this->contact = new Contact(contact.name, contact.email, contact.phone);
    next = nullptr;
    previous = nullptr;
}

string Node::toString() const
{
    if (contact != NULL)
    {
    return  contact->toString();
    }else
    {
        return "";
    }

}

Node::~Node()
{
    delete contact;
    next = nullptr;
    previous = nullptr;
}

void displayContact(Node *node){
    std::cout << "les information du contact a chercher sont : \n" << std::endl;
    std::cout << node->toString() << std::endl;
};


