#ifndef Hashing
#define Hashing 


#include<stdio.h>
#include<stdlib.h>

#define EMPTY NULL
#define DELETED "DELETED"
#define SIZE 10
#define EMPT -1
#define DEL -99



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

typedef struct {
	Person CDictnionary[SIZE];
	int count;
}CDictionary;




//Hash Function
int hash(char *name);

//Functions for Open Hashing

void initDictionary(OPdictionary *D);
void insert(OPdictionary *D, Person p);
void resizedHashTable(OPdictionary *D);
void deleterec(OPdictionary *D, Person p);
void visualize(OPdictionary D);

//Functions for Closed hashing

void initCDict(CDictionary *CD);
void insertCDict(CDictionary *CD, Person p);
void resizeCDtable(CDictionary *CD);
void visualizeCD(CDictionary CD);


#endif
