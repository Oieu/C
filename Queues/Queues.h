#ifndef Queues
#define Queues

#include<stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}*Node;

typedef struct {
	Node front;
	Node rear;
}QList;



void initQ(QList *L);
void enqueue(QList *L, int data);
void dequeue(QList *L);
bool isEmpty(QList L);
void displayQueue(QList *L);
void sampledisplay(QList L);

#endif
