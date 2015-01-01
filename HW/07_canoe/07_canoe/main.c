
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//#define CONSOLE // yoon // for debug
//#define FILEIO

#define CAPACITY 1001

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}


int uphill (void *first, void *second) {
	return (*(int*)first - *(int*)second) ;
};



typedef struct pairset {
	int sum;
	int cls3_idx, cls4_idx;
}pairs;


int cmpForPairset(const void *first, const void *second) {
	float v1 , v2;
	v1 = ((pairs*)first)->sum;
	v2 = ((pairs*)second)->sum;
	
	if(v1 < v2) return -1;
	else if(v1 == v2) return 0;
	else return 1;
}

int bsearch_nearest(int valueToFind, pairs* pairs_arr, int arrLength) {

	int i, nearest, count = 1;				// for each bsearching
	int leftEnd, mid, rightEnd;	// for bsearch nearest arr index

	
	// yoon // bsearch nearest for each arr
	nearest = pow(2, 31)-1;
	count = 0;
	
	leftEnd = 0; rightEnd = arrLength-1;
	
#ifdef CONSOLE
	printf("\n>> bsearch_nearest to Find(%d) : ", valueToFind);
#endif
	
	while (leftEnd < rightEnd) {
		
		mid = (leftEnd + rightEnd) / 2;
		
		if (pairs_arr[mid].sum == valueToFind) { // value to find exactly exists
			if(mid!=i)
				nearest = 0;
			break;
		}
		else if (pairs_arr[mid].sum > valueToFind) // scope needs to go left
			rightEnd = mid - 1;
		
		else if (pairs_arr[mid].sum < valueToFind) // scope needs to go right
			leftEnd = mid + 1;
	}
	
	return mid;
}

// yoon // Compare And return best Fit

int doCanoeCompairing(int* cls1, int* cls2, pairs* pairs_arr, int canoeBestWeight, int studentNumber) {
	
	int i, j, selectedValue, valueToFind;
	int nearest = pow(2, 31)-1, retPtr;
	int arrLength = pow(studentNumber, 2);

	
	for (i = 0; i < studentNumber; i++) {
		for (j = 0; j < studentNumber; j++) {
			
			selectedValue	= cls1[i]+cls2[j];
			valueToFind		= canoeBestWeight - selectedValue;
			
			retPtr = bsearch_nearest(valueToFind, pairs_arr, arrLength);
	
			
			// arr+2
			/* //yoon// timeout
			if (retPtr+2 < arrLength) {
				
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr+2].sum)) < tmpNearest )
					nearest = selectedValue + pairs_arr[retPtr+2].sum;
				
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr+2].sum)) == tmpNearest
				   && selectedValue + pairs_arr[retPtr+2].sum < nearest)
					nearest = selectedValue + pairs_arr[retPtr+2].sum;
			}
			 */
			// arr+1
			if (retPtr+1 < arrLength) {
				
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr+1].sum)) < abs(canoeBestWeight - nearest) )
					nearest = selectedValue + pairs_arr[retPtr+1].sum;
				
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr+1].sum)) == abs(canoeBestWeight - nearest)
				   && selectedValue + pairs_arr[retPtr+1].sum < nearest)
					nearest = selectedValue + pairs_arr[retPtr+1].sum;
				
			}
			// arr+0
			if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr].sum)) < abs(canoeBestWeight - nearest) )
				nearest = selectedValue + pairs_arr[retPtr].sum;
			
			if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr].sum)) == abs(canoeBestWeight - nearest)
			   && selectedValue + pairs_arr[retPtr].sum < nearest)
				nearest = selectedValue + pairs_arr[retPtr].sum;
			
			
			// arr-1
			if (0 <= retPtr-1 ) {
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr-1].sum)) < abs(canoeBestWeight - nearest) )
					nearest = selectedValue + pairs_arr[retPtr-1].sum;
				
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr-1].sum)) == abs(canoeBestWeight - nearest)
				   && selectedValue + pairs_arr[retPtr-1].sum < nearest)
					nearest = selectedValue + pairs_arr[retPtr-1].sum;
			}
			// arr-2
			/*
			if (0<=retPtr-2 ) {
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr-2].sum)) < tmpNearest )
					nearest = selectedValue + pairs_arr[retPtr-2].sum;
				
				if(abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr-2].sum)) == tmpNearest
				   && selectedValue + pairs_arr[retPtr-2].sum < nearest)
					nearest = selectedValue + pairs_arr[retPtr-2].sum;
			}
			 */
