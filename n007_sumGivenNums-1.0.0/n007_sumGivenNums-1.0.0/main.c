//
//  main.c
//  n007_sumGivenNums-1.0.0
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
	
	int cnt, sum;
	
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (run = 0; run< runTimes; run++) {
		
		cnt = (mode == FILEIO ? FileIn() : CmdIn("$ how many sum ? : "));
		if (!(cnt >= 1 && cnt <= 10000))	ErrHandling("$ Invalid value (val1) occured.");
		
		sum=0;
		while (cnt--) sum+=(mode == FILEIO ? FileIn() : CmdIn("$ value ? : "));
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
