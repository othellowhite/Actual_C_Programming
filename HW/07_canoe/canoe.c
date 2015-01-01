
/*
	+ Canoe
 
	네 팀에서 한명 씩 뽑아 그 인원들의 무게 합을 
	카누에 적합한 어떤 임의의 무게에 가장 가깝게 만듦.
*/

// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// + !!! 하단의 디랙티브 둘 중 하나는 반드시 주석처리하여야 함

//#define CONSOLE // yoon // for debug // + 활성화시 입력을 콘솔로 받음. 콘솔창에 진행과정를 출력
#define FILEIO // + 활성화시 입력을 파일스트림으로 받음. 오직 결과만을 출력.

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


// + 문제 해결을 위해 만든 구조체.
typedef struct pairset {
	int sum;
	int cls3_idx, cls4_idx; // + 결과는 최소합만을 원하기에 main에서 실제 사용되진 않았다.
}pairs;

// + 위의 구조체를 위한 비교함수. 오름차순이라 qsort와 bsearch에 모두 적용할 수 있다.
int cmpForPairset(const void *first, const void *second) {
	float v1 , v2;
	v1 = ((pairs*)first)->sum;
	v2 = ((pairs*)second)->sum;
	
	if(v1 < v2) return -1;
	else if(v1 == v2) return 0;
	else return 1;
}

// + 라이브러리 내부의 bsearch 함수는 쓸 수 없다. 수정된 이진탐색함수를 다음과 같이 구현.
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
			
			retPtr = bsearch_nearest(valueToFind, pairs_arr, arrLength); // + 이진탐색결과 인덱스(int)를 반환
	
			// + 수정된 이진탐색함수는 최소값을 정확하게 가르킬 수 없다. 따라서 주변 언저리를 전부 탐색 해 주어야 함.
			
			// arr+2
			/* // yoon // timeout
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
#ifdef CONSOLE // + 디버깅을 위해 이중 for문 선택에 의한 합과 nearest pairset의 합과 그 둘의 합, 적합무게와의 치이를 출력
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
	
	int testCases, canoeBestWeight, studentNumber; // + 각각 실행횟수, 카노에에게 적합한 무게, 팀당 인원수를 의미
	int cls1[CAPACITY], cls2[CAPACITY], cls3[CAPACITY], cls4[CAPACITY]; // + 각 팀 배열
	int i, j, k;
	pairs* pairs_arr = (pairs *)malloc(CAPACITY*CAPACITY*sizeof(pairs)+1);  // + 두 팀의 합을 하나의 어레이에 할당할 것
	
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	
#else
	scanf("%d", &testCases);
	
#endif
	
	while (testCases-->0) {
		
#ifdef FILEIO // + 파일입력
		fscanf(filein, "%d %d", &canoeBestWeight, &studentNumber);
		
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls1[i]);
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls2[i]);
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls3[i]);
		for (i = 0; i < studentNumber; i++) fscanf(filein, "%d", &cls4[i]);
#else	// + 콘솔입력
		printf("\n>> now CONSOLE Test.");
		scanf("%d %d", &canoeBestWeight, &studentNumber);

		for (i = 0; i < studentNumber; i++) scanf("%d", &cls1[i]);
		for (i = 0; i < studentNumber; i++) scanf("%d", &cls2[i]);
		for (i = 0; i < studentNumber; i++) scanf("%d", &cls3[i]);
		for (i = 0; i < studentNumber; i++) scanf("%d", &cls4[i]);
#endif
		
		// make pairaset
	
		k = 0; // + 두 개의 팀은 직관적인 비교를 위해, 모든 경우의 수로 미리 더해두어 하나의 배열에 넣어둔다.
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
		
		// + 빠른 무게비교과정을 구현하기 위해 모든 배열들을 정렬시킨다.
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
		// + 카누에 적합한 무게와 최소의 차이를 가지는 팀 쌍의 무게를 출력
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