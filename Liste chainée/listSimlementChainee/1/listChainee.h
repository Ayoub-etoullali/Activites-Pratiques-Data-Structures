#include <stdio.h>
#include <stdlib.h>
#include "listSimplementChainee.h"

noeud_t *creeNoeud(int valeur)
{
  noeud_t *p;
  p = (noeud_t *)malloc(sizeof(noeud_t));
  p->valeur = valeur;
  p->suive = NULL;
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
      while (temp->suive != NULL && temp->valeur != element)
        temp = temp->suive;
      if (temp->suive != NULL)
      {
        noeud->suive = temp->suive;
        temp->suive = noeud;
      }
    }
  }
  return debut;
}

// -------------------- AJOUTER UN NOEUD AVANT UN ELEMNT ----------------------------

void supprimerAuDebut(noeud_t **debut)
{
  if (*debut)
  {
    noeud_t *temp = *debut;
    *debut = (*debut)->suive;
    free(temp);
  }
}

// -------------------- SUPPRIMER AU DEBUT ----------------------------

void supprimerEnFin(noeud_t **debut)
{
  if (*debut != NULL)
  {
    noeud_t *temp = *debut;
    noeud_t *temp1;
    while (temp->suive->suive != NULL)
      temp = temp->suive;
    temp1 = temp->suive;
    temp->suive = NULL;
    free(temp1);
  }
}

// -------------------- SUPPRIMER A LA FIN ----------------------------

void supprimerApreElement(noeud_t **debut, objet_t element)
{
  if (*debut != NULL)
  {
    noeud_t *temp1;
    if ((*debut)->valeur == element)
    {
      temp1 = (*debut)->suive;
      (*debut)->suive = (*debut)->suive->suive;
    }
    else
    {
      noeud_t *temp = *debut;
      while (temp->suive->suive != NULL && temp->suive->valeur != element)
        temp = temp->suive;
      if (temp->suive->suive != NULL)
      {
        temp1 = temp->suive;
        temp->suive = temp->suive->suive;
      }
    }
    free(temp1);
  }
}

// -------------------- SUPPRIMER APRES UN ELEMNT ----------------------------

void supprimeravantElement(noeud_t **debut, objet_t element)
{
  if (*debut != NULL)
  {
    noeud_t *temp1;
    if ((*debut)->suive->valeur == element)
    {
      temp1 = *debut;
      (*debut) = (*debut)->suive;
    }
    else
    {
      noeud_t *temp = *debut;
      noeud_t *pred = NULL;
      while (temp->suive->suive != NULL && temp->suive->valeur != element)
      {
        pred->suive = temp;
        temp = temp->suive;
      }
      if (temp->suive->suive != NULL)
      {
        temp1 = temp;
        pred->suive = temp->suive;
      }
    }
    free(temp1);
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
      printf("%d -->", temp->valeur);
      temp = temp->suive;
    }
  }
}

// -------------------- AFFICHER LES ELEMENTS DE LA LIST ----------------------------
