/*
    + ducci
     
    ������ ���� ������ �迭�� LOOP �ΰ� ZERO�ΰ� Ȯ��
  
    Boys : �ּ��� ������ �ڹο�
  
 */
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
// + !!! �ϴ��� ��Ƽ�� �� �� �ϳ��� �ݵ�� �ּ�ó���Ͽ��� ��
 
//#define CONSOLE // yoon // for debug // + Ȱ��ȭ�� �Է��� �ַܼ� ����. �ܼ�â�� ��������� ���
#define FILEIO // + Ȱ��ȭ�� �Է��� ���Ͻ�Ʈ������ ����. ���� ������� ���.
 
#define LOOP 1
#define ZERO 0
 
const char* loop = "LOOP";
const char* zero = "ZERO";
 
FILE *filein;
 
void ErrHandling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
 
/*
  
 1. ������ ����
  
 2. ����Ž��
  
 0,0,0,2,2
 0,0,2,0,2
 0,2,2,2,2 
 2,0,0,0,2 
 2,0,0,2,0 
 2,0,2,2,2 
 2,2,0,0,0 
 0,2,0,0,2 
 2,2,0,2,2 
 0,2,2,0,0 
 2,0,2,0,0 
 2,2,2,0,2 
 0,0,2,2,0 
 0,2,0,2,0 
 2,2,2,2,0
  
 �߿� �ϳ��� ���°� ������ Loop, 0,0,0,0,0�� ���͹����� false.
  
 ��������(5)
 I.     00XX0
 II.    0X0X0
 III.   0XXXX
  
 */
 
int runDucciSeq(int* arr, int arrLeng) {
     
    int i, arridx, arrFirstTmp;
	int ducciFlag = ZERO; 

    for (i = 0; i < 7000; i++) {
		arrFirstTmp = arr[0];
        for (arridx = 0; arridx < arrLeng-1; arridx++) 
             arr[arridx] = abs(arr[arridx]-arr[arridx+1]); 
        
		arr[arrLeng-1] = abs(arr[arrLeng-1]-arrFirstTmp);

    }
#ifdef CONSOLE
	printf("\n>> arr : [");
	for (i = 0; i < arrLeng; i++) printf("%4d ", arr[i]);
	printf("]\n");
#endif
	for (i = 0; i < arrLeng; i++) {

		if (arr[i]!= 0) ducciFlag=LOOP;
	}
	return ducciFlag;
};
 
int main() {
     
    int testCases, i;
    int arrLeng, arr[15];
     
     
#ifdef FILEIO
     
    if((filein = fopen("input.txt", "r")) == NULL)
        ErrHandling("no input file");
     
    fscanf(filein, "%d", &testCases);
     
#else
    scanf("%d", &testCases);
     
#endif
     
    while (testCases-->0) {
         
#ifdef FILEIO // yoon // scan arr
        fscanf(filein, "%d", &arrLeng);
        for (i = 0; i < arrLeng; i++)
            fscanf(filein, "%d", &arr[i]);
         
#else
        scanf("%d", &arrLeng);
        for (i = 0; i < arrLeng; i++)
            scanf("%d", &arr[i]);
#endif
     
        printf("%s\n", runDucciSeq(&arr, arrLeng) == LOOP ? loop : zero);
         
    }
    return 0;
}

/*
4
4
8 11 2 7
5
4 2 0 2 0
7
0 0 0 0 0 0 0
6
1 2 3 1 2 3
*/