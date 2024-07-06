#ifndef BST
#define BST


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



typedef struct {
	int day, month, year;
}Date;

typedef struct {
	char prodName[20]; 
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node {
	Product item;
	struct node *left, *right;
}Nodetype, *NodePtr;

typedef struct nodeQ {
    NodePtr treeNode;
    struct nodeQ* next;
} *Node;

typedef struct {
	Node front;
	Node rear;
}Queue;


//BST in iterative
NodePtr insertBST(NodePtr *T, Product item);
NodePtr deleteBST(NodePtr *T, char *Name);

//BFS lEVEL ORDER TRAVERSAL OF THE TREE
void LevelorderTrav(NodePtr T);

//utililty or helper functions for BST
bool searchBST(NodePtr T, char *Name);
void initBST(NodePtr *T);
NodePtr createNode(Product item);

//queue in LL implementation
void initQueue(Queue *Q);
void enQueue(Queue *Q, NodePtr treeNode);
NodePtr deQueue(Queue *Q);
bool isEmpty(Queue Q);


//DFS traversals in recursive
void preorder(NodePtr T);
void inorder(NodePtr T);
void postorder(NodePtr T);




#endif
