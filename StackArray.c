#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"


void initStack(StackArrayList *s) {
  s->top = 0;
}

StackArrayList createStack() {
	StackArrayList s;
	s.top = 0;
	
	return s;
}

bool stack_push(StackArrayList *s, int elem) {
	s->data[s->top++] = elem;
}

bool stack_pop(StackArrayList *s) {
	s->top--;
}

int stack_peek(StackArrayList s) {
	return s.data[s.top-1];
}


bool isEmpty(StackArrayList s) {
	return s.top = 0;
}

bool isFull(StackArrayList s) {
	return s.top = MAX; 
}

void display(StackArrayList s) {
	StackArrayList newStack;
	newStack.top = 0;
	
}

void visualize(StackArrayList s) {
	int i;
	
	for(i = 0; i < s.top; i++) {
		printf("index%d: %d \n", i+1, s.data[i]);
	}
	
	printf("\n");
	printf("TOP %d", stack_peek(s));
}
