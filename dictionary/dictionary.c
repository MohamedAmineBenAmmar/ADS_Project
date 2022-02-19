#include "dictionary_functions.h"
#include "../tree/tree_functions.h"

/* Display the tree */
void display_tree(TArbre a, char word[], char from, char *pOperation)
{
    if (a != NULL)
    {
        if (from == 'L')
        {
            // if (a->data.letter == '\0')
            if (arbreRacineLettre(a) == '\0')
            {
                // Display the word
                // printf("word: %s / Occurence: %d\n", word, a->data.occurence);
                printf("word: %s / Occurence: %d\n", word, arbreRacineNbOcc(a));
            }
            else
            {
                strncat(word, &(a->data.letter), 1);
            }
        }
        else
        {
            if (*pOperation == 'N')
            {
                word[strlen(word) - 1] = arbreRacineLettre(a);
            }
            else
            {
                strncat(word, &(a->data.letter), 1);
            }
        }

        *pOperation = 'N';
        // display_tree(a->left, word, 'L', pOperation);
        display_tree(arbreFilsGauche(a), word, 'L', pOperation);

        if (arbreRacineLettre(a) != '\0')
        {
            word[strlen(word) - 1] = '\0';
        }

        display_tree(arbreFilsDroit(a), word, 'R', pOperation);
    }
    else
    {
        if (from == 'L')
        {
            *pOperation = 'C';
        }
    }
}

void dicoAfficher(TArbre a)
{
    char word[256];
    char operation = 'N';
    // Init the word variable
    word[0] = '\0';
    display_tree(a, word, 'L', &operation);
}

/* -------------------------- */

/* Insert new word in the tree */
void dicoInsererMot(char mot[], TArbre *pa)
{
    TArbre ptr, parent, newNode;
    int letter_existence_flag;
    int letter_sort_flag;
    int newNodeFlag = 0;

    // Check if the tree is empty or not
    if (*pa == NULL)
    {
        *pa = arbreCons(mot[0], 0, NULL, NULL);
        ptr = *pa;
        for (size_t i = 1; i <= strlen(mot); i++)
        {
            ptr->left = arbreCons(mot[i], 0, NULL, NULL);
            ptr = ptr->left;
        }

        // Setting the 1st word occurence to one
        ptr->data.occurence = 1;
    }
    else
    {
        parent = NULL;
        ptr = *pa;
        for (size_t i = 0; i <= strlen(mot); i++)
        {
            letter_existence_flag = 0;
            letter_sort_flag = 0;
            if (ptr == NULL)
            {
                // Directly adding characters
                newNode = arbreCons(mot[i], 0, NULL, NULL);
                parent->left = newNode;
                parent = newNode;
                ptr = parent->left;

                // Here we added new  node
                (newNodeFlag == 0) && (newNodeFlag = 1);
            }
            else
            {
                if (mot[i] == ptr->data.letter)
                {
                    parent = ptr;
                    ptr = ptr->left;
                }
                else
                {
                    if (mot[i] > ptr->data.letter)
                    {
                        // Going down in the right subbranch until we hit a leaf
                        // or we find the character that we want to insert
                        while (arbreEstVide(ptr->right) == 0)
                        {
                            parent = ptr;
                            ptr = ptr->right;

                            // Check if we hit a character that we already have
                            if (arbreRacineLettre(ptr) == mot[i])
                            {
                                letter_existence_flag = 1;
                                break;
                            }
                            else
                            {
                                if (arbreRacineLettre(ptr) > mot[i])
                                {
                                    letter_sort_flag = 1;
                                    break;
                                }
                            }
                        }

                        if (letter_existence_flag == 1)
                        {
                            parent = ptr;
                            ptr = parent->left;
                        }
                        else
                        {
                            if (letter_sort_flag == 1)
                            {
                                newNode = arbreCons(mot[i], 0, NULL, ptr);
                                parent->right = newNode;
                                parent = newNode;
                                ptr = parent->left;

                                // Here we added new  node
                                (newNodeFlag == 0) && (newNodeFlag = 1);
                            }
                            else
                            {
                                newNode = arbreCons(mot[i], 0, NULL, NULL);
                                ptr->right = newNode;
                                parent = newNode;
                                ptr = parent->left;

                                // Here we added new  node
                                (newNodeFlag == 0) && (newNodeFlag = 1);
                            }
                        }
                    }
                    else
                    {
                        newNode = arbreCons(mot[i], 0, NULL, ptr);

                        // Here we added new  node
                        (newNodeFlag == 0) && (newNodeFlag = 1);

                        // Check if we are going to apply changes on the root of the tree
                        if (parent == NULL)
                        {
                            // Update the root of the tree
                            *pa = newNode;
                        }
                        else
                        {
                            parent->left = newNode;
                        }

                        parent = newNode;
                        ptr = parent->left;
                    }
                }
            }
        }

        // After inserting the word we've gotta update the \0 occurence
        (newNodeFlag == 1) ? (parent->data.occurence = 1) : (parent->data.occurence++);
    }
}

/* -------------------------- */

/* Check if a word exists in the tree */
int find(char word[], int index, TArbre a)
{
    // printf("\nthe letter to check: %c\n", word[index]);
    if (word[index] == '\0' && arbreRacineLettre(a) == '\0')
    {
        return 1;
    }
    else
    {
        if (arbreEstVide(a) == 1 || index == strlen(word))
        {
            return 0;
        }
        else
        {
            if (word[index] == arbreRacineLettre(a))
            {
                return (find(word, ++index, arbreFilsGauche(a)));
            }
            else
            {
                return (find(word, index, arbreFilsDroit(a)));
            }
        }
    }
}

int dicoNbOcc(char mot[], TArbre a)
{
    int index = 0;
    int word_existence_flag = find(mot, index, a);

    

    return word_existence_flag;
}

/* -------------------------*/

/* Calculating the number of words within the dictionary  */
void calculate_words(TArbre a, char option, int *p_result)
{
    if (arbreEstVide(a) == 0)
    {
        calculate_words(arbreFilsGauche(a), option, p_result);

        // Check if the current node is a leaf
        if (arbreRacineLettre(a) == '\0')
        {
            if (option == 'D')
            {
                (*p_result)++;
            }
            else
            {
                (*p_result) += arbreRacineNbOcc(a);
            }
        }

        calculate_words(arbreFilsDroit(a), option, p_result);
    }
}

int dicoNbMotsDifferents(TArbre a)
{
    int result = 0;
    calculate_words(a, 'D', &result);

    return result;
}

int dicoNbMotsTotal(TArbre a)
{
    int result = 0;
    calculate_words(a, 'S', &result);

    return result;
}
/* -------------------------*/