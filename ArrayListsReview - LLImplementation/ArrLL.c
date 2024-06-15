#include<stdio.h>
#include<stdlib.h>


typedef struct {
	char fname[20];
	char lname[20];
}studName;


typedef struct {
	int month;
	int year;
}bday;

typedef struct {
	studName name;
	bday birthdate;
	int age;
}studentinfo;

typedef struct node{
	studentinfo studList;
	struct node* next;
}CRecord, *CRecordPTR;

void initArrListLL(CRecordPTR *R);
void insertFrontLL(CRecordPTR *R, studentinfo stud);
void insertRearLL(CRecordPTR *R, studentinfo stud);
void DeleteRecordLL(CRecordPTR *R, int age);
void DeleteRecordMany(CRecordPTR *R, int year);
void insertSortedLL(CRecordPTR *R, studentinfo stud);
void DisplayRecords(CRecordPTR R);

int main() {
	
	CRecordPTR SLL;
	
	initArrListLL(&SLL);
	
	
	studentinfo studs[] = {
		{{"Oieu","Nuneza"},{7,2002},22},
		{{"Auoua","Nuneza"},{9,1999},24},
		{{"Lemon","Soda"},{12,2003},20},
		{{"Orange","Juice"},{7,2012},16},
		{{"Apple","Pie"},{1,2002},22},
		{{"Rice","Cake"},{2,2001},23},
		{{"Ube","Palaman"},{8,2004},14},
		{{"Melon","Dalandan"},{10,1998},27},
		{{"Pan","Desal"},{12,1999},23},
		{{"Spanish","Orig"},{4,2014},10},
		{{"Nescafe","Original"},{5,2002},22}
	};
	
	
	printf("Insert First Link List Operations: \n");
	insertFrontLL(&SLL, studs[0]);
	insertFrontLL(&SLL, studs[1]);
	insertFrontLL(&SLL, studs[2]);
	insertFrontLL(&SLL, studs[3]);
	insertFrontLL(&SLL, studs[4]);
	DisplayRecords(SLL);
	printf("\n\n");
	
	printf("Insert Rear Link List Operations: \n");
	insertRearLL(&SLL, studs[5]);
	insertRearLL(&SLL, studs[6]);
	insertRearLL(&SLL, studs[7]);
	insertRearLL(&SLL, studs[8]);
	DisplayRecords(SLL);
	printf("\n\n");
	
	
	printf("Insert Sorted in Unsorted List Operations: \n");
	insertSortedLL(&SLL, studs[9]);
	insertSortedLL(&SLL, studs[10]);
	DisplayRecords(SLL);
	printf("\n\n");	
	
	printf("Delete Operations Link List: \n");
	//Sample age 14 is unique in the record
	DeleteRecordLL(&SLL, 14);
	DisplayRecords(SLL);
	printf("\n\n");	
	
	
		printf("Delete Operations Link List: \n");
	//Deletes all records with birthyear of 2002
	DeleteRecordMany(&SLL, 2002);
	DisplayRecords(SLL);
	printf("\n\n");	
	
	return 0;
}


void initArrListLL(CRecordPTR *R) {
	*R = NULL;
}

void insertFrontLL(CRecordPTR *R, studentinfo stud) {
	CRecordPTR temp;
	
	temp = malloc(sizeof(struct node));
	
	if(temp != NULL) {
		temp->studList = stud;
		temp->next = *R;
		*R = temp;
	}
}

void insertRearLL(CRecordPTR *R, studentinfo stud) {
	CRecordPTR temp, *trav;
	
	temp = malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->studList = stud;
		
		for(trav = R; *trav != NULL; trav = &(*trav)->next){};
		temp->next = *trav;
		*trav = temp;
		
	}
	
}

void insertSortedLL(CRecordPTR *R, studentinfo stud) {
	CRecordPTR temp, *trav;
	
	temp = malloc(sizeof(struct node));
	
	if(temp != NULL) {
		
		temp->studList = stud;
		
		for(trav = R; *trav != NULL && (*trav)->studList.age < stud.age; trav = &(*trav)->next) {}
		temp->next = *trav;
		*trav = temp;
	}
}
void DisplayRecords(CRecordPTR R) {
	CRecordPTR trav;
	
	printf("Student Records: \n");
	printf("%3sName %6s| BirthDate | Age\n"," "," ");
	for(trav = R; trav != NULL; trav = trav->next){
			printf("%s %s%4s| %d/%d%3s| %d\n", trav->studList.name.fname,trav->studList.name.lname," ", trav->studList.birthdate.month,trav->studList.birthdate.year," ", trav->studList.age);
	}
}

void DeleteRecordLL(CRecordPTR *R, int age) {
	CRecordPTR *trav, temp;
	
	for(trav = R; *trav != NULL && (*trav)->studList.age != age; trav = &(*trav)->next){}
		temp = *trav;
		*trav = temp->next;
		free(temp);
}


void DeleteRecordMany(CRecordPTR *R, int year) {
	CRecordPTR *trav, temp;
	
	for(trav = R; *trav != NULL;){
		if((*trav)-> studList.birthdate.year == year) {
			temp = *trav;
			*trav = temp->next;
			free(temp);
		}else{
		 trav = &(*trav)->next;
		}
	
	}
}
