
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define CONSOLE // yoon // for debug
#define FILEIO

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}

int euclidGCD(int a, int b) {
#ifdef CONSOLE
	printf(">> GCD(%d, %d)\n", a, b);
#endif
	
	// yoon // base case
	if (b==0)
		return a;
	
	// yoon // recur step
	else
		return euclidGCD(b, a%b);
	
};


int main() {
	int testCases, a, b;
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	while ( testCases --> 0 ) {
		fscanf(filein, "%d %d", &a, &b);
		printf("%d\n", euclidGCD(a, b) );
	}
	
#else
	scanf("%d", &testCases);
	while ( testCases --> 0 ) {
		scanf("%d %d", &a, &b);
		printf("%d\n", euclidGCD(a, b) );
	}
#endif
	
	
	return 0;
}
/*
 3
 132 36 
 0 12 
 132 1
*/