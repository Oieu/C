#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"
#include "StackLinkList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	StackArrayList s;
	
  initStack(&s);
    
    stack_push(&s, 1);
    stack_push(&s, 2);
    stack_push(&s, 12);
    stack_push(&s, 14);
    stack_push(&s, 15);
	
	printf("for Stacks Array Implementation: \n");
	visualize(s);
	
	printf("\n\n");
	printf("Display of Stack:\n");
	 display(s);
	 
	 printf("\n\n");
	 printf("New stack containing even Numbers:\n");
	 
	 StackArrayList newStack;
	 newStack = evenStack(&s);
	 
	 visualize(newStack);
	
	printf("\n\nStack Link List Implementation: \n\n");
	
	StackLLPtr sll;
	
	initStackLL(&sll);
	
	stack_pushLL(&sll, 2);
	stack_pushLL(&sll, 5);
	stack_pushLL(&sll, 8);
	stack_pushLL(&sll, 14);
	
	printf("Sample Visualizer for Stacks Link List Implementation: \n");
	visualizestackLL(sll);
	printf("\n");
	
	printf("Current Top of Stack: %d", stack_peekLL(sll));
	printf("\n\n");
	
	stack_popLL(&sll);
	printf("Sample Visualizer for Stacks Link List Implementation after POP operation: \n");
	visualizestackLL(sll);
	printf("\n");
	
	printf("Current Top of Stack: %d", stack_peekLL(sll));
	printf("\n\n");
	
	return 0;
}
