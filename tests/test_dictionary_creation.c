#include "../dictionary/dictionary_functions.h"
#include "../tree/tree_functions.h"
#include "../file_manager/dico.h"

int main(int argc, char **argv)
{
    TArbre dico;
    char buffer[100];
    char filename[100];

    // Init the tree
    dico = arbreConsVide();

    // Extract a word from the file
    piocherMot(buffer, "./data/dico.txt");
    dicoInsererMot(buffer, &dico);
    
    piocherMot(buffer, "./data/dico.txt");
    dicoInsererMot(buffer, &dico);

    piocherMot(buffer, "./data/dico.txt");
    dicoInsererMot(buffer, &dico);

    piocherMot(buffer, "./data/dico.txt");
    dicoInsererMot(buffer, &dico);

    dicoAfficher(dico);
    // printf("The word extracted from the file: %s\n", buffer);



    
   
}