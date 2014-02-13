//
//  main.c
//  n_009_worktime-1.0.0
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

struct workTime {
	int day, hr, min, sec;
}add;

int main(int argc, const char * argv[])
{
	int mode;
	int run, runTimes;
	
	int numOfWorkers;
	
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (run = 0; run< runTimes; run++) {
		
		numOfWorkers = (mode == FILEIO ? FileIn() : CmdIn("$ how many workers ? : "));
		
		add.day = add.hr = add.min = add.sec = 0; //y reset time
		while (numOfWorkers-->0) {
			add.hr	+= (mode == FILEIO ? FileIn() : CmdIn("$ hr ? : "));
			add.min	+= (mode == FILEIO ? FileIn() : CmdIn("$ min ? : "));
			add.sec	+= (mode == FILEIO ? FileIn() : CmdIn("$ sec ? : "));
			
			if (mode==CMDIO) printf("\n$ %d worker(s) left.\n\n", numOfWorkers);
		}
		
		add.min	+=	add.sec/60;
		add.sec %=	60;
		
		add.hr	+=	add.min/60;
		add.min	%=	60;
		
		add.day	+=	add.hr/24;
		add.hr	%=	24;
		
		printf("%d %d %d %d\n", add.day, add.hr, add.min, add.sec);
		
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