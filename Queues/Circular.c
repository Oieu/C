#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Queues.h"

void initCQList(CircularQ *cq) {
	cq->front = 1;
	cq->rear = 2;
	
}

void Cenq(CircularQ *cq, int data) {
	if(!CQisFull(*cq)) {
		cq->data[cq->rear] = data;
		cq->rear++;
	}else{
		printf("Queue is FULL\n");
	}
}

void Cdeq(CircularQ *cq) {
	if(!CQisEmpty(*cq)) {
		cq->front++;
	}
}

int CQisFront(CircularQ cq) {
	return ((cq.rear + 1) % MAX == cq.front) ? -1 : cq.data[cq.front];
}
bool CQisEmpty(CircularQ cq) {
	return ((cq.rear + 1) % MAX == cq.front) ? 1 : 0;
}
bool CQisFull(CircularQ cq) {
	return ((cq.rear + 2) % MAX == cq.front) ? 1 : 0;
}

void displayCQ(CircularQ cq) {
	int i;
	
	printf("\nIndex | Data\n");
	for(i = cq.front; i < cq.rear; i++) {
		printf("%2s%d %2s| %2s%d \n"," ",i," ", " ", cq.data[i]);
	}
}
