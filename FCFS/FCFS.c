#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// MAX process
#define MAX 10

typedef struct {
    int AT;
    int BT;
    int WT;
    int TT;
    int ET;
} Process;

typedef struct {
    Process P[MAX];
    int count;
    int currTime; // current time process being evauluated during execution
} ProcessL;

typedef struct node {
    Process process;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} FCFS;

void initProcessList(ProcessL *L);
void initFCFSQ(FCFS *Q);
void FCFSProcess(ProcessL *L, Process P[]);
void insertSortedProcess(ProcessL *L, Process P[]);
void enqueue_process(FCFS *Q, Process p);
void dequeue_process(FCFS *Q);
int TT_Time(Process p);
int WT_Time(Process p, int currTime);
int ET_Time(ProcessL *L);
void calculateAverages(ProcessL L);

//Helper Functions
void sampledisplay( FCFS Q);
bool isEmpty(FCFS Q);
void sampleDisplay(ProcessL L);

int main() {
    int process, i;
    ProcessL L;
    FCFS F;
    Process p[MAX];

    initProcessList(&L);
    initFCFSQ(&F);

    printf("FCFS CPU scheduling process:\n");
    printf("Enter How many process:\n ");
    scanf("%d", &process);

    for (i = 0; i < process; i++) {
        printf("Process #%d: \n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].AT);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].BT);
        printf("\n\n");
        L.count++;
    }

    FCFSProcess(&L, p);
    sampleDisplay(L);
    calculateAverages(L);

    return 0;
}

void initProcessList(ProcessL *L) {
    L->count = 0;
    L->currTime = 0;
}

void initFCFSQ(FCFS *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void FCFSProcess(ProcessL *L, Process P[]) {
    int i;
    FCFS Q;

    initFCFSQ(&Q);
    insertSortedProcess(L, P);

    for (i = 0; i < L->count; i++) {
        enqueue_process(&Q, L->P[i]);
    }

//    sampledisplay(Q);
    
    
    while (!isEmpty(Q)) {
        Process p = Q.front->process;
      
        if (L->currTime < p.AT) {
           L->currTime = p.AT;
      }
        p.ET = L->currTime + p.BT;
        p.TT = TT_Time(p);
        p.WT = WT_Time(p, L->currTime);
        L->currTime += p.BT;
	
        for (i = 0; i < L->count && L->P[i].AT != p.AT || L->P[i].BT != p.BT; i++) {}
        L->P[i] = p;
               
           
        dequeue_process(&Q);
    }
    
}


void insertSortedProcess(ProcessL *L, Process P[]) {
    int i, j, process;

    for (process = 0; process < L->count; process++) {
        for (i = 0; i < process && L->P[i].AT < P[process].AT; i++) {}

        for (j = process; j > i; j--) {
            L->P[j] = L->P[j - 1];
        }

        L->P[i] = P[process];
    }
}

void sampleDisplay(ProcessL L) {
    int i;

    for (i = 0; i < L.count; i++) {
        printf("Process #%d: \n", i + 1);
        printf("AT: %d | BT: %d | ET: %d | WT: %d | TT: %d\n", L.P[i].AT, L.P[i].BT, L.P[i].ET, L.P[i].WT, L.P[i].TT);
    }
}

void enqueue_process(FCFS *Q, Process p) {
    Node *temp = malloc(sizeof(Node));
      
	 if (temp != NULL) {
	        temp->process = p;
	        temp->next = NULL;
		
	    if (isEmpty(*Q)) {
	            Q->front = temp;
	            Q->rear = temp;
	        } else {
	            Q->rear->next = temp;
	            Q->rear = temp;
	        }
    
	}
}

void dequeue_process(FCFS *Q) {
    
	if (!isEmpty(*Q)) {
        Node *temp = Q->front;
        Q->front = Q->front->next;

        if (Q->front == NULL) {
            Q->rear = NULL;
        }

        free(temp);
    }
}

bool isEmpty(FCFS Q) {
    return Q.front == NULL && Q.rear == NULL;
}

int TT_Time(Process p) {
    return p.ET - p.AT;
}

int WT_Time(Process p, int currTime) {
    return currTime - p.AT;
}

int ET_Time(ProcessL *L) {
    return L->currTime;
}

void calculateAverages(ProcessL L) {
    int i;
    float totalWT = 0, totalTT = 0;

    for (i = 0; i < L.count; i++) {
        totalWT += L.P[i].WT;
        totalTT += L.P[i].TT;
    }

    printf("Average WT: %.2f\n", totalWT / L.count);
    printf("Average TT: %.2f\n", totalTT / L.count);
}


void sampledisplay(FCFS Q) {
    int i = 1;
    Node *current = Q.front;
    printf("\nIndex | AT\n");
    while (current != NULL) {
        printf("%2s%d %2s| %2s%d \n", " ", i, " ", " ", current->process.AT);
        i++;
        current = current->next;
    }

}


