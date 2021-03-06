/*
    + ducci
     
    일정한 연산 이후의 배열이 LOOP 인가 ZERO인가 확인
  
    Boys : 최성현 최윤승 박민욱
  
 */
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
// + !!! 하단의 디랙티브 둘 중 하나는 반드시 주석처리하여야 함
 
//#define CONSOLE // yoon // for debug // + 활성화시 입력을 콘솔로 받음. 콘솔창에 진행과정를 출력
#define FILEIO // + 활성화시 입력을 파일스트림으로 받음. 오직 결과만을 출력.
 
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
  
 1. 시퀀스 구현
  
 2. 패턴탐색
  
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
  
 중에 하나의 형태가 있으면 Loop, 0,0,0,0,0이 나와버리면 false.
  
 패턴유형(5)
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