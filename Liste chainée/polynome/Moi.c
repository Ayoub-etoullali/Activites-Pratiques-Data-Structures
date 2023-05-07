#include<stdio.h>
#include<stdlib.h>

typedef struct Noeud_t{
	int degre;  //element
	int coef; //element	
	struct Noeud_t *Next;
}Noeud_t;

typedef struct {
	struct Noeud_t *Tete, *Queue;
    int longueur;
}Liste_t;
		
int main(){
	

		Noeud_t *N1,*N2,*N3,*N;
				
		// creer
		N=(Noeud_t*)malloc(sizeof(Noeud_t));
		N1=(Noeud_t*)malloc(sizeof(Noeud_t));
		N2=(Noeud_t*)malloc(sizeof(Noeud_t));
		N3=(Noeud_t*)malloc(sizeof(Noeud_t));
					
					
		N1->Next=N2;
		N2->Next=N3;
		N3->Next=NULL;

     	// afficher
		N=N1;
		
		while(N){
			
		printf(" coef = %d \t degree = %d \t adresse = %d \n ",N->coef,N->degre,N->Next);
		N=N->Next;
		
		}
		
		//Afficher : P(x) = a0 + a1*X^1 + a2*X^2 + ... + an*X^n
		
		N1->coef=5; N1->degre=0;
		N2->coef=-4; N2->degre=1;
		N3->coef=2; N3->degre=2;	
		
		printf("\n  P(x) = %d x X^%d + %d x X^%d + %d x X^%d \n ",N1->coef,N1->degre,N2->coef,N2->degre,N3->coef,N3->degre);

		//Addition
		
		
		return 0;		
} 		
