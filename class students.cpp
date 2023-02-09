#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class students{
	
	private :
		int nbrCourant;
		int mtr;
		string nom;
		float notes[2];
	
	public :
		students();
		students student(string);
		students(students &);
		string getNom();
		int getMtr();
		float getNote(int);
		float getAverage();
		void setNote(float,int);
		void setNome(string);
		int compare(students);
		void print();
		
};

students::students(){
	
	nbrCourant=1;  mtr=0;  nom="";  notes[2]={};
}

students::students(students &s){
	
	nbrCourant=s.nbrCourant;  mtr=s.mtr;  nom=s.nom;  for(int i;i<2;i++) notes[i]=s.notes[i];
}

students students::student(string s){
	
	students st;
	float a;
	st.nom=s;    
	for(int i=0;i<2;i++){
		
		cin >> a;
		st.notes[i]=a;
	}
	return st;
}		

string students::getNom(){
	
	cout << "le nom : " << nom << endl;
	return nom;
}

int students::getMtr(){
	
	cout << "la matricule : " << mtr << endl;
	return mtr;
}

float students::getNote(int i){
	
	cout << "la note de " << i << " : " << notes[i] << endl;
	return notes[i];
}

float students::getAverage(){
	
	float s=0;
	for(int i=0;i<2;i++){
		
		s=s+notes[i]; 
	}
	return s/2;
}

void students::setNote(float n,int k){
	
	for(int i=0;i<2;i++){
		
		if(i==k)   notes[i]=n; 
	}
}

void students::setNome(string s){
	
	nom=s;
}
		
int students::compare(students s){
	
	if(nbrCourant==s.nbrCourant &&  mtr==s.mtr && nom==s.nom &&  notes[1]==s.notes[1])   return 1; // for(int i;i<20;i++) 
	return 0;
}

void students::print(){
	
	cout << "le nombre courant : " << nbrCourant << "\t le matruicule : " << mtr << "\t le nom : " << nom << "\t notes[1] = " << notes[1] << endl;
}



int main(){
	
	students a,b,w;
	a.print();
	w=b.student("Radouan");
	w.print();
	a=w;
	
	cout << "\n Matricule de a : " << a.getMtr() << endl;
	cout << "\n a : Note[1] = " << a.getNote(1) << endl;
	cout << "\n Moyenne de a : " << a.getAverage() << endl;
	
	a.setNote(20,0);  
	cout << "\n a : Note[0] = " << a.getNote(0) << endl;
	string s;   
	cout << "Entrer un nom : ";
	cin >> s;
	a.setNome(s);
	    
	cout << "\n Comparaison entre l'etudiant a et w : " << a.compare(w) << endl;
	cout << "\n Moyenne de a : " << a.getAverage() << endl;
	b=w;
	a.print();
	b.print();
	return 0;
}
