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
	return s.top == 0;
}

bool isFull(StackArrayList s) {
	return s.top == MAX-1; 
}

StackArrayList evenStack(StackArrayList *s) {
	StackArrayList evenStack;
	initStack(&evenStack);
	
	
	while(s->top != 0) {
		if(stack_peek(*s) % 2 == 0) {
			evenStack.data[evenStack.top++] = stack_peek(*s);
			stack_pop(s);
		}else{
			stack_pop(s);
		}
	}
	
	return evenStack;
}

void display(StackArrayList s) {
	StackArrayList newStack;
	initStack(&newStack);
	
	while(s.top != 0) {
		printf("%d \n", stack_peek(s));
		
		newStack.data[newStack.top++] = stack_peek(s);
		
		stack_pop(&s);
	}
	
}

void visualize(StackArrayList s) {
	int i;
	printf("%3s Index : Data\n"," ");
	for(i = 0; i < s.top; i++) {
		printf("%5s %d %2s:%1s %d \n", " ",i+1, " ", " ", s.data[i]);
	}
	
	printf("\n");
	printf("TOP %d", stack_peek(s));
}
