#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

poly_t *creerMonome(monome_t element)
{
  poly_t *p;
  p = (poly_t *)malloc(sizeof(poly_t));
  p->element.c = element.c;
  p->element.d = element.d;
  p->suive = NULL;
  return p;
}

// -------------------- CREER UN MONOME ----------------------------

poly_t* additionPoly(poly_t* poly1, poly_t* poly2,poly_t* poly3){
  if (poly1 == NULL)
  return poly2;
  if (poly2 == NULL)
  return poly1;
  poly3 =NULL;

  monome_t element;
  element.d=0;
  poly_t* temp1 = poly1;
  poly_t* temp2 = poly2;
  while (temp1 != NULL || temp2 != NULL)
  {
    if (temp1 == NULL)
    element.c = temp2->element.c;

    if (temp2 == NULL)
    element.c = temp1->element.c;

    if (temp1 != NULL && temp2 != NULL)
    element.c = temp1->element.c + temp2->element.c;

    if (element.c != 0)
    poly3 = ajouterEnFin(poly3, element);
    if (temp1 != NULL)
    temp1 = temp1->suive;
    if (temp2 != NULL)
    temp2 = temp2->suive;
    element.d += 1;
  }
  
  
  return poly3;
}

// -------------------- ADDITION DES DEUX POLYNOMES ----------------------------

poly_t* produitPoly(poly_t* poly1, poly_t* poly2,poly_t* poly3){
  if (poly1 == NULL)
    return NULL;
  if (poly2 == NULL)
    return NULL;
  poly3 = NULL;
  poly_t* temp1 = poly1;
  while (temp1 != NULL)
  {
    poly_t* temp2 = poly2;
    while (temp2 != NULL)
    {
      monome_t element;
      element.c = temp1->element.c * temp2->element.c;
      element.d = temp1->element.d + temp2->element.d;
      poly3 = ajouterEnFin(poly3, element);
      temp2 = temp2->suive;
    }
    temp1 = temp1->suive;
  }
  return poly3;
}

// -------------------- PRODUIT DES DEUX POLYNOMES ----------------------------

poly_t *ajouterEnFin(poly_t *debut, monome_t element)
{
  poly_t *noeud = creerMonome(element);
  if (debut == NULL)
    return noeud; 
  else
  {
    poly_t *temp = debut;
    if (temp->element.d == element.d)
    {
      debut = debut->suive;
      free(temp);
      return debut;
    }
    
    poly_t *pred =NULL;
    while (temp != NULL && temp->element.d != element.d)
      { 
        pred = temp;
        temp = temp->suive;
      }
      
if (temp != NULL)
{
        temp->element.c += element.c;
        if (temp->element.c == 0)
        {
          pred->suive = temp->suive;
          free(temp);

        }
        return debut;
  }
  temp = debut;
    while (temp->suive != NULL)
      temp = temp->suive;
    temp->suive = noeud;

  }
  return debut;

    
}

// -------------------- AJOUTER UN MONOMEA LE POLYNOMIAL  ----------------------------

poly_t* supprimerPoly(poly_t*poly){
  if(poly != NULL){
    poly_t* curr;
    do
    {
    curr = poly;
    if (curr->suive == NULL)
    {
      free(curr);
      return NULL;
    }
    
    while (curr->suive->suive!=NULL)
      curr = curr->suive;
    
    poly_t *temp = curr->suive;
    curr->suive = NULL;
    free(temp);
    } while (curr != NULL);
  return poly;
  }
  return poly;
}

// -------------------- SUPPRIMER LE POLYNOME  ----------------------------


void afficherPoly(poly_t *debut)
{
  if (debut == NULL)
    printf("le polynome est vide \n");
  else
  {
    poly_t *temp = debut;
    printf("P(X) = ");
    
    while (temp != NULL)
    {
      (temp->element.c < 0 ?
            (temp->element.d != 0 ? (printf(" - %.1f X^%1d",temp->element.c*-1,temp->element.d)) : printf(" %.1f",temp->element.c*-1))
            :
            (temp->element.d != 0 ? ( printf(" + %.1f X^%1d", temp->element.c,temp->element.d)) : printf(" %.1f",temp->element.c))
            );
      temp = temp->suive;
    }

  }
}

// -------------------- AFFICHER LE POLYNOME ----------------------------
