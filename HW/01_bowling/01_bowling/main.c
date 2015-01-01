

#include <stdio.h>
#include <stdlib.h>

#define CONSOLE
//#define FILEIO

#define STRIKE 3
#define MISS   0


FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}


void Bowling(  ) {
	
	int i, iptTimes, point[22], frame = 10, result = 0;
	int isErr=0;
	
#ifdef FILEIO
	fscanf(filein, "%d", &iptTimes);
#else
	scanf("%d", &iptTimes);
#endif
	
	for (i = 0; i < iptTimes; i++)
#ifdef FILEIO
		fscanf(filein, "%d", &point[i]);
#else
		scanf("%d", &point[i]);
#endif
	
	i = 0;
	while (frame-->0) {
		
		if (point[i] == STRIKE) { // Strike
			result += point[i]+point[i+1]+point[i+2];
			i++;
		}
		
		else {
			result+= point[i++];
			if (point[i]+point[i-1]==STRIKE) { // Spare
				result += point[i]+point[i+1];
				i++;
			}
			else if (point[i]+point[i-1]>STRIKE) {// Error
				//ErrHandling("error");
				printf("error\n");
				isErr = 1;
				break;
			}
			else result+=point[i++]; // Miss
		}
	}
	
	if (isErr!=1)
		printf("%d\n", result);

	
	return;
}


int main(int argc, const char * argv[]) {
	
	int testCases;
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	fscanf(filein, "%d", &testCases);
	
#else
	
	scanf("%d", &testCases);
	
#endif
	
	
	while (testCases-->0)
		Bowling();

	return 0;
}

/*
 
 3
 18 
 1 2 1 0 3 1 1 3 3 2 1 1 2 2 1 3 1 1 
 12
 3 3 3 3 3 3 3 3 3 3 3 3
 12
 2 2 3 3 3 3 3 3 3 3 3 3
 
 */
