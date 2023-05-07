#include <stdio.h>
#include <stdlib.h>

typedef struct objet_t{
	int valeur;
	struct objet_t *next;
}objet_t;

int main(){
	
	int k,i=1;
	objet_t *Objet1,*Objet2,*Objet3,*Objet4,*O;
	
	Objet1=(objet_t*)malloc(sizeof(objet_t));
	Objet2=(objet_t*)malloc(sizeof(objet_t));
	Objet3=(objet_t*)malloc(sizeof(objet_t));
	Objet4=(objet_t*)malloc(sizeof(objet_t));
	
	
	Objet1->valeur=1;
	Objet2->valeur=5;
	Objet3->valeur=7;
	Objet4->valeur=9;
	
	Objet1->next=Objet2;
	Objet2->next=Objet3;
	Objet3->next=Objet4;
	Objet4->next=NULL;
	
	printf("\n\n___________________Menu____________________\n");
	printf("(1) afficher \n");
	printf("(2) ajouter un objet a debut de liste\n");
	printf("(3) ajouter un objet a la fin de liste\n");
	printf("(4) ajouter un objet a l'interieur d'un liste\n\n");
	
	printf("Entrer le nombre favorable : \n");
	scanf("%d",&k);
	
	switch(k){
		
		case 1 : {
			printf("\n\n\n________________afficher_________________\n"); 
    
    O=Objet1;
    
    while(O!=NULL){
	   printf("la valeur de l'objet n%d est %d \n",i,O->valeur);
	   printf("l'adresse de next objet n%d est %d \n",i,O->next);
       printf("l'adresse de l'objet n%d est %d \n\n",i,O);
	   O=O->next;
	   i++;
    }
    	break;
    }
    
    case 3 : {
    	printf("\n\n\n________________ajouter_________________\n");
    printf("\n_________________a la fin de la liste_________________\n");
    objet_t *Objet5;
    Objet5=(objet_t*)malloc(sizeof(objet_t));
    Objet4->next=Objet5;
    
    Objet5->valeur=20;
    Objet5->next=NULL;
    
    i=1;
    O=Objet1;
    while(O!=NULL){
	   printf("la valeur de l'objet n%d est %d \n",i,O->valeur);
	   printf("l'adresse de next objet n%d est %d \n",i,O->next);
       printf("l'adresse de l'objet n%d est %d \n\n",i,O);
	   O=O->next;
	   i++;
    }
			break;
		}
	
	
	case 2 : {
		printf("\n\n________________a le debut de la liste_________________\n");
    objet_t *Objet0;
    Objet0=(objet_t*)malloc(sizeof(objet_t));
    Objet0->valeur=30;
    Objet0->next=Objet1;
    
    i=0;
    O=Objet0;
    while(O!=NULL){
	   printf("la valeur de l'objet n%d est %d \n",i,O->valeur);
	   printf("l'adresse de next objet n%d est %d \n",i,O->next);
       printf("l'adresse de l'objet n%d est %d \n\n",i,O);
	   O=O->next;
	   i++;
    }
		break;
	}
	
	case 4 : {
		 printf("\n________________a l'intérieur de la liste_________________\n");
	objet_t *Objet3_;
    Objet3_=(objet_t*)malloc(sizeof(objet_t));
    Objet3_->valeur=100;
    Objet2->next=Objet3_;
    Objet3_->next=Objet3;
    
    
    
    i=1;
    O=Objet1;
    while(O!=NULL){
	   printf("la valeur de l'objet n%d est %d \n",i,O->valeur);
	   printf("l'adresse de next objet n%d est %d \n",i,O->next);
       printf("l'adresse de l'objet n%d est %d \n\n",i,O);
	   O=O->next;
	   i++;
    }
		break;
	}
}
	return 0;
}


