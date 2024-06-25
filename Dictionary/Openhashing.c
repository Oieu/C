#include<stdio.h>
#include<stdlib.h>

#define EMPTY NULL
#define DELETED "DELETED"
#define SIZE 10

typedef struct {
	char fame[20];
	char address[20];
	int index; //for visualization
	
}Person;

typedef struct node{
	Person p;
	struct node* next;
}Nodetype, *Nodeptr;

typedef struct {
	Nodeptr Dictionary[SIZE];
	int count; //Counts the actual number of records in the dictionary for resizing
}OPdictionary;


int hash(char *name);
void initDictionary(OPdictionary *D);
void insert(OPdictionary *D, Person p);
void resizedHashTable(OPdictionary *D);
void deleterec(OPdictionary *D, Person p);
void visualize(OPdictionary D);

int main()
{
	OPdictionary D;
	
	initDictionary(&D);
	
	Person Persons[] = {
		{"Apple", "Cebu"},
		{"Orange", "Manila"},
		{"Lemon", "Car car"},
		{"Star Fruit", "Carmen"}
	};
	
	insert(&D, Persons[0]);
	insert(&D, Persons[1]);
	insert(&D, Persons[2]);
	insert(&D, Persons[3]);
	insert(&D, Persons[3]);
	insert(&D, Persons[3]);
	visualize(D);
	
	
}

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
	
	if(D->count != table_threshold) {
		temp = malloc(sizeof(struct node));
	
		if(temp != NULL) {
			temp->p = p;
			temp->next = D->Dictionary[hashndx];
			D->Dictionary[hashndx] = temp;
		}		
	}else{
		resizedHashTable(D);
	}
	

	D->count++;
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
	SIZE * 2;
	
	initDictionary(D);
}
