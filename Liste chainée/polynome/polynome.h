#ifndef __POLYNOME
#define __POLYNOME
typedef struct
{
  float c;
  int d;
} monome_t;

typedef struct poly_t
{
  monome_t element;
  struct poly_t *suive;
} poly_t;

poly_t *creerMonome(monome_t);
poly_t *ajouterEnFin(poly_t *, monome_t);
poly_t *additionPoly(poly_t *, poly_t *, poly_t *);
poly_t *produitPoly(poly_t *, poly_t *, poly_t *);
poly_t *supprimerPoly(poly_t *);
void afficherPoly(poly_t *);

#endif