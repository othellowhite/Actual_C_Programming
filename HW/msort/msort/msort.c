
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <alloca.h>
#include <string.h>

#define ACTIVE_MAIN
//#define CONSOLE

#define MAX_THRESH 4

// non-recur 구현을 위한 디파인 함수
#define STACK_SIZE	(CHAR_BIT * sizeof(size_t))
#define PUSH(top, low, high)	((void) ((top->leftEnd = (low)), (top->rightEnd = (high)), ++top))
#define	POP(top, low, high)	((void) (--top, (low = top->leftEnd), (high = top->rightEnd)))
#define	STACK_NOT_EMPTY	(stack < top)

/* Byte-wise swap two items of size SIZE. */
#define SWAP(a, b, size)					\
do {										\
	register size_t __size = (size);		\
	register char *__a = (a), *__b = (b);	\
	do {									\
		char __tmp = *__a;					\
		*__a++ = *__b;						\
		*__b++ = __tmp;						\
	} while (--__size > 0);					\
} while (0)

#define min(x, y) ((x) < (y) ? (x) : (y))

typedef struct {
	char *leftEnd;
	char *rightEnd;
}stackNode;

/* Non recursive merge sort
 
	1. 함수는 배열의 시작주소와 배열의 길이 그리고 비교할 함수 포인터를 받아온다.
	2. 만약 들어온 배열의 길이가 0이면 에러핸들링, 호출함수로 복귀한다.
	3. 배열의 길이가 4보다 작아질 때 까지 분할, 스택에 저장한다
	4. 4보다 작을땐 insertion sort가 더 빠르다. 
	   따라서 maxThresh 이내로 들어오면 isort를 진행.
	5. isort이후엔 POP에 의해 leftEnd 값이 가산된다. 
       이를 기준으로 Merge를 실행하자. */
