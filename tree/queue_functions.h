#ifndef QUEUE_FUNCTIONS_HEADER_FILE
#define QUEUE_FUNCTIONS_HEADER_FILE

#include "types.h"

/* -------------------------------------------------------*/ 
/* Managing the queue */ 
/* -------------------------------------------------------*/ 
void init_queue(Queue* queue_ptr);
void enqueue(Queue* queue_ptr, TreeNode* tree_node_ptr);
TreeNode* dequeue(Queue* queue_ptr);
int isEmpty(Queue queue);
/* -------------------------------------------------------*/

#endif