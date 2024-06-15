#include<stdio.h>
#include<stdlib.h>


#define MAX 20

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

typedef struct {
	studentinfo studList[MAX];
	int studcount;
}ClassRecord;

void initArrList(ClassRecord *R);
void insertFront(ClassRecord *R, studentinfo stud);
void insertRear(ClassRecord *R, studentinfo stud);
void insertatIndex(ClassRecord *R, studentinfo stud, int index);
void DeleteRecordatIndex(ClassRecord *R, int index);
void DeleteRear(ClassRecord *R);
void InsertSorted(ClassRecord *R, studentinfo stud);
void DisplayRecords(ClassRecord R);


int main() {
	ClassRecord SR;
	
	initArrList(&SR);
	
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
	
	
	printf("Insert First Operations: \n");
	insertFront(&SR, studs[0]);
	insertFront(&SR, studs[1]);
	insertFront(&SR, studs[2]);
	insertFront(&SR, studs[3]);
	insertFront(&SR, studs[4]);
	DisplayRecords(SR);
	printf("\n\n");
	
	printf("Insert Rear Operations: \n");
	insertRear(&SR, studs[5]);
	insertRear(&SR, studs[6]);
	DisplayRecords(SR);
	printf("\n\n");
	
	printf("Insert Rear at Index Operations: \n");
	insertatIndex(&SR, studs[7], 2);
	insertatIndex(&SR, studs[8], 0);
	DisplayRecords(SR);
	printf("\n\n");
	
	printf("Insert Sorted in Unsorted List Operations: \n");
	InsertSorted(&SR, studs[9]);
	InsertSorted(&SR, studs[10]);
	DisplayRecords(SR);
	printf("\n\n");
	
	printf("Delete At Index Operation: \n");
	DeleteRecordatIndex(&SR, 2);
	DeleteRecordatIndex(&SR, 0);
	DeleteRecordatIndex(&SR, 4);
	DisplayRecords(SR);
	printf("\n\n");
	
	printf("Delete Rear: \n");
	DeleteRear(&SR);
	DeleteRear(&SR);
	DisplayRecords(SR);
	printf("\n\n");
	return 0;
}




void initArrList(ClassRecord *R) {
	R->studcount = 0;
}

void insertRear(ClassRecord *R, studentinfo stud) {
	if(R->studcount < MAX) {
		R->studList[R->studcount++] = stud;
	}
}

void insertFront(ClassRecord *R, studentinfo stud) {
	int i;
	
	if(R->studcount < MAX) {
			for(i = R->studcount; i > 0; i--) {
			R->studList[i] = R->studList[i-1];
		}	
			R->studList[0] = stud;
			R->studcount++;
	}

}
void insertatIndex(ClassRecord *R, studentinfo stud, int index) {
	int pos,i;
	
	for(pos = 0; pos < R->studcount; pos++) {
		if(pos == index) {
			for(i = R->studcount; i >= pos; i--) {
				R->studList[i] = R->studList[i-1];
			}
			R->studList[index] = stud;
			R->studcount++;
		}
	}
	
}

void InsertSorted(ClassRecord *R, studentinfo stud) {
	int i,j;
	
	for(i = 0; i < R->studcount && R->studList[i].age < stud.age; i++){}
	
	for(j = R->studcount; j > i; j--){
		R->studList[j] = R->studList[j-1];
	}
	
	R->studList[i] = stud;
	R->studcount++;
}

void DeleteRecordatIndex(ClassRecord *R, int index) {
	int pos,i;
	
	if(R->studcount != 0) {
		for(pos = 0; pos < R->studcount; pos++) {
			if(pos == index) {
				for(i = pos; i < R->studcount; i++) {
					R->studList[i] = R->studList[i+1];
				}
				R->studcount--;
			}
		}
	}
	

}
void DeleteRear(ClassRecord *R) {
	if(R->studcount != 0) {
		R->studcount--;
	}
}

void DisplayRecords(ClassRecord R) {
	int i;
	
	printf("Student Records: \n");
	printf("%3sName %6s| BirthDate | Age\n"," "," ");
	
	for(i = 0; i < R.studcount; i++) {
		printf("%s %s%4s| %d/%d%3s| %d\n", R.studList[i].name.fname,R.studList[i].name.lname," ", R.studList[i].birthdate.month,R.studList[i].birthdate.year," ", R.studList[i].age);
	}

}
