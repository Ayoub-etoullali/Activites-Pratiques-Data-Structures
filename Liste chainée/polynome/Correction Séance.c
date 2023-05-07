#include<stdlib.h>
#include<stdio.h>

//declaration des types

typedef struct noeud{
	int degree;  //element
	double coeff; //element
	struct noeud *suivant;
}noeud;

typedef struct liste{
	noeud *tete, *queue;
	int longueur;
}liste;

noeud* creernoueud (int degree, double coeff){
	noeud *N;
	N=(noeud*)malloc(sizeof(noeud)); 
	N->degree=degree;
	N->coeff=coeff;
	N->suivant=NULL;
	return N;
}
// construction d'une liste vide

void creerliste(liste *l)
{
	l->tete=l->queue=NULL; 
	l->longueur=0;
}
	//ou bien
	/*
	liste creerliste()
	{
		liste l={null,null,0};
		return l;
	}
*/

//nsertion monome
void inserer_monome(int degree, double coeff, liste *l){
	noeud *n;
	//null
   if(l->tete==NULL){
   	l->queue=n;
   	l->longueur=1;
   }	
   //degre moins (tete)
	else if(degree<=l->tete->degree){
		n->suivant=l->tete;
		l->tete=n;
		l->longueur++;
	}
	//degre plus (queue)
	else {
		noeud *tmp=l->tete;
		while(tmp->suivant!=NULL && tmp->suivant->degree<degree) tmp=tmp->suivant;
		
		n->suivant=tmp->suivant;
		if(tmp->suivant==NULL) l->queue=n;
		tmp->suivant=n;
		l->longueur++;	
		}
		
		/*
		//insertion avant tmp (between)
		noeud *tmp=l->tete;
		while(tmp->degree=degree) tmp=tmp->suivant;
		
		tmp->suivant=n;
		n->suivant=tmp->suivant;
		l->longueur++;
		
		*/
		
		
	
	void deriver(void *p, size_t size){
		//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
		noeud_t *pt=(monome_t*)p; 
		//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
		pt->coef *= pt->deg;
		pt->deg--;
	}
	
	void primitive(void *p, size_t size){
		//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
		noeud_t *pt=(monome_t*)p; 
		//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
		pt->deg++;
		pt->coef /= pt->deg;
	}
		
	}
	
	//-----------------------------------------------------------------------------
	
	int main(){
		
	}
