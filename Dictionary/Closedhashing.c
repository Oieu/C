#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Hashing.h"




void initCDict(CDictionary *CD) {
	int i;
	
	for(i = 0; i < SIZE; i++) {
		strcpy(CD->CDictnionary[i].fame, "");
		strcpy(CD->CDictnionary[i].address, "");
		CD->CDictnionary[i].index = EMPT;
	}
	CD->count = 0;
}

void insertCDict(CDictionary *CD, Person p) {
    int i = 0;
    int hndx, origndx;
    int table_size = SIZE * 0.65;
    hndx = hash(p.fame) % SIZE;
    origndx = hndx; 
    
    p.index = hndx;

    if (CD->count == table_size) {
    	printf("\nthreshold is reached: Table size will be expanded\n");
        resizeCDtable(CD);
    }

    while ((strcmp(CD->CDictnionary[hndx].fame, "") != 0 && strcmp(CD->CDictnionary[hndx].fame, DELETED) != 0) && CD->count != table_size) {
        hndx = (origndx + i) % SIZE;
        i++;
    }

    CD->CDictnionary[hndx] = p;
    CD->count++;
   
}




void resizeCDtable(CDictionary *CD) {
	int new_tablesize = SIZE *2;
	int i;
	
	CDictionary NCD;
	NCD.CDictnionary[new_tablesize];
	initCDict(&NCD);
	
	for (i = 0; i < SIZE; i++) {
    	if (strcmp(CD->CDictnionary[i].fame, "") != 0 && strcmp(CD->CDictnionary[i].fame, DELETED) != 0) {
            insertCDict(&NCD, CD->CDictnionary[i]);
        }
    }

    *CD = NCD;
    
    printf("\nList After Threshold is reached: \n");	
	visualizeCD(NCD);
}


void visualizeCD(CDictionary CD) {
	int i;
	
		printf("Index %2s|%2 Person %2s|%2s Address\n\n"," "," "," "," ");
	
    for (i = 0; i < SIZE; i++) {
        if(strcmp(CD.CDictnionary[i].fame, "") != 0) {
            printf("%2s %d %2s|%2s %s %2s|%2s %s\n", " ", CD.CDictnionary[i].index, " "," ", CD.CDictnionary[i].fame," "," ", CD.CDictnionary[i].address);
        }    
    }
    
    printf("\nNumber of Elements in the table: %d\n\n",CD.count);
}
