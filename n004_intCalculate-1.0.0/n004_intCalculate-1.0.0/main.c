//
//  main.c
//  n004_intCalculate-1.0.0
//
//  Created by Yoonseung Choi on 2014. 2. 8..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define FILEIO	1
#define CMDIO	2

FILE *infile;

int FileIn();
int CmdIn(char* msg);
int isSame(int a, int b){return(a==b?1 : 0);}

void ErrHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, const char * argv[])
{
	int mode;
	
	int i;
	int runTimes;
	int val1, val2;
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (i = 0; i < runTimes; i++) {
		
		val1 = (mode == FILEIO ? FileIn() : CmdIn("$ val1 ? : "));
		if (!(val1 >= 1 && val1 <= 10000))	ErrHandling("$ Invalid value (val1) occured.");
		
		val2 = (mode == FILEIO ? FileIn() : CmdIn("$ val2 ? : "));
		if (!(val2 >= 1 && val2 <= 10000))	ErrHandling("$ Invalid value (val2) occured.");
		
		if (mode==CMDIO) printf("$ sum sub abs(sub) mul div mod max isSame()\n");
		printf("%d %d %d %d %d %d %d %d\n",
			   val1+val2, val1-val2, abs(val1-val2), val1*val2, val1/val2, val1%val2, (val1>val2 ? val1:val2), isSame(val1,val2));
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








