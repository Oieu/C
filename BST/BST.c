#include<stdio.h>
#include<stdlib.h>
#include<string.h>



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

//BST in iterative
NodePtr insertBST(NodePtr *T, Product item);
NodePtr deleteBST(NodePtr *T);
void initBST(NodePtr *T);
NodePtr createNode(Product item);

//BFS
//>>>>????<<<<

//DFS traversals in recursive
void preorder(NodePtr T);
void inorder(NodePtr T);
void postorder(NodePtr T);


int main()
{
	NodePtr T;
	initBST(&T);
	
	Product items[] = {
		{"Puto",230.10,10,{22,7,2025}},
		{"Biko",150,5,{2,9,2024}},
		{"Bibingka",500,32,{1,6,2025}},
		{"Puto Cheese",100,2,{13,4,2025}},
		{"Atis",210,10,{26,8,2024}},
		{"Melon",12.2,13,{4,2,2025}}
	};
	
	T = insertBST(&T, items[0]);
	T = insertBST(&T, items[1]);
	T = insertBST(&T, items[2]);
	T = insertBST(&T, items[3]);
	T = insertBST(&T, items[4]);
	T = insertBST(&T, items[5]);
	
	printf("Inorder Traversal: \n");
	inorder(T);
	printf("\n\n");
	
	printf("Preorder Traversal: \n");
	preorder(T);
	printf("\n\n");
	
	printf("Postorder Traversal: \n");
	postorder(T);
	printf("\n\n");
	
	
}

void initBST(NodePtr *T) {
	*T = NULL;
}

NodePtr insertBST(NodePtr *T, Product item) {
	NodePtr *trav = T;
		
		if(*trav == NULL) {
			*trav = createNode(item);
		}else{
			for(; *trav != NULL; ) {
				trav = (strcmp((*trav)->item.prodName, item.prodName) < 0) ? &(*trav)->left :  &(*trav)->right;
			}
		
		}
		*trav = createNode(item);
	
		return *T;
}


NodePtr deleteBST(NodePtr *T) {
	NodePtr *trav = T;
	

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
