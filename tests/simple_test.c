#include "../dictionary/dictionary_functions.h"
#include "../tree/tree_functions.h"

int main(int argc, char **argv)
{
    TArbre dico;
    char buffer[100];
    dico = arbreConsVide();

    strcpy(buffer, "hamma");    
    dicoInsererMot(buffer, &dico);
    // dicoAfficher(dico);

    strcpy(buffer, "hammas");   
    dicoInsererMot(buffer, &dico);
    // dicoAfficher(dico);

    strcpy(buffer, "ham");
    dicoInsererMot(buffer, &dico);


    strcpy(buffer, "tom");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "tom");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "jerry");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "jerry");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "nada");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "sliman");
    dicoInsererMot(buffer, &dico);
    
    
    printf("\n ---- Display the dict ---- \n");
    dicoAfficher(dico);
    // arbreSuppr(dico);

}