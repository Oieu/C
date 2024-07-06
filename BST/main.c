#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char sample_name[] = "Puto Cheese";
	char sample_name_del[] = "Bibingka";
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
	
	printf("Searching an item: \n");
	
	if(searchBST(T, sample_name) == 1) {
		printf("%s exists in the list\n",sample_name);
	}else{
		printf("%s does not exist in the list",sample_name);
	}
	printf("\n\n");
	
	printf("Deleting an item: %s\n\n", sample_name_del);
    T = deleteBST(&T, sample_name_del);
    printf("Inorder Traversal after deletion: \n");
    inorder(T);
    printf("\n\n");
    
	printf("Level Order Traversal:\n");
    LevelorderTrav(T);
    printf("\n");

}
