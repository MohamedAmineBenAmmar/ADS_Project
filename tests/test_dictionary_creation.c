#include "../dictionary/dictionary_functions.h"
#include "../tree/tree_functions.h"
#include "../file_manager/dico.h"

#include <time.h>

int main(int argc, char **argv)
{
    TArbre dico;
    char buffer[100];
    char filename[100];
    char input[256];

    // Calling srand at the start of the program
    // so I can get different values for multiple function calls
    srand(time(NULL));

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

    printf("\n");
    printf("Test for word existence: ");
    scanf("%s", input);
    printf("%d", dicoNbOcc(input, dico));

    printf("\nTest for deleting all the entries to the dict: ");
    printf("\nBefor calling the delete function root letter == %c", arbreRacineLettre(dico));
    arbreSuppr(dico);
    printf("\nAfter calling the delete function root letter == %c \n", arbreRacineLettre(dico));

}