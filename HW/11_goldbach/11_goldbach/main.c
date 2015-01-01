
/*
	+ goldbach's conjecture
	
	숫자가 주어지면 그거의 합인 어떤 두 소수의 출력
 
	Boys : 최성현 최윤승 박민욱
 
 */

// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// + !!! 하단의 디랙티브 둘 중 하나는 반드시 주석처리하여야 함

#define CONSOLE // yoon // for debug // + 활성화시 입력을 콘솔로 받음. 콘솔창에 진행과정를 출력
//#define FILEIO // + 활성화시 입력을 파일스트림으로 받음. 오직 결과만을 출력.


#define CAPACITY 1001
#define TRUE	1
#define FALSE	0

#define NUM_OF_PRIME 169

#define FIRST	0
#define SECOND	1

#define CURRENT_VAL primeArr[i] + primeArr[j]

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void mkPrimArr(int* arr) {
	
	int i, j, num, currnetIdx=0;
	char primeFlag;
	
#ifdef CONSOLE
	printf("\n>> make prime Array.\n>>");
#endif
	
	arr[currnetIdx++]=2;
	arr[currnetIdx++]=3;
	
	for (i = 5; i <= CAPACITY; i+=2) {
		
		primeFlag = TRUE;
		
		for (j = 2; j <= i/2; j++) {
			
			if ( i%j == 0 ) {
				primeFlag=FALSE;
				break;
			}
		}
		
		if (primeFlag == TRUE)
			arr[currnetIdx++] = i;
		
#ifdef CONSOLE
		if (primeFlag == TRUE) printf("\n>> current prime num :%4d [count :%4d]", i, currnetIdx);
#endif
	}
	
	return;
}

void mkRsltArr(int* primeArr, int** rslt) {
	int i, j, currentVal = 4;
	
	// yoon // search sumpair - bruteforce


	return;
}

/*
 
 << goldbach's conjecture>>
 
 
 1. 먼저, 1000이하의 수로 구성된 소수 배열을 생성.
 
 2. 다음으로 들어오는 인풋에 대해 무식하게 작은 인덱스부터 진행하며 sumpair가 있는지 확인.
 
 3. 근데 이게 한번 하는 건 괜찮은데 케이스가 많으면 결국 타임오바, 결과배열로 만들어서 출력해야 할 듯
 
 4. 다 답이 나오는 인풋이니까 삐꾸얘기가 없겠지.
 
 
 */

int main() {
	
	int testCases, i, j, ipt;
	int primeArr[NUM_OF_PRIME]={0,};
	int loop = CAPACITY/2;;
	
	int rslt[CAPACITY][2]={0,};
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	
#else
	scanf("%d", &testCases);
	
#endif
	
	// yoon // make prime num arr.
	
	mkPrimArr(&primeArr);
	
	
	// yoon // make rslt arr.
	for (i = 0; i < NUM_OF_PRIME-1; i++) {
		for (j = i; j < NUM_OF_PRIME-1; j++) {
			
			if (CURRENT_VAL <= CAPACITY) { // yoon // ipt range : 4 <= ipt <= 1000
				rslt[CURRENT_VAL][FIRST]  = primeArr[i];
				rslt[CURRENT_VAL][SECOND] = primeArr[j];
				
#ifdef CONSOLE
				printf("\n>> current sum pair: {%4d, %4d} [currentVal :%4d]", rslt[CURRENT_VAL][FIRST], rslt[CURRENT_VAL][SECOND], CURRENT_VAL);
#endif
			} // yoon // smallest sumpair will set after loop
			
		}
		
	} // yoon // search end.
	
	
	
#ifdef CONSOLE // yoon // debug // find empty arr
	printf("\n>>");
	for (i = 4; i < CAPACITY; i++) {
		if (rslt[i][FIRST]==0 && rslt[i][SECOND]==0)
			printf("\n>> empty arr[%3d] : {%4d, %4d}", i, rslt[i][FIRST], rslt[i][SECOND]);
		
		if (rslt[i][FIRST]==0 && rslt[i][SECOND]==0 && i%2==0)
			printf(" <-- Even value appeared !!!!!!!!!!!!!!");
		
	}
	printf("\n");
#endif
	
	
	while (testCases-->0) {
		
		
#ifdef FILEIO
		fscanf(filein, "%d", &ipt);
#else
		scanf("%d", &ipt);
#endif
		
		printf("%d %d\n", rslt[ipt][FIRST], rslt[ipt][SECOND]);
	}
	return 0;
}










