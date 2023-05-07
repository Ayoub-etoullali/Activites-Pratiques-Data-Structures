#ifndef __LIST_DOUBLEMENT_CHAINEE
#define __LIST_DOUBLEMENT_CHAINEE
typedef int objet_t;
typedef struct noeud
{
  objet_t valeur;
  struct noeud *suive;
  struct noeud *pred;
} noeud_t;

noeud_t *creeNoeud(int);
noeud_t *ajouterAuDebut(noeud_t *, int);
noeud_t *ajouterEnFin(noeud_t *, objet_t);
noeud_t *ajouterApreElement(noeud_t *, objet_t, objet_t);
noeud_t *ajouteravantElement(noeud_t *, objet_t, objet_t);
void supprimerAuDebut(noeud_t **);
void supprimerEnFin(noeud_t **debut);
void supprimerApreElement(noeud_t **debut, objet_t element);
void supprimeravantElement(noeud_t **debut, objet_t element);
void afficherList(noeud_t *);
#endif