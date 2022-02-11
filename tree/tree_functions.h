#ifndef TREE_FUNCTIONS_HEADER_FILE
#define TREE_FUNCTIONS_HEADER_FILE

#include "types.h"

/* -------------------------------------------------------*/ 
/* Primitives de gestion des arbres */ 
/* -------------------------------------------------------*/ 
TArbre arbreConsVide(void); 
int arbreEstVide(TArbre a); 
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd); 
char arbreRacineLettre(TArbre a); 
int arbreRacineNbOcc(TArbre a); 
TArbre arbreFilsGauche(TArbre a); 
TArbre arbreFilsDroit(TArbre a); 
void arbreSuppr(TArbre a); 
/* -------------------------------------------------------*/

#endif