#ifdef CONSOLE
			printf("\n>>1. %d + %d = %d [diff : %d]"
				   , selectedValue, pairs_arr[retPtr+1].sum, selectedValue + pairs_arr[retPtr+1].sum, abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr+1].sum)));
			printf("\n>>2. %d + %d = %d [diff : %d]"
				   , selectedValue, pairs_arr[retPtr].sum, selectedValue + pairs_arr[retPtr].sum, abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr].sum)));

			printf("\n>>3. %d + %d = %d [diff : %d]"
				   , selectedValue, pairs_arr[retPtr-1].sum, selectedValue + pairs_arr[retPtr-1].sum, abs(canoeBestWeight - (selectedValue + pairs_arr[retPtr-1].sum)));

			printf("\n>>current nearest = %d [diff : %d]\n",nearest, abs(canoeBestWeight - nearest));
#endif
			
		}
		
	}
	
	
	return nearest;
}


int main() {
	
	int testCases, canoeBestWeight, studentNumber;
	int cls1[CAPACITY], cls2[CAPACITY], cls3[CAPACITY], cls4[CAPACITY];
	int i, j, k;
	pairs* pairs_arr = (pairs *)malloc(CAPACITY*CAPACITY*sizeof(pairs)+1);
	
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	
#else
	scanf("%d", &testCases);
	
#endif
	
	while (testCases-->0) {
		
#ifdef FILEIO
		fscanf(filein, "%d %d", &canoeBestWeight, &studentNumber);
		
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls1[i]);
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls2[i]);
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls3[i]);
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls4[i]);
#else
		scanf("%d %d", &canoeBestWeight, &studentNumber);

		for (i = 0; i < studentNumber; i++) scanf("%d", &cls1[i]);
		for (i = 0; i < studentNumber; i++) scanf("%d", &cls2[i]);
		for (i = 0; i < studentNumber; i++) scanf("%d", &cls3[i]);
		for (i = 0; i < studentNumber; i++) scanf("%d", &cls4[i]);
#endif
		
		// make pairaset
	
		k = 0;
		for (i = 0; i < studentNumber; i++) {
			for (j = 0; j < studentNumber; j++) {
				pairs_arr[k].cls3_idx = i;
				pairs_arr[k].cls3_idx = j;
				pairs_arr[k].sum = cls3[i]+cls4[j];
				k += 1;
			}
		}
		
#ifdef CONSOLE
		printf("\n>> before sort :");
		printf("\n>> cls1 mem\n");
		for (i = 0; i < studentNumber; i++) printf("%d ", cls1[i]);
		printf("\n>> cls2 mem\n");
		for (i = 0; i < studentNumber; i++) printf("%d ", cls2[i]);
		printf("\n>> pairset mem\n");
		for (i = 0; i < pow(studentNumber, 2); i++) printf("%d ", pairs_arr[i].sum);
		printf("\n>>");
#endif
	

		qsort(cls1, studentNumber, sizeof(int), uphill);
		qsort(cls2, studentNumber, sizeof(int), uphill);
		qsort(pairs_arr, pow(studentNumber, 2), sizeof(pairs), cmpForPairset);
		
		
#ifdef CONSOLE
		printf("\n>> after sort :");
		printf("\n>> cls1 mem\n");
		for (i = 0; i < studentNumber; i++) printf("%d ", cls1[i]);
		printf("\n>> cls2 mem\n");
		for (i = 0; i < studentNumber; i++) printf("%d ", cls2[i]);
		printf("\n>> pairset mem\n");
		for (i = 0; i < pow(studentNumber, 2); i++) printf("%d ", pairs_arr[i].sum);
		printf("\n>>");
#endif
		
		printf("%d\n", doCanoeCompairing(&cls1, &cls2, pairs_arr, canoeBestWeight, studentNumber));
		
	}
	return 0;
}
/*
 3
 300 4
 60 52 80 40
 75 68 88 63
 48 93 48 54 
 56 73 49 75 
 
 8 3
 1 2 3
 1 2 3
 1 2 3
 1 2 3
 
 32 2
 2 5
 9 4
 10 20
 4 2
 
 10 5
 1 2 3 4 5
 1 2 2 3 4
 1 2 3 4 5
 1 2 3 4 5
*/