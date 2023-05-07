#include <stdio.h>
#include <stdlib.h>

//__________________struct_____________________________

typedef struct Item_t item_t;
typedef struct Noeud_t
{
    int ptrIt;
    struct Noeud_t *next;
} Noeud_t;
typedef struct List_t
{
    Noeud_t *tete, *queue;
    int lg;
} List_t;

//__________________fonction_____________________________

List_t* creer_vide()
{

    List_t *L = (List_t*)malloc(sizeof(List_t));

    L->tete = NULL;
    L->queue = NULL;
    L->lg = 0;

    // Noeud_t *N=(Noeud_t*)malloc(sizeof(Noeud_t));

    return L;
}

List_t list_null()
{
    List_t L = {NULL, NULL, 0};
    return L;
}

void afficher_List(List_t *L, Noeud_t *N)
{
    N = (Noeud_t*)malloc(sizeof(Noeud_t));
    N = L->tete;

    while (N)
    {

        printf("\n data = %d ---- next data = %d \n");
        N = N->next;
    }
}

List_t* estvide(List_t *L)
{
    if (L->tete == NULL)
    {
        printf("\n la liste est vide ");
        
    }
    else
    {
        printf("\n la liste est non vide ");
        afficher_Liste(L);
    }
    return L;
}
 
List_t* inser_Debut(int p , List_t *L)
{
    Noeud_t *N1;     
    N1 = (Noeud_t *)malloc(sizeof(Noeud_t));

    N1->ptrIt = p;
    N1->next = L->tete;
    L->lg++;

    L->tete = N1;
    
    return L;
}

List_t* inser_Fin(int P , List_t *L)
{
	Noeud_t *N;

    N = (Noeud_t *)malloc(sizeof(Noeud_t));
    L->queue->next = N;
    N->ptrIt = P;
    N->next = NULL;
    L->lg++;

    L->queue = N;
    
    return L;
}


List_t* remplir_list(List_t *L)
{
    Noeud_t *N,*N1, *N2, *N3;

    N1->ptrIt = 5;
    N2->ptrIt = 10;
    N3->ptrIt = 1;

    L->tete = N1;
    N1->next = N2;
    N2->next = N3;
    
    return L;
}



void Recherche_valeur(List_t *L, int  valeur)
{
	Noeud_t *N;
    int i = 1, V_F = 0;
    while (N)
    {

        if (valeur == N->ptrIt)
        {
            printf("\n la valeur se trouve a la noeud n:%d \n", i);
            i++;
            V_F= 1;
        }

        N = N->next;
    }
    if (V_F == 0)
    {
        printf("\n la valeur ne trouve pas dans la noeud \n");
    }
}

void Trier_I2S(List_t *L)
{

    Noeud_t *N=(Noeud_t*)malloc(sizeof(Noeud_t));
    N = L->tete;
    int P,X;
    N->ptrIt=P;
    int i;
    for (i = 1; i <= L->lg; i++)
    {

        if (N->ptrIt < P)
        {

            // permuter
            X = P;
            P = N->ptrIt;
            N->ptrIt = X;
        }

        N = N->next;
    }
}

//____________________main_________________________

int main()
{

    List_t *L;

    creer_vide(L);
    afficher_list(L);

    list_null();
    afficher_list(L);

    L=estvide(L);


    L=inser_Fin(5, L);
    L=inser_Fin(10, L);
    L=inser_Fin(-7, L);
    L=inser_Fin(2, L);
    L=inser_Debut(1,L);

    afficher_list(L); 

    L = remplir_list(L);
    afficher_list(L);

    Recherche_valeur(L,5);
    Trier_I2S(L);

 return 0;
}
