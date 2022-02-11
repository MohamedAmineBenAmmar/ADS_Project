#include "queue_functions.h"

void init_queue(Queue* queue_ptr){
    queue_ptr->head = NULL;
    queue_ptr->tail = NULL;
}

void enqueue(Queue* queue_ptr, TreeNode* tree_node_ptr){    
    QueueNode* tmp_queue_node = (QueueNode*)malloc(sizeof(QueueNode));

    tmp_queue_node->tree_node_ptr = tree_node_ptr;
    tmp_queue_node->prev = NULL;
    tmp_queue_node->next = queue_ptr->tail;

    if (queue_ptr->tail == NULL) {
        queue_ptr->head = tmp_queue_node;
    } else {
        queue_ptr->tail->prev = tmp_queue_node;
    }
    
    queue_ptr->tail = tmp_queue_node;
}

TreeNode* dequeue(Queue* queue_ptr){
    TreeNode* returnValue = queue_ptr->head->tree_node_ptr;
    QueueNode* queue_head = queue_ptr->head;

    queue_ptr->head = queue_ptr->head->prev;
    if (queue_ptr->head == NULL){
        queue_ptr->tail = NULL;
    } else {
        queue_ptr->head->next = NULL;
    }
    

    free(queue_head);
    return returnValue;
}

int isEmpty(Queue queue){
    if (queue.head == NULL && queue.tail == NULL){
        return 1;
    } else {
        return 0;
    }
}