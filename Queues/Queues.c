#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Queues.h"



void initQ(QList *L) {
	L->front = NULL;
	L->rear = NULL;	
}
void enqueue(QList *L, int data) {
	Node temp;
	
	temp = malloc(sizeof(struct node));
	
	if(temp != NULL) {
		temp->data = data;
		temp->next = NULL;
	}
	
	if(isEmpty(*L)) {
		L->front = temp;
		L->rear = temp; 
	}else{

		temp->next = L->rear;
		L->rear->next = temp;
		L->rear = temp;
	}
	
}
void dequeue(QList *L) {
	Node temp;
	
	if(!isEmpty(*L)) {
		
		if(L->front == L->rear) {
			temp = L->front;
			free(temp);
			L->front = NULL;
			L->rear = NULL;	
		}else{
			temp = L->front;
			L->front = temp->next;
			free(temp);	
		}
		
	}	
	
}
bool isEmpty(QList L) {
	return L.front == NULL && L.rear == NULL;
}
void displayQueue(QList *L) {
	QList temp;
 	initQ(&temp);
 	
 	while(!isEmpty(*L)) {
 		enqueue(&temp, L->front->data);
 		printf("%d \n", temp.rear->data);
 		dequeue(L);
	 }
	 
	 while(!isEmpty(temp)) {
	 	enqueue(L, temp.front->data);
	 	dequeue(&temp);
	 }
}


void sampledisplay(QList L) {
	int i = 1;
	printf("\nIndex | Data\n");
	while(L.front != L.rear) {
		printf("%2s%d %2s| %2s%d \n"," ",i," ", " ", L.front->data);
		i++;
		L.front = L.front->next;
	}
}

int isFront(QList L) {
	return (isEmpty(L)) ? -1 : L.front->data;
}
