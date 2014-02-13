//
//  main.c
//  n013_oddEven-1.0.0
//
//  Created by Yoonseung Choi on 2014. 2. 12..
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
struct relation {
	int odd;
	int even
}numOf;

void set() {numOf.odd=numOf.even=0;}
int compare(int ipt) {
	
	if ( !(1<=ipt&&ipt<=100) ) // err occurred
		return -1;
	return (ipt%2==0? numOf.even++ : numOf.odd++);
}

int main(int argc, const char * argv[])
{
	int mode;
	int run, runTimes;
	
	int iptTimes, tmp;
	
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (run = 0; run< runTimes; run++) {
		
		set();
		iptTimes = (mode == FILEIO ? FileIn() : CmdIn("$ number of inputs ? : "));
		while (iptTimes-->0)
			if( compare (mode == FILEIO ? FileIn() : CmdIn("$ int value : ")) ==-1)
			ErrHandling("$ Wrong input value Err.");
		
		printf("%d %d\n",numOf.odd, numOf.even);
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
