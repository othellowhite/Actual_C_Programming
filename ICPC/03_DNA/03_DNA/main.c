#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define CAPACITY 1000001

char* sequence;
int count;

void dnaCompare(int a, int g, int t, int c, char* marker, int lv) {

	if (a != 0) {
		marker[lv] = 'A';
		dnaCompare(a-1, t, c, g, marker, lv+1);
	}
	if (g != 0) {
		marker[lv] = 'G';
		dnaCompare(a, t, c, g-1, marker, lv+1);
	}
	if (t != 0) {
		marker[lv] = 'T';
		dnaCompare(a, t-1, c, g, marker, lv+1);
	}
	if (c != 0) {
		marker[lv] = 'C';
		dnaCompare(a, t, c-1, g, marker, lv+1);
	}
	

	if (a==0 && t==0 && c==0 && g==0 
		&& strstr(sequence, marker)!=NULL)
		count ++;
}

int main() {
	int testCases, i;
	int seqLen, tokLen;
	int a, g, t, c;

	char marker[101];
	sequence = (char*)malloc(sizeof(char)*CAPACITY);	

	scanf("%d", &testCases);
	while (testCases-->0) {
		
		scanf("%d %d", &seqLen, &tokLen); 

		memset(sequence,'\0', sizeof(char)*seqLen+1);		
		a = 0;  g = 0; t = 0; c = 0;
		count = 0;

		
		scanf("%s", sequence);
		scanf("%s", &marker);

		for (i = 0; i < tokLen; i++) {
			if (marker[i]=='A') a++;
			else if (marker[i]=='G') g++;
			else if (marker[i]=='T') t++;
			else if (marker[i]=='C') c++;
		}
		memset(marker, '\0', sizeof(char)*101);
		dnaCompare(a,g,t,c,marker,0);
		printf("%d\n", count);
	}
}
/*
3
9 4
ATTGGCATT
TGGC
*/