void
msort (void *const pbase, size_t totalElems, size_t size,
		int (*cmp)(const void *, const void *)) {
	
	register char *basePtr = (char*) pbase;
	const size_t maxThresh = MAX_THRESH * size;
	
	/* msort() 는 필연적으로 정렬을 위해 버퍼를 만들어주어야 한다.
	   버퍼의 용도로는 두가지 경우가 있다.
	
	   1. 자식노드 둘을 2개의 버퍼에 각각 memcpy후 원래배열에 정렬하여 넣는다
	   2. 원래배열에서 자식노드를 참조하여 버퍼에 정렬삽입 후 결과를 원래배열에 memcpy한다.
	 
	   두 경우 모두 옮겨가는 비트수는 같으나, (1.)은 memcpy함수를 2번 호출한다.
	   memcpy를 1번만 호출하는 (2.)가 그나마 오버해드가 더 작으므로 이를 택하기로 하자. */
	void *bufferBeingSorted = (void*)__alloca(size*totalElems);
	stackNode partitionsForMerge[STACK_SIZE];
	stackNode *topForMerge=partitionsForMerge;
	
	char *leftEnd = basePtr; // 배열의 왼쪽 끝, 시작 위치
	char *rightEnd = &leftEnd[ (totalElems-1) * size]; // 배열의 오른쪽 끝, 마지막 위치
	
	if (totalElems==0) return;
	
	if (totalElems > MAX_THRESH) {
		
		
		stackNode stack[STACK_SIZE];
		stackNode *top = stack + 1;
		
		while (STACK_NOT_EMPTY) {
			DIVIDE_STEP :;
			
			char *mid = leftEnd + size * ((rightEnd - leftEnd) / size >> 1);
			
#ifdef CONSOLE
			printf("\nscope : %2lu ~ %2lu ~ %2lu\n",
				   (unsigned long)(leftEnd-basePtr)/size,
				   (unsigned long)(mid - basePtr)/size,
				   (unsigned long)(rightEnd-basePtr)/size);
#endif
			
			
			if (rightEnd-leftEnd > maxThresh) { // pust arrPtr to stack
#ifdef CONSOLE
				printf("<< PUSH() to stack >>\n");
#endif
				PUSH(top, mid+size, rightEnd);
				rightEnd = mid;
				goto DIVIDE_STEP;
			}
			
			else { // insertion sort
				
				/* 배열의 크기가 MAX_THRESH 보다 작거나 같다. 우리는 이를 정렬한다.
				   그리고 정렬할 다음 배열을 꺼내어 두 배열을 Merge할 것이다.*/
				char *tmpPtr = leftEnd;
				char *thresh = rightEnd;
				register char *runPtr;
#ifdef CONSOLE
				printf("<< isort() >>\n");
#endif
				/* 오름차순의 예로 들면 비교함수는 "전자와 후자를 뺀 결과"를 반환한다.
				   따라서 여기서 해당 룹은 최소값 탐색과정이며, 그 주소가 tmpPtr에 저장된다. */
				for (runPtr = tmpPtr + size; runPtr <= thresh; runPtr += size)
					if ((*cmp)((void*)runPtr, (void*)tmpPtr) < 0) tmpPtr = runPtr;
				
				if (tmpPtr != leftEnd)
					SWAP(tmpPtr, leftEnd, size);
				
				/* Insertion sort, running from left-hand-side up to right-hand-side.  */
				
				runPtr = leftEnd + size;
				while ((runPtr += size) <= rightEnd) {
					
					tmpPtr = runPtr - size;
					while ((*cmp) ((void *) runPtr, (void *) tmpPtr) < 0)
						tmpPtr -= size;
					
					tmpPtr += size;
					if (tmpPtr != runPtr) // swap
					{
						char *trav;
						
						trav = runPtr + size;
						while (--trav >= runPtr)
						{
							char c = *trav;
							char *hi, *lo;
							
							for (hi = lo = trav; (lo -= size) >= tmpPtr; hi = lo)
								*hi = *lo;
							*hi = c;
						}
					} // swap end
				}

				//Merge를 위해 현재 파티션을 저장해두자.
				PUSH(topForMerge, leftEnd, rightEnd);
	
				//Devide를 위해 다음 스코프를 불러오자.
				POP(top, leftEnd, rightEnd);

			} // insertion sort
			
		} // Stack 내부가 비면 종료.

	}
	
	
	/* <<<<< Conquer Step. >>>>>
	 분할된 인덱스에 대해 Stack에 저장 (partitionsForMerge)
	 Maxthresh 이내 배열에 대해서 isort완료. 남은건 파티션들에 대한 Merge*/
	
	POP(topForMerge, leftEnd, rightEnd);
	{
#ifdef CONSOLE
	printf("\n<<<< MergeStep. >>>>\n");
	printf("partitions : %2lu ~ %2lu\n",
		   (unsigned long)(leftEnd-basePtr)/size,
		   (unsigned long)(rightEnd-basePtr)/size);
#endif
	}
	while (partitionsForMerge < topForMerge ) {
		
		char *leftCmpPtr, *rightCmpPtr, *runPtr;
		
		char *oldLeftEnd = leftEnd;
		char *oldRightEnd = basePtr + ((totalElems-1) * size);
		
		POP(topForMerge, leftEnd, rightEnd);
		leftCmpPtr = leftEnd;
		rightCmpPtr = oldLeftEnd;
		{
#ifdef CONSOLE
			printf("partitions : (new)%2lu ~ %2lu / (old)%2lu ~ %2lu\n",
				   (unsigned long)(leftEnd-basePtr)/size,
				   (unsigned long)(rightEnd-basePtr)/size,
				   (unsigned long)(oldLeftEnd-basePtr)/size,
				   (unsigned long)(oldRightEnd-basePtr)/size);
#endif
		}
		memset(bufferBeingSorted, 0, size*totalElems); // yoon // for debug
		for (runPtr = bufferBeingSorted; runPtr <= bufferBeingSorted+(oldRightEnd - leftEnd); runPtr += size ) {
			{
#ifdef CONSOLE
				printf("leftCmpPtr : %2lu , rightCmpPtr : %2lu, runPtr : %2lu / runptr %2lu ends at %2lu\n",
					   (unsigned long)(leftCmpPtr-basePtr)/size,
					   (unsigned long)(rightCmpPtr-basePtr)/size,
					   ((unsigned long)runPtr-(unsigned long)bufferBeingSorted)/size,
					   ((unsigned long)(runPtr)-(unsigned long)bufferBeingSorted)/size,
					   (unsigned long)(oldRightEnd - leftEnd)/size);
#endif
			}
			// case 1. 두 배열에 아직 원소가 남아있다.
			if ( (rightCmpPtr<=oldRightEnd) && (leftCmpPtr<=rightEnd) ) {
				if ((*cmp)((void*)leftCmpPtr, (void*)rightCmpPtr) < 0) {
					SWAP(leftCmpPtr, runPtr, size);
					leftCmpPtr+=size;
				}
				else {
					SWAP(rightCmpPtr, runPtr, size);
					rightCmpPtr+=size;
				}
			}
			// case 2. 오른쪽 배열이 남았다
			else if ( (rightCmpPtr<=oldRightEnd) ) {
				SWAP(rightCmpPtr, runPtr, size);
				rightCmpPtr+=size;
			}
			// case 3. 왼쪽 배열이 남았다.
			else if ( (leftCmpPtr<=rightEnd)  ) {
				SWAP(leftCmpPtr, runPtr, size);
				leftCmpPtr+=size;
			}
			
			
			
		} // case 4. 두 배열이 모두 비면 룹 종료
		
		// 정렬된 배열을 원래 배열에 카피
		memcpy(leftEnd, bufferBeingSorted, (long)(oldRightEnd - leftEnd + size) );
	}
	// Conquer Step
	
	
	
	return;
};

#ifdef ACTIVE_MAIN


int uphill (void *first, void *second) {
	return (*(int*)first - *(int*)second) ;
};

int main() {
	
	int testCases, capacity, i;
	int arr[100];
	
	FILE *infile;
	if((infile = fopen("input.txt", "r")) == NULL) {
		char* msg = "no input file";
		fputs(msg, stderr);
		fputc('\n', stderr);
		exit(1);
	}
	
	fscanf(infile, "%d", &testCases);
	while (testCases-->0) {
		fscanf(infile, "%d", &capacity);
		for (i = 0; i < capacity; i++) fscanf(infile, "%d", &arr[i]);
		
		msort(&arr, capacity, sizeof(int), uphill);
		
		for (i = 0; i < capacity; i++) printf("%d ", arr[i]);
		printf("\n");
	}

}


#endif


/*
 3
 36 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1
 18 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1
 18 99 81 700 6 5005 444 321 23456 1 10 2 3 4 5 6 7 8 9
 16 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
 9 99 81 700 6 5005 444 321 23456 1
 9 1 2 3 4 5 6 7 8 9
 5
 12 12 11 10 9 8 7 6 5 4 3 2 1
 11 11 10 9 8 7 6 5 4 3 2 1
 10 10 9 8 7 6 5 4 3 2 1
 9 9 8 7 6 5 4 3 2 1
 8 8 7 6 5 4 3 2 1
 
 1
 8 8 7 6 5 4 3 2 1
 
 3
 9 99 81 700 6 5005 444 321 23456 1
 9 1 2 3 4 5 6 7 8 9
 1 10000

 */




