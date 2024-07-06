#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "BST.h"


void initBST(NodePtr *T) {
	*T = NULL;
}

NodePtr insertBST(NodePtr *T, Product item) {
	NodePtr *trav = T;
		
		if(*trav == NULL) {
			*trav = createNode(item);
		}else{
			for(; *trav != NULL; ) {
				trav = (strcmp(item.prodName, (*trav)->item.prodName) < 0) ? &(*trav)->left :  &(*trav)->right;
			}
		
		}
		*trav = createNode(item);
	
		return *T;
}


NodePtr deleteBST(NodePtr *T, char *Name) {
	NodePtr *trav,temp, *minNode;
	
	//Searches for the node to be deleted
	for(trav = T; *trav != NULL && strcmp((*trav)->item.prodName,Name) != 0;) {
		trav = (strcmp(Name,(*trav)->item.prodName) < 0) ? &(*trav)->left: &(*trav)->right;
	}
	
	//case 1 if node is a leaf
	if((*trav)->left == NULL && (*trav)->right == NULL) {
		temp = *trav;
		*trav = NULL;
		free(temp);
	}else{
		//case 2 if node has 1 child
		if((*trav)->left == NULL) {
			temp = *trav;
			*trav = temp->right;
			free(temp);
		}else if((*trav)->right == NULL) {
			temp = *trav;
			*trav = temp->left;
			free(temp);
		}else{
		//case 3 if node has 2 children get the min of the right side of the node to be deleted Note: only gets the leftmost of the right side of the node to be deleted thoooo :>>>>
		for(minNode = &(*trav)->right; (*minNode)->left != NULL; minNode = &(*minNode)->left){}
	   (*trav)->item = (*minNode)->item;
	   temp = *minNode;
	   *minNode = temp->right;
	   free(temp);
	 	}
	   
 	}
	
    
    return *T;


}



NodePtr createNode(Product item) {
	NodePtr temp = malloc(sizeof(Nodetype));
	
	temp->item = item;
	temp->left = temp->right = NULL;
	
	return temp;
}

void inorder(NodePtr T) {
	if(T != NULL) {
		inorder(T->left);
		printf("Product Name: %s\n", T->item.prodName);
		printf("Product Price: %.2f\n", T->item.prodPrice);
		printf("Quantity: %d\n", T->item.prodQty);
		printf("Expiry Date: %d/%d/%d\n\n",T->item.expDate.day,T->item.expDate.month, T->item.expDate.year);
		inorder(T->right);
	}
}

void preorder(NodePtr T) {
	if(T != NULL) {
		printf("Product Name: %s\n", T->item.prodName);
		printf("Product Price: %.2f\n", T->item.prodPrice);
		printf("Quantity: %d\n", T->item.prodQty);
		printf("Expiry Date: %d/%d/%d\n\n",T->item.expDate.day,T->item.expDate.month, T->item.expDate.year);
		preorder(T->left);
		preorder(T->right);
	}
}

void postorder(NodePtr T) {
	if(T!= NULL) {
		postorder(T->left);
		postorder(T->right);
		printf("Product Name: %s\n", T->item.prodName);
		printf("Product Price: %.2f\n", T->item.prodPrice);
		printf("Quantity: %d\n", T->item.prodQty);
		printf("Expiry Date: %d/%d/%d\n\n",T->item.expDate.day,T->item.expDate.month, T->item.expDate.year);
	}
}

bool searchBST(NodePtr T, char *Name) {
    bool RetVal = false;
	NodePtr trav;
	
	for(trav = T; trav != NULL && strcmp(trav->item.prodName,Name) != 0;){
		trav = (strcmp(Name, trav->item.prodName) < 0) ? trav->left: trav->right;
	}
	if(trav != NULL) {
		RetVal = true;
	}
   	
   	
   	
    return RetVal; 
}

void LevelorderTrav(NodePtr T) {
    Queue Q;
    initQueue(&Q);
    NodePtr visited_Node;

    enQueue(&Q, T);

    while (!isEmpty(Q)) {
        visited_Node = deQueue(&Q);
       	
       	printf("Product Name: %s\n", visited_Node->item.prodName);
	    printf("Product Price: %.2f\n", visited_Node->item.prodPrice);
	    printf("Quantity: %d\n", visited_Node->item.prodQty);
	    printf("Expiry Date: %d/%d/%d\n\n", visited_Node->item.expDate.day, visited_Node->item.expDate.month, visited_Node->item.expDate.year);

        if ( visited_Node->left != NULL) {
            enQueue(&Q,  visited_Node->left);
        }
        if ( visited_Node->right != NULL) {
            enQueue(&Q,  visited_Node->right);
        }
    }
}


void initQueue(Queue *Q) {
	Q->front = Q->rear = NULL;
}


void enQueue(Queue *Q, NodePtr treeNode) {
    Node temp = malloc(sizeof(struct nodeQ));
    if (temp != NULL) {
        temp->treeNode = treeNode;
        temp->next = NULL;
    }

    if (isEmpty(*Q)) {
        Q->front = Q->rear = temp;
    } else {
        Q->rear->next = temp;
        Q->rear = temp;
    }
}

NodePtr deQueue(Queue *Q) {
    Node temp;
    NodePtr treeNode;
	
	if (!isEmpty(*Q)) {
        	if(Q->front == Q->rear) {
	    	temp = Q->front;
	    	treeNode = temp->treeNode;
	    	free(temp);
	    	Q->front = NULL;
	    	Q->rear = NULL;
		}else{
			temp = Q->front;
			treeNode = temp->treeNode;
			Q->front = temp->next;
			free(temp);
		}
    }else{
    	printf("Queue is empty\n");
	}
  

  
    return treeNode;
}
bool isEmpty(Queue Q) {
	return Q.front == NULL && Q.rear == NULL;
}


