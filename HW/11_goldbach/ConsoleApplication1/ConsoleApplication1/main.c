
/*
	+ goldbach's conjecture
	
	���ڰ� �־����� �װ��� ���� � �� �Ҽ��� ���
 
	Boys : �ּ��� ������ �ڹο�
 
 */

// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>

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
	}
	return;
}

/*
 
 << goldbach's conjecture>>
 
 
 1. ����, 1000������ ���� ������ �Ҽ� �迭�� ����.
 
 2. �������� ������ ��ǲ�� ���� �����ϰ� ���� �ε������� �����ϸ� sumpair�� �ִ��� Ȯ��.
 
 3. �ٵ� �̰� �ѹ� �ϴ� �� �������� ���̽��� ������ �ᱹ Ÿ�ӿ���, ����迭�� ���� ����ؾ� �� ��
 
 4. �� ���� ������ ��ǲ�̴ϱ� �߲پ�Ⱑ ������.
 
 
 */

int main() {
	
	int testCases, i, j, ipt;
	int primeArr[NUM_OF_PRIME]={0,};
	int loop = CAPACITY/2;
	
	int rslt[CAPACITY][2]={0,};

	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	

	// yoon // make prime num arr.
	
	mkPrimArr(&primeArr);
	
	
	// yoon // make rslt arr.
	for (i = 0; i < NUM_OF_PRIME-1; i++) {
		for (j = i; j < NUM_OF_PRIME-1; j++) {
			
			if (CURRENT_VAL <= CAPACITY) { // yoon // ipt range : 4 <= ipt <= 1000
				rslt[CURRENT_VAL][FIRST]  = primeArr[i];
				rslt[CURRENT_VAL][SECOND] = primeArr[j];
			} // yoon // smallest sumpair will set after loop
			
		}
		
	} // yoon // search end.
	
	
	
	while (testCases-->0) {
		fscanf(filein, "%d", &ipt);
		printf("%d %d\n", rslt[ipt][FIRST], rslt[ipt][SECOND]);
	}
	return 0;
}
