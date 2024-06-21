#include "Sets.h"
#include<stdio.h>

void initSet(SET *set) {
	set->data = 0;
}

SET unionSet(SET A, SET B) {
	SET retVal;
	retVal.data = A.data | B.data;
	return retVal;
}
SET intersection(SET A, SET B) {
	
	SET retVal;
	retVal.data = A.data & B.data;
	return retVal;
	
}
void addSetval(SET *A, int data) {
	
	if(data >= 0 && data < bits) {
		A->data |= (1 << data);
	}
	
}
void DeleteSetval(SET * A, int data) {
	
	if(data >= 0 && data < bits) {
		A->data &= ~(1 << data);
	}
}


void DisplaySET(SET set) {
	int i;
	
	printf("{ ");
	for(i = 0; i < bits; i++) {
		if(set.data & (1 << i)) {
			printf("%d ", i);
		}
	}
	printf("}\n");
}

