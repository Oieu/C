#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Queues.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	QList QL;
	initQ(&QL);
	
	enqueue(&QL, 1);
	enqueue(&QL, 2);
	enqueue(&QL, 3);
	enqueue(&QL, 4);
	enqueue(&QL, 5);
	
	printf("Display of Queue: \n");
	displayQueue(&QL);
	printf("\n\n");
	printf("Sample Display of Queue: \n");
	sampledisplay(QL);
		
	return 0;
}
