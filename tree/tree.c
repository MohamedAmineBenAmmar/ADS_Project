#include "tree_functions.h"
#include "queue_functions.h"

TArbre arbreConsVide(){
    TArbre root = NULL;
    return root;
}

int arbreEstVide(TArbre a){
    // 1 if the tree is empty
    // 0 else

    int returnValue;
    (a == NULL) ? (returnValue = 1) : (returnValue = 0);
    return returnValue;
}

TArbre arbreCons(char c, int n, TArbre fg, TArbre fd){
    TArbre root = (TreeNode*) malloc(sizeof(TreeNode));

    root->right = fd;
    root->left = fg;
    root->data.letter = c;
    root->data.occurence = n;

    return root;
}

char arbreRacineLettre(TArbre a){
    return a->data.letter;
} 

int arbreRacineNbOcc(TArbre a){
    return a->data.occurence;
}

TArbre arbreFilsGauche(TArbre a){
    return a->left;
}

TArbre arbreFilsDroit(TArbre a){
    return a->right;
}

void arbreSuppr(TArbre a){
    Queue tree_queue;
    TreeNode* tmp_tree_node_ptr = NULL;

    init_queue(&tree_queue);

    enqueue(&tree_queue, a);
    while (isEmpty(tree_queue) == 0)
    {
        tmp_tree_node_ptr = dequeue(&tree_queue);

        if (tmp_tree_node_ptr->right != NULL){
            enqueue(&tree_queue, tmp_tree_node_ptr->right);
        }

        if (tmp_tree_node_ptr->left != NULL) {
            enqueue(&tree_queue, tmp_tree_node_ptr->left);
        }
        
        free(tmp_tree_node_ptr);
        // printf("letter is : %c\n", tmp_tree_node_ptr->data.letter);
        // if (tmp_tree_node_ptr->data.letter == '\0'){
        //     printf("pst \n");
        // }
    }

}
