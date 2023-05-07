#include<stdio.h>
#include<stdlib.h>

//__________________struct_____________________________

typedef struct Item_t item;
typedef struct noeud_t{
	void* ptrIt;
	struct Noeud_t *next;
}noeud_t;
typedef struct List_t{
	noeud_t *tete, *queue;
	int lg;
}List_t;

//__________________fonction_____________________________


noeud_* CreerNoeud(void* ptrtIt,int lg){

noeud_t *new=(noeud*)mallo(sizeof(noeud));
void *q=malloc(lg);
mencopy(q,ptrIt,lg);
new->ptrIt=q;
new->next=NULL;
return new; 
}



// creat de la liste(à l'état vide)

list_t list_null()
{
    list_t l = {NULL, NULL, 0};
    return list;
}


//constructeur d'une liste à 1 noeud sachant l'adresse et la longueur d'un item;

List_t cree2list(void * ptrIt, size_t lg){
	
	List_t l;
	l.tete=l.queue=creernoeud(ptrit, lg);
	l.lg=1;
	return l;
}

//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
List_t cree3list(List_t l, size_t size){
	
	List_t list;
	noeud_t *curr;
	list.lg=l.lg;
	curr=l.tete;
	while(curr){
		insererQueue(&list,curr->item,size);
		curr=curr->next;
	}
	return list;
}  
void insererTete(list_t *l, void* ptrIt, size_t size){
		
		noeud_t *new=creerNoeud(ptrIt, size), *curr;
		   if(!l->tete){ // if l->tete=NULL
		   	l->tete=l->queue=new;
		   }
		   else{
		   	new->next=l->tete;
		   	l->tete=new;
		   }
		   l->lg++;
	}
	//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
	
	void insererQueue(list_t *l, void* ptrIt, size_t size){
		
		noeud_t *new=creerNoeud(ptrIt, size);
		
		   if(!l->tete) 
		   	l->tete=l->queue=new;
		   
		   else{
		   	 	l->queue->next=new;
		  	 	l->queue=new;
		   }
		  
		   l->lg++;
	}
	
		void insererMilieu(list_t *l, noeud_t *N, void* ptrIt, size_t size ){
		
		noeud_t *new=creerNoeud(ptrIt, size);
		
		   if(!N)
		   	insererTete(l,ptr,size); 
		   
		   else{
		   	noeud_t *new=creerNoeud(ptr,size);
		   	new->next=N->next;
		   	N->next=new;
		   	   if(l->queue==N) l->queue=new;
		   }
		   
		   l->lg++;
	}
	
	//opération de parcours de la liste pour appliquer un traitement T à tous les noeuds
	
	//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
	void (*T)(void *, size_t);  
	//!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
	void parcourir(list_t l,void (*T)(void *, size_t)){
		noeud_t p=l.tete;
		while(p){
			(*T)(p->ptrIt, size);
			p=p->next;
		}
	}
	
	
	
	

