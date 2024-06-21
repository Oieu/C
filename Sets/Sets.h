#ifndef Sets
#define Sets


#define bits 8
#define MAX 10


typedef struct {
	unsigned char data;
}SET;

typedef struct {
	int setA[MAX];
	int setB[MAX];
}SETarr;


SET unionSet(SET  A, SET B);
SET intersection(SET A, SET B);
void addSetval(SET *A, int data);
void DeleteSetval(SET * A, int data);


void initSet(SET *set);
void DisplaySET(SET set);

//Could not finish on time 

void insertinSet(SETarr *set, int data);
SETarr unionSetarr(SETarr *A, SETarr *B);
SETarr intersectionarr(SETarr *A, SETarr *B);
void displaySet(SETarr set);


#endif
