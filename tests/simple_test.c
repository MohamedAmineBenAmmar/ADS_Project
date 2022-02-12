#include "../dictionary/dictionary_functions.h"
#include "../tree/tree_functions.h"

int main(int argc, char **argv)
{
    TArbre dico;
    char buffer[100];
    char input[100];
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

    printf("\nStats:\n");
    printf("The number of different words: %d\n", dicoNbMotsDifferents(dico));
    printf("The number of all words: %d\n", dicoNbMotsTotal(dico));

    printf("\nType a string to search for its existance within the tree: ");
    scanf("%s", input);

    printf("The string: %s ---> existence value: %d\n", input, dicoNbOcc(input, dico));


    printf("\nTest access to the data in the memory adress (before free) : \n");
    printf("%c\n", arbreRacineLettre(dico));
    
    printf("\nTrying to delete all the tree entries :D \n");
    arbreSuppr(dico);
    printf("Tree state (empty): %d\n", arbreEstVide(dico));

    printf("\nTest access to the data in the memory adress (after free) : \n");
    printf("%c\n", arbreRacineLettre(dico));
}