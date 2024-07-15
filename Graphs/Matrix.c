#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node {
    char vertex;
    struct node* next;
} ADJL, *ADJLPtr;

typedef struct {
    int adjMatrix[MAX][MAX];
} ADJM;

typedef struct {
    int numvertix;
    ADJM matrix;
    ADJLPtr list[MAX];
} Graph;

void createGraph(Graph *G);
void AddEdge(Graph *G, char v1, char v2);
void displayGraphMatrix(Graph G);
void displayADJList(Graph G);

int main()
{
    Graph G;
    createGraph(&G);

    AddEdge(&G, 'A', 'B');
    AddEdge(&G, 'A', 'C');
    AddEdge(&G, 'A', 'D');
    AddEdge(&G, 'B', 'E');
    AddEdge(&G, 'B', 'C');
    AddEdge(&G, 'B', 'D');
	AddEdge(&G, 'C', 'A');
	AddEdge(&G, 'C', 'B');
	AddEdge(&G, 'C', 'D');
	AddEdge(&G, 'D', 'A');
	AddEdge(&G, 'D', 'C');
	AddEdge(&G, 'D', 'B');
	AddEdge(&G, 'E', 'D');
	AddEdge(&G, 'E', 'D');

    printf("Display for Adjacency matrix: \n");
    displayGraphMatrix(G);
    printf("\n\n");
    printf("Display for Adjacency List:\n");
    displayADJList(G);

    return 0;
}

void createGraph(Graph *G) {
    G->numvertix = MAX;
    int row, col, i;

    for (row = 0; row < MAX; row++) {
        for (col = 0; col < MAX; col++) {
            G->matrix.adjMatrix[row][col] = 0;
        }
    }

    for (i = 0; i < MAX; i++) {
        G->list[i] = NULL;
    }
}

void AddEdge(Graph *G, char v1, char v2) {
    // Convert characters to indices
    int index1 = v1 - 'A';
    int index2 = v2 - 'A';

    // For adjacency list
    ADJLPtr temp = malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->vertex = v2;
        temp->next = G->list[index1];
        G->list[index1] = temp;
    }

    // For adjacency matrix
    G->matrix.adjMatrix[index1][index2] = 1;
    G->matrix.adjMatrix[index2][index1] = 1;
}

void displayGraphMatrix(Graph G) {
    int row, col;
    printf("   A B C D E\n");
    for (row = 0; row < MAX; row++) {
        printf("%c: ", 'A' + row);
        for (col = 0; col < MAX; col++) {
            printf("%d ", G.matrix.adjMatrix[row][col]);
        }
        printf("\n");
    }
}

void displayADJList(Graph G) {
    ADJLPtr trav;
    int i;

    for (i = 0; i < MAX; i++) {
        printf("vertex %c: ", 'A' + i);
        for (trav = G.list[i]; trav != NULL; trav = trav->next) {
            printf("%c -> ", trav->vertex);
        }
        printf("NULL\n");
    }
}
