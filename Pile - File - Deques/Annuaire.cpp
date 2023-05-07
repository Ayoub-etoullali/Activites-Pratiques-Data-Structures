#include <iostream>
#include <string>
#include <stdlib.h>
#include "Annuaire.h"

//=> class contact
Contact ::Contact(string name, string email, string phone)
{

    this->name = name;
    this->email = email;
    this->phone = phone;
}

Contact ::Contact(const Contact &v)
{

    this->name = v.name;
    this->email = v.email;
    this->phone = v.phone;
}

string Contact ::toString() const
{

    return "Name : " + this->name + "\t phone : " + this->phone + "\t email : " + this->email + "\n";
}

bool Contact ::compare(const Contact &v) const
{ // { ! x<y  ! x>y} => x==y

    return name < v.name; // name de quoi
}

// compare = operator<
bool Contact ::operator<(const Contact &v) const
{

    return name < v.name;
}

void Contact ::print() const
{
    cout << toString();
}



//=> class Node

Node ::Node(string name, string email, string phone)
{

    this->contact = new Contact(name, email, phone);
    this->next = nullptr; // NULL=nullptr
    this->previous = NULL;
}

Node ::Node(const Contact &C)
{ //il était & seul !!

    this->contact = new Contact(C);  //il était Contact(Contact)
    this->next = NULL;
    this->previous = NULL;
}

Node ::~Node()
{

    delete contact;
}

string Node ::toString() const
{

    return this->contact->toString();
}




//=>List

List ::List()
{

    head = NULL;
    size = 0;
}

/*  => ou
List :: List() : head(NULL), size(0){}
*/

List ::~List()
{

    Node *current = head;
    while (current != NULL)
    {

        head = head->next;
        delete current;
        current = head;
    }
}

void List ::add(string name, string email, string phone)
{

    size++;
    Node *added = new Node(name, phone, email);
    if (size == 0)
    {
        added->previous = (Node *)&head;
        added->next = NULL;
        head = added;
    }
    else
    {
        Node *c = head;
        while (((c->contact->name) < name) && c != NULL) // ou "<= name", alors dans ce cas là, on élimine "c=c->next;"
            c = c->next;
        if (c->next != NULL)
        {
            added->previous = c->previous;
            added->next = c;
            c->previous->next = added; // il faut ajouter "c->previous = added;" !!?
        }
        else
        {
            added->previous = c; 
            added->next = NULL;
            c->next = added;
        }
        size++;
    }
}

/*
void List ::_delete(string, string = "")
{
}

Node *List ::search(string, string = "") const
{
}

void List ::update(string, string, string, string = "") const
{
}

string List ::toString() const
{
}

void List ::print() const
{
}

bool List ::isEmpty() const
{
}
*/