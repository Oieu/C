#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkList.h"


void initStackLL(StackLLPtr *s) {
	*s = NULL;
}

StackLL createStackLL() {
	//Not really sure about this sir
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


StackLLPtr evenStackLL(StackLLPtr *s) {
	StackLLPtr newStackLL;
	initStackLL(&newStackLL);
	
	while(*s != NULL) {
		if((*s)->data % 2 == 0) {
			stack_pushLL(&newStackLL, (*s)->data);	
			stack_popLL(*s);
		}
	}
	
	return newStackLL;
	
}

void displaystackLL(StackLLPtr s) {
	
	StackLLPtr tempStackLL;
	initStackLL(&tempStackLL);
		
		//Displays the values in each stack and pushes them to a temporary stack for retrieval after displaying all values
		while(s != NULL) {
			printf("%d \n", s->data);
			stack_pushLL(&tempStackLL, s->data);
			stack_popLL(&s);
		}
		
		//Returns back the values in the temporary stack to the original stack after displaying 
		if(isEmptyLL(s)) {
			while(tempStackLL != NULL) {
				stack_pushLL(&s, tempStackLL->data);
				stack_popLL(&tempStackLL);
			}	
			
		}
	
	
}
void visualizestackLL(StackLLPtr s) { 
	
	StackLLPtr trav;
	
	for(trav = s; trav != NULL; trav = trav->next) {
		printf("%d \n", trav->data);
	}

}
