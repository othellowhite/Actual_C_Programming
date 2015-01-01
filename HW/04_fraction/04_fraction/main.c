
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

unsigned long long euclidGCD(unsigned long long a, unsigned long long b) {
#ifdef CONSOLE
	printf(">> GCD(%llu, %llu)\n", a, b);
#endif
	
	// yoon // base case
	if (b==0)
		return a;
	
	// yoon // recur step
	else
		return euclidGCD(b, a%b);
	
};

void myFracAdd(int a, int b, int c, int d) {
	unsigned long long mothersGCD = euclidGCD(b, d);
	unsigned long long mothersLCM = mothersGCD * b * d;
	unsigned long long babies_SUM = (a * mothersGCD * d) + (c * mothersGCD * b);
	unsigned long long iWantToDivMore = euclidGCD(mothersLCM, babies_SUM);
	
#ifdef CONSOLE
	printf(">> %llu/%llu + %llu/%llu = %llu/%llu, need to div %llu.\n"
		   , a, b, c, d, babies_SUM, mothersLCM, iWantToDivMore);
#endif
	printf("%llu %llu\n",
		   babies_SUM/iWantToDivMore, mothersLCM/iWantToDivMore);
	return ;
};

int main() {
	int testCases;
	int a, b, c, d; // yoon // " a/b + c/d = ? "
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	while ( testCases --> 0 ) {
		fscanf(filein, "%d %d %d %d", &a, &b, &c, &d);
		myFracAdd(a, b, c, d);
	}
	
#else
	scanf("%d", &testCases);
	while ( testCases --> 0 ) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		myFracAdd(a, b, c, d);
	}
#endif
	
	
	return 0;
}
/*
 
 4
 1 2 1 3
 4 3 2 6
 5 3 5 6
 9999 9999 9999 9999
 
 
*/
