#include <stdio.h>
#include <stdlib.h>
#include "implementationPolynome.h"
#include <unistd.h>
int main(int argc, char const *argv[])
{
  int nbr;
  monome_t m;
  m.d = 0;
  int choix;
  int element;
  poly_t *poly = NULL;

  // ---------------- DECLARATION --------------------------

  do
  {
    printf("le nbr des elements a insere : ");
    scanf("%d", &nbr);
  } while (nbr < 0);

  for (int i = 0; i < nbr; i++)
  {
    printf("entrez le coefficient %d: ", i + 1);
    scanf("%f", &m.c);
    poly = ajouterEnFin(poly, m);
    m.d = m.d+1;
  }


  // ---------------- INITIALISATION --------------------------




  do
  {
    poly1:
    system("cls");
    printf("1) ajouter un monome ...\n");
    printf("2) afficher polynome ...\n");
    printf("3) les operation sur le polynome ...\n");
    printf("4) quiter ...\n");
    printf("entrez votre choix ? ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
       printf("entrez le coefficient : ");
    scanf("%f", &m.c);
    printf("entrez la degre : ");
    scanf("%d", &m.d);
    poly = ajouterEnFin(poly, m);
      break;
       case 2:
       
        afficherPoly(poly);
        printf("\n");
        getchar();
        getchar();
      break;
       case 3:
       printf("l'ajoute d'un autre polynome ..\n");
    do
    {
      printf("entrer le nbr des elements a jouter : ");
      scanf("%d", &nbr);
    } while (nbr < 0);
    poly_t *poly1= NULL;
    monome_t m1;
    m1.d = 0;
    for (int i = 0; i < nbr; i++)
    {
      printf("entrez le Coefficient %d: ", i + 1);
      scanf("%f", &m1.c);
      poly1 = ajouterEnFin(poly1, m1);
      m1.d = m1.d+1;
    }
        do
  {
    system("cls");
    poly_t * poly3 = NULL;
    printf("1) l'addition des deux polynomes ...\n");
    printf("2) poduit des deux polynomes ...\n");
    printf("3) afficher les deux polynomes...\n");
    printf("4) quiter ...\n");

    printf("entrez votre choix ? ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
      poly3 = additionPoly(poly, poly1, poly3);
        afficherPoly(poly3);
        printf("\n");
        getchar();
        getchar();
        poly3 = supprimerPoly(poly3);
      break;
       case 2:
        poly3 = produitPoly(poly, poly1, poly3);
        afficherPoly(poly3);
        printf("\n");
        getchar();
        getchar();
        poly3 = supprimerPoly(poly3);
      break;
       case 3:
        printf("poly 1 : ");
        afficherPoly(poly);
        printf("\n");
        printf("poly 2 : ");
        afficherPoly(poly1);
        printf("\n");
        getchar();
        getchar();
      break;
       case 4:
      goto poly1;
      break;
    default:
      printf("erreur de saisie ...\n");
      break;
    }
  } while (1);
      break;
      case 4:
      printf("merci ......\n");
      getchar();
      getchar();
      return 0;
      break;
    default:
      printf("erreur de saisie ...\n");
      break;
    }
  } while (1);

  // ---------------- TRAITEMENT ----------------------------

  return 0;
}
