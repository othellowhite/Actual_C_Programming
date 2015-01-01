
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

int uphill (void *first, void *second) {
	return (*(int*)first > *(int*)second) ? 1 : -1;
}

int twoNums() {
	
	int i, j, arrLength, kVal;
	int nearest, count;
	int before, current;
	
	// yoon // init Array
#ifdef FILEIO
	int iptArr[1000001];
	fscanf(filein, "%d %d", &arrLength, &kVal);
	
	for (i = 0; i < arrLength; i++)
		fscanf(filein, "%d", &iptArr[i]);
	
#else
	int iptArr[400];
	scanf("%d %d", &arrLength, &kVal);
	
	for (i = 0; i < arrLength; i++)
		scanf("%d", &iptArr[i]);
#endif
	
	// yoon // qsort arr
	qsort(iptArr, arrLength, sizeof(int), uphill);
	
#ifdef CONSOLE
	printf("\n>> k value : %d", kVal);
	printf("\n>> qsort Arr : ");
	for (i = 0; i < arrLength; i++)
		printf("%d ",iptArr[i]);
	printf("\n");
#endif

	// brute-force
	
	nearest = pow(2, 31)-1;
	count = 1;
	
	for (i = 0; i < arrLength; i++) {
		
		before = pow(2, 31)-1;
		for (j = i+1; j < arrLength; j++) {
#ifdef CONSOLE
			printf("\n>> %d) local near = {%4d, %4d}, current result : nearest = %2d, count = %2d ",
				   i, iptArr[i], iptArr[j], nearest, count);
#endif
			current = abs(iptArr[i]+iptArr[j]-kVal);
			
			if (before < current) break; // no needs to find more.
			
			if (current < nearest) {
				nearest = current;
				count = 1;
#ifdef CONSOLE
				printf("\n>> nearest changed. ", i, nearest, count);
#endif
			}
			else if (current == nearest) {
				count++;
			}
			before = current;
		}
	}
	return count;
}

int main(int argc, const char * argv[]) {
	
	int testCases;
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	fscanf(filein, "%d\n", &testCases);
	
#else
	
	scanf("%d", &testCases);
	
#endif
	
	while (testCases-->0)
		printf("%d\n", twoNums());
	
	return 0;
}

/*
 
 
	while (1) {
 for (i = 0; i < arrLength; i ++) {
 for (j = i+1; j < arrLength; j++) {
 if ( iptArr[i]+iptArr[j]==kVal+howNear ||
 iptArr[i]+iptArr[j]==kVal-howNear) {
 #ifdef CONSOLE
 printf("{%d, %d} ", iptArr[i], iptArr[j]);
 #endif
 breakflag++;
 break;
 }
 }
 }
 if (breakflag!=0) break;
 else howNear++;
	}
 #ifdef CONSOLE
	printf("how near = %d\n", howNear);
 #endif
	printf("%d\n", breakflag);
 
 
 
 3
 10 8
 -7 9 2 -4 12 1 5 -3 -2 0
 10 4
 -7 9 2 -4 12 1 5 -3 -2 0
 4 20
 1 7 3 5
 */


/*
 
 
 3
 10 -1
 -7 9 2 -4 12 1 5 -3 -2 0
 
 50 -5
 1 2 3 4 5 6 7 8 9 10
 1 2 3 4 5 6 7 8 9 10
 1 2 3 4 5 6 7 8 9 10
 1 2 3 4 5 6 7 8 9 10
 1 2 3 4 5 6 7 8 9 10
 
 10 5
 1 2 3 4 5 6 7 8 9 10
 
 10 15
 1 2 3 4 5 6 7 8 9 10
 
 2 1
 4 5
 
 3 3
 1 3 5
 
 3 200 10
 -99	-98	-97	-96	-95	-94	-93	-92	-91	-90
 -89	-88	-87	-86	-85	-84	-83	-82	-81	-80
 -79	-78	-77	-76	-75	-74	-73	-72	-71	-70
 -69	-68	-67	-66	-65	-64	-63	-62	-61	-60
 -59	-58	-57	-56	-55	-54	-53	-52	-51	-50
 -49	-48	-47	-46	-45	-44	-43	-42	-41	-40
 -39	-38	-37	-36	-35	-34	-33	-32	-31	-30
 -29	-28	-27	-26	-25	-24	-23	-22	-21	-20
 -19	-18	-17	-16	-15	-14	-13	-12	-11	-10
 -9	-8	-7	-6	-5	-4	-3	-2	-1	0
 1	2	3	4	5	6	7	8	9	10
 11	12	13	14	15	16	17	18	19	20
 21	22	23	24	25	26	27	28	29	30
 31	32	33	34	35	36	37	38	39	40
 41	42	43	44	45	46	47	48	49	50
 51	52	53	54	55	56	57	58	59	60
 61	62	63	64	65	66	67	68	69	70
 71	72	73	74	75	76	77	78	79	80
 81	82	83	84	85	86	87	88	89	90
 91	92	93	94	95	96	97	98	99	100
 */



// yoon // binary search sucks so much.
/*
 int i, j, arrLength, kVal;
	int nearest = 0, count = 1; // for each bsearching
	int toFind, leftEnd, mid, rightEnd;	      // for bsearch nearest arr index
	int min;
	// yoon // bsearch nearest for each arr
	nearest = pow(2, 31)-1;
	count = 0;
	
	for (i = 0; i < arrLength; i++) { // yoon // compare for each array
	
 toFind = kVal - iptArr[i];
 leftEnd = 0; rightEnd = arrLength-1;
 
 #ifdef CONSOLE
 printf("\n>> bsearch_nearest(%d)\ttoFind(%d) : ", iptArr[i], toFind);
 #endif
	
 while (leftEnd < rightEnd) {
 
 mid = (leftEnd + rightEnd) / 2;
 
 if (iptArr[mid]==toFind) { // value to find exactly exists
 if(mid!=i)
 nearest = 0;
 break;
 }
 else if (iptArr[mid] > toFind) // scope needs to go left
 rightEnd = mid - 1;
 
 else if (iptArr[mid] < toFind) // scope needs to go right
 leftEnd = mid + 1;
 }
 
 // yoon // find smallest one & count
 
 min = abs(iptArr[mid-1]+kVal) < abs(iptArr[mid]+kVal)
 ? abs(iptArr[mid-1]+kVal) : abs(iptArr[mid]+kVal); // comp mid-1 & mid
 
 min = min < abs(iptArr[mid+1]+kVal)
 ? min : abs(iptArr[mid+1]+kVal); // // comp min_before & mid+1
 
	
 
 
 #ifdef CONSOLE
 printf("value %d is nearest in this scope. ", iptArr[mid]);
 printf("\n>> current result : nearest = %d, count = %d \n", nearest, count);
 #endif
 */