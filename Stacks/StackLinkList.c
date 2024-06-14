#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkList.h"


void initStackLL(StackLLPtr *s) {
	*s = NULL;
}

StackLL createStackLL() {
	StackLL *sl;
	sl = NULL;
	
	return *sl;
}

bool stack_pushLL(StackLLPtr *s, int elem) {
	
	StackLLPtr temp;
	
	temp = malloc(sizeof(struct nodeLL));
	
	if(temp != NULL) {
		temp->data = elem;
		temp->next = *s;
		*s = temp;
	}
}

bool stack_popLL(StackLLPtr *s) {
	
	StackLLPtr temp, *trav;
	
	if(!isEmptyLL(*s)) {
		trav = s;
		
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
	
}


int stack_peekLL(StackLLPtr s) {
	return s->data;
	
}


bool isEmptyLL(StackLLPtr s) {
	return (s == NULL) ? 1 : 0;
}


StackLL evenStackLL(StackLLPtr *s) {
	
	
}

void displaystackLL(StackLLPtr s) {
	
	
}
void visualizestackLL(StackLLPtr s) { 
	
	StackLLPtr trav;
	
	for(trav = s; trav != NULL; trav = trav->next) {
		printf("%d \n", trav->data);
	}

}
