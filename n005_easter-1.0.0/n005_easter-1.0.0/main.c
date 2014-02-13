//
//  main.c
//  n005_easter-1.0.0
//
//  Created by Yoonseung Choi on 2014. 2. 8..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

#define FILEIO	1
#define CMDIO	2

FILE *infile;

void ErrHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, const char * argv[])
{
	int mode;
	
	int I;
	int runTimes;
	int y, c, n, t, i, j, k, l, p, q, m, d;
	
	infile = fopen("/input.txt", "r");
	
	printf("$ set Console I/O \n");
	printf("$ (1) File I/O , (2) Command I/O : ");
	scanf("%d", &mode);
	printf("\n");
	
	if (mode == FILEIO && infile == NULL)	ErrHandling("$ File not found.");
	else if (!(mode==CMDIO||mode==FILEIO))	ErrHandling("$ Invalid value (mode) occured.");
	
	runTimes = (mode == FILEIO ? FileIn() : CmdIn("$ runTimes ? : "));
	for (I = 0; I < runTimes; I++) {
		y = (mode == FILEIO ? FileIn() : CmdIn("$ year ? : "));
		if (!(val1 >= 1583 && val1 <= 99999))	ErrHandling("$ Invalid value (val1) occured.");
		
		c = y/100; // 2
		n = y-(y/19)*19; // 3
		t = (c-17)/25; // 4
		i = ( c-( (c/4) + (c-t)/3 ) ) +(n*19)+15; // 5,6,7
		j = i-(i/30)*30; //8
		k = j - ( (j/28)*((1-j/28))*(29/(j+1))*((21-n)/11) ); //9,10,11,12,13
		l = y+(y/4)+(j+2)-c+(c/4); //14,15
		p = l-((l/7)*7); //16
		q = k-p; //17
		m = (q+40)/44+3; //18
		d = (q+28) - (m/4)*31; //19
		
		//printf("%d %d %d %d %d %d %d %d %d %d %d %d\n",y, c, n, t, i, j, k, l, p, q, m, d );
		printf("%d %d\n", m, d);
		
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
	
