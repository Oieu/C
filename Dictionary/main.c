#include <stdio.h>
#include <stdlib.h>

#include "Hashing.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	OPdictionary D;
	
	initDictionary(&D);
	
	Person Persons[] = {
		{"Oieu", "Cebu"},
		{"Auoua", "Manila"},
		{"Yngrydd", "Car car"},
		{"Erich", "Carmen"},
		{"Archie", "Borbon"},
		{"Clifford", "Liloan"},
		{"Rasheed", "Catmon"},
		{"Rham Joushua", "ARgao"},
		{"Jemar", "Centro"}
	};
	
	insert(&D, Persons[0]);
	insert(&D, Persons[1]);
	insert(&D, Persons[2]);
	insert(&D, Persons[4]);
	insert(&D, Persons[5]);
	insert(&D, Persons[6]);
	
	printf("List Before Threshold is reached: \n");
	visualize(D);
	printf("\n");
	
	printf("\nList After Threshold is reached: \n");
	printf("\n");
	
	insert(&D, Persons[7]);
	insert(&D, Persons[8]);
	insert(&D, Persons[8]);
	insert(&D, Persons[8]);
	insert(&D, Persons[8]);
	visualize(D);
	
	CDictionary CD;
	
	printf("\n\n For Closed hashing:\n");
	initCDict(&CD);
	insertCDict(&CD, Persons[7]);	
	insertCDict(&CD, Persons[6]);
	insertCDict(&CD, Persons[5]);
	insertCDict(&CD, Persons[4]);
	insertCDict(&CD, Persons[3]);
	insertCDict(&CD, Persons[2]);
	insertCDict(&CD, Persons[1]);
	insertCDict(&CD, Persons[1]);
	insertCDict(&CD, Persons[1]);
	insertCDict(&CD, Persons[1]);
	
	
	
	printf("List Before Threshold is reached: \n");
	visualizeCD(CD);
	printf("\n\n");
	
	return 0;
	
}
