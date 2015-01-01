
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define CONSOLE // yoon // for debug
//#define FILEIO

const char* valid = "YES";
const char* noValid = "NO";

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}

int main() {
	
	int testCases, i, isValid, iptLength;
	char ipt[51];

	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	
#else
	scanf("%d", &testCases);
	
#endif
	
	while (testCases-->0) {
		isValid=0;
		
#ifdef FILEIO
		fscanf(filein, "%s", &ipt);
#else
		scanf("%s", &ipt);
#endif
		
		iptLength = strlen(ipt);
		for (i = 0; i < iptLength; i++) {
			isValid += (ipt[i] == '(' ? 1 : -1);
			if (isValid<0) break;
		}
		
		printf("%s\n", (isValid==0 ? valid : noValid) );
	}
	
	return 0;
}