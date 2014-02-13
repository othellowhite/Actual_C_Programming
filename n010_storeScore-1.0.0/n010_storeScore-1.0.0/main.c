//
//  main.c
//  n010_storeScore-1.0.0
//
//  Created by Yoonseung Choi on 2014. 2. 10..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

#define FILEIO	1
#define CMDIO	2

FILE *infile;

int FileIn();
int CmdIn(char* msg);

void ErrHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

struct student {
	
	int grade_A;
	int grade_B;
	int grade_C;
	int grade_D;
	int grade_F;
	
}numOf;
void reset(){numOf.grade_A=numOf.grade_B=numOf.grade_C=numOf.grade_D=numOf.grade_F=0;};
void score(int i) {
	int err=
	(100>= i && i > 89) ? numOf.grade_A++ :
	(89 >= i && i > 79) ? numOf.grade_B++ :
	(79 >= i && i > 69) ? numOf.grade_C++ :
	(69 >= i && i > 59) ? numOf.grade_D++ :
	(59 >= i && i > 1)  ? numOf.grade_F++ : -1;
	
	if (err==-1) ErrHandling("$ wrong Score Err.");
}

int main(int argc, const char * argv[])
{
	int mode;
	int run, runTimes;
	
	int numOfStudents;
	
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (run = 0; run< runTimes; run++) {
		reset();
		numOfStudents= (mode == FILEIO ? FileIn() : CmdIn("$ how many students ? : "));
		while (numOfStudents-->0) {
			
			if (mode==CMDIO) printf("\n$ %d student(s) left.\n", numOfStudents+1);
			score( (mode == FILEIO ? FileIn() : CmdIn("$ score ? : ") ) );
		}
		printf("%d %d %d %d %d \n",
			   numOf.grade_A, numOf.grade_B, numOf.grade_C, numOf.grade_D, numOf.grade_F);
		
	}
	return 0;
}

int FileIn() {
	int retVal;
	fscanf(infile, "%d", &retVal);
	return retVal;
}

int CmdIn(char* msg) {
	int retVal;
	printf("%s",msg);
	scanf("%d", &retVal);
	return retVal;
}


