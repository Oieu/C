#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	StackArrayList s;
	
  initStack(&s);
    
    stack_push(&s, 1);
    stack_push(&s, 2);
    stack_push(&s, 12);
    stack_push(&s, 14);
    stack_push(&s, 15);
	
	printf("Sample Visualizer: \n");
	visualize(s);
	
	printf("\n\n");
	printf("Display of stack:\n");
	 display(s);
	
	return 0;
}
