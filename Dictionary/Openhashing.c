#include<stdio.h>
#include<stdlib.h>

#include "Hashing.h"




int hash(char *name) {
	int index = 0,i;
	
	for(i = 0; name[i] != '\0'; i++) {
		index = index + name[i];
	}
	
	return index % SIZE;
}

void initDictionary(OPdictionary *D) {
	int i;
	
	for(i = 0; i < SIZE; i++) {
		D->Dictionary[i] = NULL;
	}
	D->count = 0;
}

void insert(OPdictionary *D, Person p) {
	Nodeptr temp;
	int hashndx;
	int table_threshold = SIZE * 0.6;
	
	hashndx = hash(p.fame);
	p.index = hashndx;
//	printf("%d",p.index);

	if(D->count == table_threshold) {
		resizedHashTable(D);
	}
	
		
		temp = malloc(sizeof(struct node));
	
		if(temp != NULL) {
			temp->p = p;
			temp->next = D->Dictionary[hashndx];
			D->Dictionary[hashndx] = temp;
			D->count++;
		}		
	


}


void visualize(OPdictionary D) {
	int i;
	Nodeptr trav;
	
	printf("Index %2s|%2 Person %2s|%2s Address\n\n"," "," "," "," ");
	
	for(i = 0; i < SIZE; i++) {
		for(trav = D.Dictionary[i]; trav != NULL; trav = trav->next) {
			printf("%2s %d %2s|%2s %s %2s|%2s %s\n", " ", trav->p.index, " "," ", trav->p.fame," "," ", trav->p.address);
		}
	}
	
	printf("\nTotal Number of records in the table: %d\n",D.count);

}
void resizedHashTable(OPdictionary *D) {
	
	int i;
	Nodeptr trav;
	int newtable_Size = 0;
	OPdictionary ND;
	
	SIZE * 2;
		
	initDictionary(&ND);
	
	for(i = 0; i < SIZE; i++) {
		for(trav = D->Dictionary[i]; trav != NULL; trav = trav->next){
			insert(&ND, trav->p);
			free(trav);
		}
	}
	
	*D = ND;

}


