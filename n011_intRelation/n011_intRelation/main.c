//
//  main.c
//  n011_intRelation
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
	int big;
	int small;
	int same;
	int diffMoreThen5;
	int modulable;
}frontIs;

void set() {frontIs.big=frontIs.small=frontIs.same=frontIs.diffMoreThen5=frontIs.modulable=0;}
int compare(int* tmp, int ipt) {
	
	if ( !(0<=ipt&&ipt<=100) ) // err occurred
		return -1;
	
	if (*tmp>=ipt)		frontIs.big++;
	if (*tmp<=ipt)		frontIs.small++;
	if (*tmp==ipt)		frontIs.same++;
	if (*tmp>ipt+5 ||
		*tmp<ipt-5)		frontIs.diffMoreThen5++;
	if (*tmp%ipt==0 ||
		ipt%*tmp==0)	frontIs.modulable++;
	
	*tmp = ipt;
	return 0;
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
		tmp = (mode == FILEIO ? FileIn() : CmdIn("$ int value : "));
		iptTimes--;
		while (iptTimes-->0) if( compare
			(&tmp, (mode == FILEIO ? FileIn() : CmdIn("$ int value : "))) ==-1)
			ErrHandling("$ Wrong input value Err.");
			
		printf("%d %d %d %d %d\n",
			   frontIs.big, frontIs.small, frontIs.same, frontIs.diffMoreThen5, frontIs.modulable);
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
