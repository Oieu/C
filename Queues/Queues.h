#ifndef Queues
#define Queues

#include<stdbool.h>

#define MAX 10

typedef struct node{
	int data;
	struct node *next;
}*Node;

typedef struct {
	Node front;
	Node rear;
}QList;

//Definition for Circular Array

typedef struct {
	int data[MAX];
	int front;
	int rear;
}CircularQ;



//for LinkList Queue
void initQ(QList *L);
void enqueue(QList *L, int data);
void dequeue(QList *L);
bool isEmpty(QList L);
void displayQueue(QList *L);
void sampledisplay(QList L);
int isFront(QList L);

//for Circular Arrays

void Cenq(CircularQ *cq, int data);
void Cdeq(CircularQ *cq);
void initCQList(CircularQ *cq);
int CQisFront(CircularQ cq);
bool CQisEmpty(CircularQ cq);
bool CQisFull(CircularQ cq);
void displayCQ(CircularQ cq);
#endif
