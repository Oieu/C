#ifndef StackLinkList
#define StackLinkList

#include<stdbool.h>


typedef struct nodeLL{
	int data;
	struct node* next;
} *StackLLPtr, StackLL;


void initStackLL(StackLLPtr *s);
StackLL createStackLL();

bool stack_pushLL(StackLLPtr *s, int elem);
bool stack_popLL(StackLLPtr *s);
int stack_peekLL(StackLLPtr s);
bool isEmptyLL(StackLLPtr s);
//bool isFull(StackLLPtr s); Not applicable ?

StackLL evenStackLL(StackLLPtr *s);

void displaystackLL(StackLLPtr s);
void visualizestackLL(StackLLPtr s);


//others
//create a function that would get all even numbers and return as a
//new stack removing from the old stack 

#endif
