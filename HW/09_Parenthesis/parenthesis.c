
/*
	+ Parenthesis
	
	쌍이 맞는 적합한 괄호(VPS)인지 확인
 
	Boys : 최성현 최윤승 박민욱
 
 */
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// + !!! 하단의 디랙티브 둘 중 하나는 반드시 주석처리하여야 함

//#define CONSOLE // yoon // for debug // + 활성화시 입력을 콘솔로 받음. 콘솔창에 진행과정를 출력
#define FILEIO // + 활성화시 입력을 파일스트림으로 받음. 오직 결과만을 출력.

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
			isValid += (ipt[i] == '(' ? 1 : -1); // + 0부터 시작하여 열린괄호는 가산, 닫힌괄호는 감산하며 검사
			if (isValid<0) break; // + 음수고 되면 열란 괄호보다 닫힌 괄호가 많음을 의미하므로 에러.
		}
		
		printf("%s\n", (isValid==0 ? valid : noValid) ); // + 괄호쌍이 적합하면 감-가산 결과가 반드시 0일 것임

	}
	
	return 0;
}