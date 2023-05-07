#include <stdio.h>
#include <stdlib.h>


typedef struct  Noeud_t{
    int data;
    struct Noeud_t *next;
}noeud_t;

typedef struct {
    struct Noeud_t *tete,*queue;
    int longueur;
}list_t;


//_______________________________________


void afficher(list_t list)
{
    noeud_t *p = list.tete;
    printf("Liste (");
    while (p)
    {
        printf(" %d   ", p->data);
        p = p->next;
    }
    printf(")\n");
}

list_t list_vide()
{
    list_t list = {NULL, NULL, 0};
    return list;
}

/*
int estVide(list_t l)
{
    return !l.longueur || !l.tete || !l.queue;
}
*/
 
void est_Vide(list_t l)
{
   if(!l.tete) printf(" \nla liste est vide \n");
   else {
       printf("\nla liste est non vide \n");
   }
   afficher(l);
}

list_t insererTete(list_t *list, int x)
{
    noeud_t *new = (noeud_t *)malloc(sizeof(noeud_t));
    new->data = x;
    if (!list->tete){
        list->queue=list->queue = new;
        list->longueur=1;
    }
        
    new->next = list->tete;
    list->tete = new;
    list->longueur++; 
    return *list;
}


list_t insererQueue(list_t *list, int x)
{
    noeud_t *p,*new = (noeud_t *)malloc(sizeof(noeud_t));
    new->data = x;
    new->next=NULL;
    
    if (!list->tete){
        list->tete=list->queue = new;
        list->longueur=1;
    }
    
    p=list;
    
	while(p->next){ // while(p) ??
    	p=p->next;
	} 
  
	p->next=new;
  
	list->queue=new;
	list->longueur++;
    return *list;
}


list_t insererMilieu(list_t *list, noeud_t N ,int x)
{
    noeud_t *new = (noeud_t *)malloc(sizeof(noeud_t)),*p=list->tete;

    new->data = x;
    
    if (!list->tete){
        list->tete=list->queue = new;
        list->longueur=1;
    }
        if (list->queue==&N){
		
        	*list=insererQueue(&list, x);
		}
		else{
			
			while(p->data!=N.data){
    	p=p->next;
		}
	
	new->next=p->next;
    p->next=new;
    
    list->longueur++; 
			
		}
    
    return *list;
}


list_t supprimerOccur(list_t list, int x)
{
    noeud_t *p = list.tete, *pp = NULL;
    while (p) // 
    {
        if (p->data == x)
        {
            if (pp == NULL)
            { 
                list.tete = p->next;
                if (list.longueur == 0)
                    list.queue = NULL;
            } 
            else
            {
                pp->next = p->next;
                if (pp->next == NULL)
                    list.queue = pp;
            }
            free(p);
            list.longueur--;
            break;
        }
        pp = p;
        p = p->next;
    }
    return list;
}

/*
liste_t supprimerOccur (liste_t liste,object_t x, int(*cmp)(object_t,object_t)){
    noeud_t *p=liste.tete, *pp=NULL;
    while(p!=NULL){
        if((*cmp)(p->data,x)) {

 }

    }
    return liste;
}
 */
 
list_t supprimerToutesOccur(list_t list, int x) 
{
    noeud_t *p = list.tete, *pp = NULL;
    while (p)
    {
        if (p->data == x)
        {
            if (!pp)
            {
                list.tete = p->next;
                if (list.longueur == 0)
                    list.queue = NULL;
            }
            else
            {
                pp->next = p->next;
                if (!pp->next)
                    list.queue = pp;
            }
            // free(p);
            list.longueur--;
            pp = p;
            p = pp->next;
        }
        else
        {
            pp = p;
            p = p->next;
        }
    }
    return list;
}

//________________________________________________



int main() {
	
    list_t list;
    noeud_t N2,N5;
    
    list=list_vide();

    est_Vide(list);
    		
    		
	printf("\ninsererTete\n");
    list=insererTete(&list, 39);
    list=insererTete(&list, 20);
    list=insererTete(&list, 30);
    list=insererTete(&list, 39);
    list=insererTete(&list, 17);
    list=insererTete(&list, 50);
    list=insererTete(&list, 39);
    list=insererTete(&list, 45);
    afficher(list);
    
    printf("\ninsererQueue\n");
    list=insererQueue(&list, 1);
    list=insererQueue(&list, -7);
    list=insererQueue(&list, -9);
    afficher(list);
    
    printf("\ninsererMilieu\n"); 
    N2.data=20;
    N5.data=50;
	list=insererMilieu(&list,N2,0);
	list=insererMilieu(&list,N5, 100);
	afficher(list);
	
	printf("\nsupprimerOccur\n");
    list=supprimerOccur(list, -7);
    afficher(list);
    
    printf("\nsupprimerToutesOccur\n");
    list=supprimerToutesOccur(list, 39);
    afficher(list);

    return 0;
}




