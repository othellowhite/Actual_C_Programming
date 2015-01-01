
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 G. mutation
 
 - 삐꾸난 염기서열이 시퀀스 안에 몇개나 들어가 있나 출력
 
 << 조건 >>
 1. 시퀀스는 1000000개까지, 삐꾸날 염기서열은 100개까지
 
 << 입력 >>
 1. 테스트케이스
 2. 시퀀스문장, 삐꾸날 염기서열문장
 
 << 출력 >>
 1. 시퀀스 내 삐꾸난 염기서열 문장 갯수
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define CAPACITY 1000001

#define A 0
#define G 1
#define T 2
#define C 3

#define RM_1ST_MRK	\
if (sequence[i-1]=='A') mutatableMarker[A]--;		\
else if (sequence[i-1]=='G') mutatableMarker[G]--;	\
else if (sequence[i-1]=='T') mutatableMarker[T]--;	\
else if (sequence[i-1]=='C') mutatableMarker[C]--;

#define ADD_NEW_MRK		\
if (sequence[i+mrkLen-1]=='A') mutatableMarker[A]++;		\
else if (sequence[i+mrkLen-1]=='G') mutatableMarker[G]++;	\
else if (sequence[i+mrkLen-1]=='T') mutatableMarker[T]++;	\
else if (sequence[i+mrkLen-1]=='C') mutatableMarker[C]++;

#define CMP_SEQ \
if ( mutatableMarker[A]==a	\
&& mutatableMarker[G]==g	\
&& mutatableMarker[T]==t	\
&& mutatableMarker[C]==c )	countMutableStr++;

char* sequence;
int count;

/*
 int dnaCompare(int a, int g, int t, int c , int seqLen, int mrkLen) {
 
 -	정말 단순하고 빠른 방법이 있다. 
	sequence를 처음부터 marker 길이만큼 스코프를 둔 후,
	거기안에 있는 모든 염기서열 갯수만 찾아내. 
	암만 mutetion 해봐야 갯수는 무조건 같아야 하니까. <- 키포인트 !!
	그리고 나서 스코프를 1 씩 증가시키면서 염기서열 갯수만 체크하면 된다.
	시간복잡도 n = strlen(sequence);

 */
int dnaCompare(int a, int g, int t, int c , int seqLen, int mrkLen) {
	
	int i , countMutableStr = 0;
	int mutatableMarker[4] = {0,};
	int j;
	
	
	// yoon // init mutableMarker arr
	for (i = 0; i < mrkLen; i++) {
		if (sequence[i]=='A') mutatableMarker[A]++;
		else if (sequence[i]=='G') mutatableMarker[G]++;
		else if (sequence[i]=='T') mutatableMarker[T]++;
		else if (sequence[i]=='C') mutatableMarker[C]++;
	}
	
	printf("current scope[%d] : \n %c {", 0, 'X');
	for(j = 0; j < mrkLen; j++)printf("%c ", sequence[j]);
	printf("}%c\n", sequence[j]);
	
	// yoon // cmp first seq scope
	CMP_SEQ;
	
	
	/*
	 1. 시퀀스 스코프를 옮김. 
	 2. 그와 동시에 mutableMarker 내부 값 조정이라 함은 뺄거 뺴고 더할거 더하고
	 3. 이제 비교 후 있으면 가산, 없으면 말고.
	 */
	for (i = 1; i <= seqLen - mrkLen; i++) {
		
		// yoon // move scope & set mutableMarker
		RM_1ST_MRK;
		ADD_NEW_MRK;
		
		printf("current scope[%d] : \n %c {", i, sequence[i-1]);
		for(j = 0; j < mrkLen; j++)printf("%c ", sequence[i+j]);
		printf("}%c\n", sequence[i+j]);
		
		// yoon // mutation comparing
		CMP_SEQ;
	}
	
	return countMutableStr;
}
/*
 int main()
 */

int main() {
	int testCases, i;
	int seqLen, mrkLen;
	int a, g, t, c;
	
	char marker[101];
	sequence = (char*)malloc(sizeof(char)*CAPACITY);
	// yoon // 문장이 너무 길어 배열로 선언이 안된다. 동적할당으로  힙 영역에 시퀀스 문장을 둔다.
	
	scanf("%d", &testCases);
	while (testCases-->0) {
		
		scanf("%d %d", &seqLen, &mrkLen); // 시퀀스 길이, 마커 길이 입력
		
		memset(sequence,'\0', sizeof(char)*seqLen+1);
		a = 0;  g = 0; t = 0; c = 0;
		count = 0;
		
		
		scanf("%s", sequence); // yoon // 이거 좀 잘 보자. 다 풀어놓고 제출도 못해보고
		scanf("%s", &marker);
		
		for (i = 0; i < mrkLen; i++) {
			if (marker[i]=='A') a++;
			else if (marker[i]=='G') g++;
			else if (marker[i]=='T') t++;
			else if (marker[i]=='C') c++;
		}
		memset(marker, '\0', sizeof(char)*101);
		
		//dnaCompare_mkTree(a,g,t,c,marker,0);
		//printf("%d\n", count);
		
		printf("%d\n", dnaCompare(a, g, t, c, seqLen, mrkLen));
	}
}

/* ipt
 
 3
 6 4 
 ATGGAT 
 AGGT 
 6 4 
 ATGGAT AGCT
 17 4
 ATGGATATGGATATGGA
 AGGT
 17 5
 ATGGATATGGATATGGA
 AGGTA
 */


/* opt
3
0
*/

/*
 void dnaCompare_mkTree(int a, int g, int t, int c, char* marker, int lv)
 - 염기서열 각각의 갯수, 변형될 염기문장배열, 함수재귀횟수 를 받아온다
 - 시퀀스에 해당 염기가 있으면 count 변수를 가산한다.
 
 << 트리를 생성해서 스트링 컴페어 하는건 정말 '정도'이다. 느려질 수 밖에 없는 구조. 따라서 문제에서 사용하지 않는다. >>
 */
void dnaCompare_mkTree(int a, int g, int t, int c, char* marker, int lv) {
	
	if (a != 0) {
		marker[lv] = 'A';
		dnaCompare_mkTree(a-1, g, t, c, marker, lv+1);
	}
	if (g != 0) {
		marker[lv] = 'G';
		dnaCompare_mkTree(a, g-1, t, c, marker, lv+1);
	}
	if (t != 0) {
		marker[lv] = 'T';
		dnaCompare_mkTree(a, g, t-1, c, marker, lv+1);
	}
	if (c != 0) {
		marker[lv] = 'C';
		dnaCompare_mkTree(a, g, t, c-1, marker, lv+1);
	}
	
	//if (a==0 && t==0 && c==0 && g==0) printf("%s\n", marker);
	if (a==0 && t==0 && c==0 && g==0
		&& strstr(sequence, marker)!=NULL)
		count ++;
}