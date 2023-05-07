#ifndef _DIR
#define _DIR
#include <iostream>
#include <string>
#define NBLISTS 27
using namespace std;
class Contact
{
private:
    string name, phone, email;
    Contact(string, string, string );
    Contact(const Contact &);
    ~Contact() {};
    string toString() const;
    bool compare(const Contact &) const;
    bool operator<(const Contact &) const;
    void print() const;
    friend class Node;
    friend class List;
    friend class Dir;
};

class Node
{
private:
    Contact *contact;
    Node *previous, *next;
    Node(string, string, string);
    Node(const Contact &);
    ~Node();
    string toString() const;
    friend class List;
    friend void displayContact(Node*);
};

class List
{
private:
    Node *head;
    int size;

public:
    List();
    ~List();
    void add(const Contact &);
    void remove(string, string);
    Node *search(string, string) const;
    void update(string, string ,string, string);
    string toString() const;
    void print() const;
    bool isEmpty() const;
};
class Dir
{
private:
    List lists[NBLISTS];
    int size;

public:
    Dir();
    ~Dir();
    void add(string, string, string );
    void remove(string, string );
    Node *search(string, string ) const;
    void update(string, string, string, string );
    string toString() const;
    void print() const;
    bool isEmpty() const;
};

class App
{
public:
    static Dir d;
    static int run();
};
#endif
