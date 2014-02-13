//
//  main.c
//  n006_sumNumbes-1.0.0
//
//  Created by Yoonseung Choi on 2014. 2. 8..
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

int main(int argc, const char * argv[])
{
	int mode;
	int run, runTimes;
	
	int val1, val2, cnt, sum;
	
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (run = 0; run< runTimes; run++) {
		
		val1 = (mode == FILEIO ? FileIn() : CmdIn("$ val1 ? : "));
		if (!(val1 >= 0 && val1 <= 10000))	ErrHandling("$ Invalid value (val1) occured.");
		
		val2 = (mode == FILEIO ? FileIn() : CmdIn("$ val2 ? : "));
		if (!(val1 >= 0 && val1 <= 10000))	ErrHandling("$ Invalid value (val2) occured.");
		
		sum = 0;
		for (cnt = val1; cnt <= val2; cnt++) sum+=cnt;
		
		if (mode==CMDIO) printf("$ result is ");
		printf("%d\n", sum);
			
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
