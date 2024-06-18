#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Queues.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	QList QL;
	initQ(&QL);
	
	enqueue(&QL, 10);
	enqueue(&QL, 23);
	enqueue(&QL, 32);
	enqueue(&QL, 4);
	enqueue(&QL, 5);
	
	printf("Display of Queue: \n");
	displayQueue(&QL);
	printf("\n\n");
	printf("Sample Display of Queue: \n");
	sampledisplay(QL);
	
	printf("\n\n");
	printf("Front Data is %d", isFront(QL));
	
	printf("\n\n");
	
	printf("Functions for Circular array implementation of Queue\n\n");
	CircularQ cq;
	
	initCQList(&cq);
	Cenq(&cq, 1);
	Cenq(&cq, 2);
	Cenq(&cq, 3);
	Cenq(&cq, 4);
	Cenq(&cq, 5);
	Cdeq(&cq);
	Cenq(&cq, 6);
	Cenq(&cq, 7);
	Cenq(&cq, 8);
	Cenq(&cq, 9); //Not inserted
	Cenq(&cq, 10); //Not inserted
	
	displayCQ(cq);
	printf("\nFront of number of the circular Queue is %d", CQisFront(cq));
	
	return 0;
}
