#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct node{
	int vertex;
	struct node* next;
}ADJL, *ADJLPtr;

typedef struct{
	int adjMatrix[MAX][MAX];
}ADJM;

typedef struct {
	int numvertix;
	ADJM matrix;
	ADJLPtr list[MAX];
}Graph;


void createGraph(Graph *G);
void AddEdge(Graph *G, int v1, int v2);
void displayGraphMatrix(Graph G);
int main()
{
	Graph G;
	createGraph(&G);
	
	AddEdge(&G, 0, 1);
	AddEdge(&G, 0, 2);
	AddEdge(&G, 0, 3);
	AddEdge(&G, 1, 4);
	AddEdge(&G, 1, 5);
	AddEdge(&G, 2, 4);
	
	displayGraphMatrix(G);
	
	
	
	return 0;
}

void createGraph(Graph *G) {
	G->numvertix = MAX;
	int row,col,i;
	
	for(row = 0; row < MAX; row++){
		for(col = 0; col < 5; col++) {
			G->matrix.adjMatrix[row][col] = 0;
		}
	}
	
	for(i = 0; i < MAX; i++) {
		G->list[i] = NULL;
	}
	
}

void AddEdge(Graph *G, int v1, int v2) {
	
	G->matrix.adjMatrix[v1][v2] = 1;
	G->matrix.adjMatrix[v2][v1] = 1;
}


void displayGraphMatrix(Graph G) {
	int row,col;
	for(row = 0; row < MAX; row++) {
		printf("row%d: ",row +1);
		for(col = 0; col < MAX; col++) {
			printf("%d ", G.matrix.adjMatrix[row][col]);
		}
		printf("\n");
	}
}
