#include <stdio.h>
#include <stdlib.h>
#include "Sets.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	SET A,B,C;
	
	addSetval(&A, 1);
	addSetval(&A, 2);
	addSetval(&A, 5);
	addSetval(&A, 7);

	addSetval(&B, 3);	
	addSetval(&B, 5);	
	addSetval(&B, 2);	
	addSetval(&B, 4);	
	addSetval(&B, 6);	
	
	printf("Current Sets:\n");
	
	printf("Set A: ");
	DisplaySET(A);
	printf("Set B: ");
	DisplaySET(B);
	
	printf("\n");
	
	printf("Union of Set A and Set B\n");
	printf("Set C: ");
	C = unionSet(A, B);
	DisplaySET(C);
	printf("\nIntersection of Set A and Set B\n");
	printf("Set C: ");
	C = intersection(A, B);
	DisplaySET(C);
	return 0;
}
