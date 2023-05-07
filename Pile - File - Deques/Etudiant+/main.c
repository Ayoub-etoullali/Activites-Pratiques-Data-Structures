#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Contact
{
    char Nom[20];
    char Prenom[20];
    char Email[50];
    char Tel[10];
} Contact_t;

typedef struct Node_t
{
    Contact_t Contact;
    struct Node_t *Next;
} Node_t;

typedef struct List
{
    Node_t *T;
    int Nbr;
} List_t;

typedef struct Annuaire
{
    List_t Tab[27];
    int NbrTot;
} Annuaire;

void Ajouter(Annuaire *A, Contact_t Data)
{
    Node_t *New = (Node_t*)malloc(sizeof(Node_t));

    int Indice = (int)Data.Nom[0] - 65;

    New->Contact = Data;
    New->Next = A->Tab[Indice].T;

    A->Tab[Indice].T = New;

    A->Tab[Indice].Nbr++;
    A->NbrTot++;
}

void Afficher(Annuaire *A)
{
    Node_t *ptr = NULL;
int i;
    for ( i = 0; i < 26; i++)
    {

        printf("Contact %c : \n\n", i + 65);

        ptr = A->Tab[i].T;

        while (ptr != NULL)
        { // 1 -> 2 -> 3 -> NULL
            printf("Nom : %s \t Prenom : %s \t Email : %s \t Tel : %s .\n", ptr->Contact.Nom, ptr->Contact.Prenom, ptr->Contact.Email, ptr->Contact.Tel);

            ptr = ptr->Next;
        }
    }
}

void MiseAJour(Annuaire *A, char *Nom, char *Email, char *Tel)
{
    int Indice = (int)Nom[0] - 65;
    Node_t *ptr = A->Tab[Indice].T;

    while (ptr != NULL)
    {

        if (strcmp(ptr->Contact.Nom, Nom) == 0)
        {

            strcpy(ptr->Contact.Email, Email);
            strcpy(ptr->Contact.Tel, Tel);
            break;
        }
        else
            ptr = ptr->Next;
    }
}

Contact_t *RechercherNom(Annuaire *A, char *Nom)
{
    int Indice = (int)Nom[0] - 65;
    Node_t *ptr = A->Tab[Indice].T;

    while (ptr != NULL)
    {

        if (strcmp(ptr->Contact.Nom, Nom) == 0)
        {
            return &ptr->Contact;
        }
        else
            ptr = ptr->Next;
    }

    return NULL;
}

Contact_t *RechercherTel(Annuaire *A, char *Tel)
{
    Node_t *ptr = NULL;
int i;
    for ( i = 0; i < 26; i++)
    {

        ptr = A->Tab[i].T;

        while (ptr != NULL)
        { // 1 -> 2 -> 3 -> NULL

            if (strcmp(ptr->Contact.Tel, Tel) == 0)
            {
                return &ptr->Contact;
                break;
            }
            else
                ptr = ptr->Next;
        }
    }

    return NULL;
}

Contact_t *RechercherEmail(Annuaire *A, char *Email)
{
    Node_t *ptr = NULL;
int i;
    for ( i = 0; i < 26; i++)
    {

        ptr = A->Tab[i].T;

        while (ptr != NULL)
        { // 1 -> 2 -> 3 -> NULL

            if (strcmp(ptr->Contact.Email, Email) == 0)
            {
                return &ptr->Contact;
                break;
            }
            else
                ptr = ptr->Next;
        }
    }

    return NULL;
}

int main()
{
    Annuaire *A = (Annuaire*)malloc(sizeof(Annuaire));
    A->NbrTot = 0;
    
    Afficher(A);
int i;
    for ( i = 0; i < 26; i++)
    {
        A->Tab[i].T = NULL;
        A->Tab[i].Nbr = 0;
    }

    Contact_t Data1 = {"Akram", "QSJK", "Akram@gmail.com", "06877"},
              Data2 = {"Afaf", "Tani", "AfafTani@gmail.com", "06877"},
              Data3 = {"Badr", "Tani", "AfafTani@gmail.com", "06877"},
              Data4 = {"Najoua", "Tani", "AfafTani@gmail.com", "08676"},
              Data5 = {"Naoufal", "Tani", "AfafTani@gmail.com", "0987687"};

    Afficher(A);

    Ajouter(A, Data1);
    Ajouter(A, Data2);
    Ajouter(A, Data3);
    Ajouter(A, Data4);
    Ajouter(A, Data5);

    //    Afficher(A);

    //	 char Nom[10]="Afaf", Email[50] = "Changement@gmail.com", Tel[10] = "06773697";
    //
    //	 MiseAJour(A, Nom, Email, Tel );
    //
    //	 printf("\nAffichage 2 : \n\n");
    //	  Afficher(A);
    //
    //	 Contact_t *C = RechercherNom(A, "AZZ");
    //
    //	if(C==NULL) printf("Azz N exist pas!\n");
    //	else
    //	printf("Nom : %s \t Prenom : %s \t Email : %s \t Tel : %s .\n",C->Nom,C->Prenom, C->Email, C->Tel);
    //
    //    char Tal[10]= "06877";
    //    Contact_t *C2 = RechercherTel(A,Tal);
    //
    //    if(C2==NULL) printf(" 0987687 N exist pas!\n");
    //	else
    //	printf("Nom : %s \t Prenom : %s \t Email : %s \t Tel : %s .\n",C2->Nom,C2->Prenom, C2->Email, C2->Tel);
    //
    //

    Afficher(A);

    return 0;
}
