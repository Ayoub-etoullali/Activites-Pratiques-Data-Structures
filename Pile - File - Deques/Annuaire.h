#ifndef _DIR
	#define _DIR
	#include<iostream>
	#include<string>
	#define NBLISTS 27

	using namespace std;
	
	class Contact{
	private:
	public:
		string name,phone,email;
		Contact(string,string,string="");
		Contact(const Contact&); //à quoi sert ?
		~Contact(){}
		string toString()const;
		bool compare(const Contact &)const; // j'ai pas compris? nom par nom? alphabétique?
		bool operator<(const Contact &)const; //à quoi sert ? pourquoi?
		void print()const;
		friend class Node;
		friend class List;
	};

	class Node{
	private:
		Contact *contact;
		Node *previous,*next;
		Node(string,string,string="");
		Node(const Contact &); //à quoi sert ?
		~Node();
		string toString()const;
		friend class List;
	};

	class List{
	private:
		Node *head;
		int size;
	public:
		List();
		~List();
		void add(string,string,string); //void add(const Contact&);
		void _delete(string,string="");
		Node* search(string,string="")const;
		void update(string,string,string,string="")const; //تحديث update 
		string toString()const;
		void print()const;
		bool isEmpty()const;
	};
	class Dir{
	private:
		List lists[NBLISTS];
		int size;
	public:
		Dir();
		~Dir();
		void add(string,string,string="");
		void _delete(string,string="");
		Node* search(string,string="")const;
		void update(string,string,string,string="");
		string toString()const;
		void print()const;
		bool isEmpty()const;
	};


	//à quoi sert ?
	class App{
	public :
		static Dir d;
		static int run();
	};

#endif
