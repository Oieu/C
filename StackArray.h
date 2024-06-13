#ifndef StackArray
#define StackArray

#include<stdbool.h>


#define MAX 20

typedef struct {
	int data[MAX];
	int top;
} StackArrayList;

void initStack(StackArrayList *s);
StackArrayList createStack();

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);
bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s);

void display(StackArrayList s);
void visualize(StackArrayList s);


//others
//create a function that would get all even numbers and return as a
//new stock removing from the old stack 

#endif
