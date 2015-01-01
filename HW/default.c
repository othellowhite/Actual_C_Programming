
/*
	+ foo
	
	이래저래
 
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

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}


int main() {
	
	int testCases;
	
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	
#else
	scanf("%d", &testCases);
	
#endif
	
	while (testCases-->0) {
		;
	}
	return 0;
}