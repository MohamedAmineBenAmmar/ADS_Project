#ifndef TYPES_HEADER_FILE
#define TYPES_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Types definition

typedef struct TreeNodeData
{
    char letter;
    int occurence;
    
} TreeNodeData;

typedef struct TreeNode
{
    TreeNodeData data;
    struct TreeNode* right;
    struct TreeNode* left;
} TreeNode;

typedef TreeNode* TArbre;

// defintion
// Queue
typedef struct QueueNode
{
    struct QueueNode* prev;
    TreeNode* tree_node_ptr;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
} Queue;


#endif