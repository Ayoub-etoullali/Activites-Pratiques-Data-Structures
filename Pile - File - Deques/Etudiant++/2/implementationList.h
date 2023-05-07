#include "dir.h"
#include <iostream>

List::List() : head(nullptr), size(0){};

List::~List()
{
    delete head;
    size = 0;
};

void List::add(const Contact &contact)
{

    Node *node = new Node(contact);

    if (head == nullptr)
    {
        head = node;
        size++;
    }
    else
    {
        if ((contact.email < head->contact->email) == 1)
        {
            node->next = head;
            head->previous = node;
            head = node;
            size++;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && (contact.email < temp->contact->email) != 1)
            temp = temp->next;
        if (temp->next != NULL)
        {
            node->next = temp;
            if (temp->previous != NULL)
                temp->previous->next = node;
            node->previous = temp->previous;
            temp->previous = node;
            size++;
            return;
        }
        if (temp->next == NULL && (contact.email < temp->contact->email) == 1)
        {
            node->next = temp;
            if (temp->previous != NULL)
                temp->previous->next = node;
            node->previous = temp->previous;
            temp->previous = node;
        }
        else
        {
            temp->next = node;
            node->previous = temp;
        }
        size++;
    }
}
void List::remove(string name, string email = "")
{
    Contact contact(name, email, "");
    if (head->contact->compare(contact) == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node *temp = head;
    while (temp != NULL && temp->contact->compare(contact) != 1)
        temp = temp->next;
    if (temp != NULL)
    {
        Node *temp1 = temp;
        temp->previous->next = temp->next;
        if (temp->next != NULL)
            temp->next->previous = temp->previous;
        free(temp1);
        size--;
    }

}
Node *List::search(string name, string email = "") const
{
    std::cout << "/* message */" << std::endl;
    Contact contact(name, email, "");
    Node *temp = head;

    while (temp != NULL && temp->contact->compare(contact) != 1)
        temp = temp->next;
    if (temp == NULL)
    {
        std::cout << "doesn't found" << std::endl;
    }

    return temp;
}

void List::update(string searchEmail, string name, string email, string phone = "") 
{
    remove(name, searchEmail);
    Contact contact(name, email, phone);
    add(contact);
}

string List::toString() const
{
    string str = "";
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        str = str + "contact[ " + to_string(count) + " ] : " + temp->toString();
        temp = temp->next;
        count++;
    }
    return str;
}
void List::print() const
{
    std::cout << toString();
}
bool List::isEmpty() const
{
    return size == 0;
}