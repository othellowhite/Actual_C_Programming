
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 D. henry
 
 -	핸리는 분수를 너무 좋아한다. 인수분해 해버리고 싶다.
	핸리분수에 의하면 5/7 = 1/2 + 1/5 + 1/70 이다. 발견되는 순번도 저 순번이다.
	여기서 가장 큰 분모수는 '70'이다.
	아무튼 분수를 받으면 핸리 분수의 '가장 큰 분모수'를 출력한다.
 
 << 조건 >>
 1. 1/3+1/3은 핸리분수가 아니다.
 2. 분자가 1이 아니면 핸리분수가 아니다.
 3. 입력될 분자, 분모는 10000보다 작다
 
 << 입력 >>
 1. 테스트케이스
 2. 분자, 분모
 
 << 출력 >>
 1. 핸리분수의 '가장 큰 분모수'
 
 */

#include <stdio.h>

#define CONSOLE
//#define FILEIO

FILE* infile;


/*
 int henry(int child, int mother)
 
 -	분모를 받아 핸리분수의 가장 큰 분모수를 반환한다.
	방법은 다음과 같다.
 
	1) 1/2부터 분모를 1씩 늘리며 차근차근 비교
	2) 현재 분수와 비교, 작으면 그 분수를 택한다.
	3) 여기서 두 경우로 나뉜다.
		basecase - 분자가 1이면 여기서의 분모 값을 반환
		rcurstep - 그 외엔 다시 핸리를 굴린다
 
 */
unsigned long long henry (unsigned long long child, unsigned long long mother, unsigned long long mkHenryNum) {

	// 이 부분을 수정
	mkHenryNum = mother/child ;
	while (child*(mkHenryNum) < mother){
		// printf("."); // yoon // for count calcCnt
		mkHenryNum++;
	}
	
	child = (child*mkHenryNum) - mother;
	mother *= mkHenryNum;
	
#ifdef CONSOLE
	printf(">> sub 1/%llu, %llu/%lluleft\n", mkHenryNum, child, mother);
#endif
	
	if (child == 1) return mother ; // basecase
	else if (child == 0) return mkHenryNum; // yoon // basecase // 아까 뺀게 1
	return henry(child, mother, mkHenryNum+1); // recur step
}
/*
 int main()
 
 - 가끔은 주석보다 C가 더 잘 읽힐때도 있다.
 
 */

int main(int argc, const char * argv[]) {
	
	int testCases;
	int child, mother;
	
#ifdef FILEIO
	if((infile = fopen("input.txt", "r"))==NULL) exit(1);;
	fscanf(infile, "%d", &testCases);
#else
	scanf("%d", &testCases);
#endif
	
	while (testCases-->0) {
		
#ifdef FILEIO
		fscanf(infile, "%d %d", &child, &mother);
#else
		scanf("%d %d", &child, &mother);
#endif
		
		printf("%llu\n", henry(child, mother, 2));
		
	}
	
    return 0;
}
/* ipt

 3
 4 23 
 5 7 
 8 11
 
*/

/* opt
138
70
4070
*/