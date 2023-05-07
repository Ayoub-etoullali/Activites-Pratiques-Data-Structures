#include <stdio.h>
#include <stdlib.h>
#include "listDoublementChainee.h"

noeud_t *creeNoeud(int valeur)
{
  noeud_t *p;
  p = (noeud_t *)malloc(sizeof(noeud_t));
  p->valeur = valeur;
  p->suive = NULL;
  p->pred = NULL;
  return p;
}

// -------------------- CREE UN NOEUD ----------------------------

noeud_t *ajouterAuDebut(noeud_t *debut, int valeur)
{
  noeud_t *noeud = creeNoeud(valeur);
  if (debut == NULL)
    debut = noeud;
  else
  {
    noeud->suive = debut;
    debut->pred = noeud;
    debut = noeud;
  }
  return debut;
}

// -------------------- AJOUTER UN NOEUD AU DEBUT ----------------------------

noeud_t *ajouterEnFin(noeud_t *debut, objet_t valeur)
{
  noeud_t *noeud = creeNoeud(valeur);
  if (debut == NULL)
    debut = noeud;
  else
  {
    noeud_t *temp = debut;
    while (temp->suive != NULL)
      temp = temp->suive;
    temp->suive = noeud;
    noeud->pred = temp;
  }
  return debut;
}

// -------------------- AJOUTER UN NOEUD A LA FIN ----------------------------

noeud_t *ajouterApreElement(noeud_t *debut, objet_t valeur, objet_t element)
{
  noeud_t *noeud = creeNoeud(valeur);
  if (debut == NULL)
    debut = noeud;
  else
  {
    noeud_t *temp = debut;
    while (temp != NULL && temp->valeur != element)
      temp = temp->suive;
    if (temp != NULL)
    {
      noeud->suive = temp->suive;
      if (temp->suive != NULL)
        temp->suive = temp->suive->pred = noeud;
      noeud->pred = temp;
      temp->suive = noeud;
    }
  }
  return debut;
}

// -------------------- AJOUTER UN NOEUD APRES UN ELEMNT ----------------------------

noeud_t *ajouteravantElement(noeud_t *debut, objet_t valeur, objet_t element)
{
  noeud_t *noeud = creeNoeud(valeur);
  if (debut == NULL)
    debut = noeud;
  else
  {
    if (debut->valeur == element)
    {
      noeud->suive = debut;
      debut = noeud;
    }
    else
    {
      noeud_t *temp = debut;
      while (temp != NULL && temp->valeur != element)
        temp = temp->suive;
      if (temp->suive != NULL)
      {
        noeud->suive = temp;
        if (temp->suive != NULL)
          temp->pred->suive = noeud;
        noeud->pred = temp->pred;
        temp->pred = noeud;
      }
    }
  }
  return debut;
}

// -------------------- AJOUTER UN NOEUD AVANT UN ELEMNT ----------------------------

void supprimerAuDebut(noeud_t **debut)
{
  if (*debut != NULL)
  {
    noeud_t *temp = *debut;
    *debut = (*debut)->suive;
    (*debut)->pred = NULL;
    free(temp);
  }
}

// -------------------- SUPPRIMER AU DEBUT ----------------------------

void supprimerEnFin(noeud_t **debut)
{
  if ((*debut)->suive != NULL)
  {

    noeud_t *temp = *debut;
    while (temp->suive != NULL)
      temp = temp->suive;
    temp->pred->suive = NULL;
    free(temp);
  }
  else
  {
    free(*debut);
    *debut = NULL;
  }
}

// -------------------- SUPPRIMER A LA FIN ----------------------------

void supprimerApreElement(noeud_t **debut, objet_t element)
{
  if ((*debut)->suive != NULL)
  {
    noeud_t *temp = *debut;
    while (temp->suive->suive != NULL && temp->valeur != element)
      temp = temp->suive;
    if (temp->suive != NULL)
    {
      noeud_t *temp1 = temp->suive;
      if (temp->suive->suive != NULL)
        temp->suive->suive->pred = temp;
      temp->suive = temp->suive->suive;
      free(temp1);
    }
  }
}

// -------------------- SUPPRIMER APRES UN ELEMNT ----------------------------

void supprimeravantElement(noeud_t **debut, objet_t element)
{
  if ((*debut)->suive != NULL)
  {
    noeud_t *temp = *debut;
    while (temp->suive != NULL && temp->valeur != element)
      temp = temp->suive;
    if (temp!= NULL)
    {
      noeud_t *temp1 = temp->pred;
      if (temp->pred->pred != NULL)
        temp->pred->pred->suive = temp;
      temp->pred = temp->pred->pred;
      free(temp1);
    }
  }
}

// -------------------- SUPPRIMER AVANT UN ELEMENT ----------------------------

void afficherList(noeud_t *debut)
{
  if (debut == NULL)
    printf("la list est vide \n");
  else
  {
    noeud_t *temp = debut;
    while (temp != NULL)
    {
      printf("%d-->", temp->valeur);
      temp = temp->suive;
    }
  }
}

// -------------------- AFFICHER LES ELEMENTS DE LA LIST ----------------------------
