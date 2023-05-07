#include <stdio.h>
#include <stdlib.h>
#include "listChainee.h"
#include <unistd.h>
int main(int argc, char const *argv[])
{
  int nbr;
  int valeur;
  int choix;
  int element;
  noeud_t *list = NULL;

  // ---------------- DECLARATION --------------------------

  do
  {
    printf("le nbr des elements a entrer : ");
    scanf("%d", &nbr);
  } while (nbr < 0);

  for (int i = 0; i < nbr; i++)
  {
    printf("entez la valeur Numero %d: ", i + 1);
    scanf("%d", &valeur);
    list = ajouterEnFin(list, valeur);
  }

  // ---------------- INITIALISATION --------------------------

  do
  {
    system("clear");
    printf("1) ajouter au debut ...\n");
    printf("2) ajouter en fin ...\n");
    printf("3) ajouter apres un element ...\n");
    printf("4) ajouter avant un element ...\n ");
    printf("5) supprimer au debut ...\n");
    printf("6) supprimer en fin ...\n");
    printf("7) supprimer apres un element ...\n");
    printf("8) supprimer avant un element ...\n ");
    printf("9) afficher les elments de la list ...\n ");
    printf("10) quiter le programme ...\n ");
    printf("entrez votre choix ? ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
      printf("entez la avleur a ajouter ");
      scanf("%d", &valeur);
      list = ajouterAuDebut(list, valeur);
      break;
    case 2:
      printf("entez la avleur a ajouter ");
      scanf("%d", &valeur);
      list = ajouterEnFin(list, valeur);
      break;
    case 3:
      printf("entez la avleur a ajouter ");
      scanf("%d", &valeur);
      printf("apres quel element vous voulez ajouter ");
      scanf("%d", &element);
      list = ajouterApreElement(list, valeur, element);
      break;
    case 4:
      printf("entez la avleur a ajouter ");
      scanf("%d", &valeur);
      printf("apres quel element vous voulez ajouter ");
      scanf("%d", &element);
      list = ajouteravantElement(list, valeur, element);
      break;
    case 5:

      supprimerAuDebut(&list);
      break;
    case 6:
      supprimerEnFin(&list);
      break;
    case 7:
      printf("entez l'element ");
      scanf("%d", &element);
      supprimerApreElement(&list, element);
      break;
    case 8:
      printf("entez l'element ");
      scanf("%d", &element);
      supprimeravantElement(&list, element);
      break;
    case 9:
      printf("\n ");
      afficherList(list);
      printf("NULL\n ");
      getchar();
      getchar();
      break;
    case 10:
      printf("\nMERCI .......");
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
