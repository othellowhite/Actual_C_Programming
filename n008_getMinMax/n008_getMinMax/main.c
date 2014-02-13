//
//  main.c
//  n008_getMinMax
//
//  Created by Yoonseung Choi on 2014. 2. 9..
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
	
	int cnt, val, tmp, min, max;
	
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (run = 0; run< runTimes; run++) {
		cnt = (mode == FILEIO ? FileIn() : CmdIn("$ how many times ? : "));
		
		min = max = tmp = (mode == FILEIO ? FileIn() : CmdIn("$ type the value : "));
		cnt--;
		while (cnt-->0) {
			tmp = (mode == FILEIO ? FileIn() : CmdIn("$ type the value : "));
			
			min = tmp<min ? tmp : min;
			max = tmp>max ? tmp : max;
		}
		printf("%d, %d\n",max, min);
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