
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#define CONSOLE // yoon // for debug
//#define FILEIO

#define CAPACITY	10
#define STUCKED		-1
#define TRUE		1
#define EMPTY		0
#define FALSE		0

#define X 0
#define Y 1

#define ULL {-2,-1}
#define UUL {-1,-2}
#define UUR { 1,-2}
#define URR { 2,-1}
#define DRR { 2, 1}
#define DDR { 1, 2}
#define DDL {-1, 2}
#define DLL {-2, 1}

struct knight {
	int x, y;
	int step;
	int currentIdx;
} myKnight;

int chessBoard[CAPACITY][CAPACITY];

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}


/* 
 + knightsTour
 :	brute-force �ϰ� Ž��, �������� �ݵ�� ������� �ʴ´�.
	�Ķ���ͷ� ü������ ũ��(x y��) �� ü������ ��ġ(x y��) �� �޾ƿ´�.
 
		step 1. while ���� ���ѹݺ��ϸ� 8���� ���������� ������ ��.
		step 2. �����ϸ�  knight ����ü�� ���ؿ� �������� ����.
		step 3. while�� Ż�⿡�� �� ���� ������ �ϳ��� �����ؾ� �Ѵ�.
 
			i)  ������ top �������� ���� ü���� ũ��� �����ϴ�. <- ���� ����, 1���� ��ȯ
			ii) ������ top �����ڰ� �ٽ� ������ ó���� �����Ѵ�. <- ���� ����, 0���� ��ȯ
 */


int knightsTour(int siz_x, int siz_y, int loc_x, int loc_y) {
	
	
	struct knight stack[CAPACITY*CAPACITY];
	int top=1;
	
	int i, j;
	int Direction[8][2] = {ULL, UUL, UUR, URR, DRR, DDR, DDL, DLL};
	int x_to_go, y_to_go;
	
	
	myKnight.x = loc_x-1;
	myKnight.y = loc_y-1;
	myKnight.step = 1;
	myKnight.currentIdx = 0;
	
	
	// set ChessBoard
	memset(chessBoard, STUCKED, sizeof(int)*CAPACITY*CAPACITY);
	for (i = 0; i < siz_y; i++)
		memset((*chessBoard+(i*CAPACITY)), 0, sizeof(int)*siz_x);
	

	// go tour and notify to main
	while (TRUE) {
	BEGIN :
		
		// RECORD PATH
		chessBoard[myKnight.y][myKnight.x] = top;
		
#ifdef CONSOLE
		printf("\n");
		
		printf("\n>> stack top : %d", top);
		for (i = top-1; i>=1; --i)
			printf("\n>> [%2d][ x :%2d, y :%2d, dstidx :%3d ]", i, stack[i].x, stack[i].y, stack[i].currentIdx);
		
		printf("\n");
		printf("\n>> curent top : %d", top);
		for (i = 0; i < CAPACITY; i++) {
			printf("\n>> ");
			for (j = 0; j < CAPACITY; j++) {
				printf("%2d", chessBoard[i][j]);
			}
		}
#endif
		
		// + ��簡 ������ ��ħ. ���༺�� ����� �������� ��ȯ�ϸ� �Լ��� ����.
		if (top == siz_x*siz_y) return 1;
		
		for (i = myKnight.currentIdx; i < 8; i++) {
			
			x_to_go = myKnight.x + Direction[i][X];
			y_to_go = myKnight.y + Direction[i][Y];
			
			if ( 0<=x_to_go && x_to_go<siz_x
				&& 0<=y_to_go && y_to_go<siz_y /* idx accessErr handling */
				&& chessBoard[y_to_go][x_to_go] != STUCKED
				&& chessBoard[y_to_go][x_to_go] == EMPTY ) {
				
				// SAVE CURRENT DIRECTION INDEX
				myKnight.currentIdx = i;
				
				// PUSH TO STACK
				stack[top].x = myKnight.x;
				stack[top].y = myKnight.y;
				stack[top].currentIdx = i;
				top++;
				
				// MOVE KNIGHT
				myKnight.x = x_to_go;
				myKnight.y = y_to_go;
				myKnight.currentIdx = 0;
				
				// GO TO BEGIN
				goto BEGIN;
    
			}
			
			
		}// yoon // for loop end.
		
		/*
		 8���� ���� Ž���ߴ�.
		 ���� ������ �ǹ��ϹǷ� �ֻ��� ������ �����Ѵ�.
		 ���� ������ ������ ���ٸ� ó������ ���ƿ� ��, ���� ����.
		 */
		if (--top == 0) break;
		
		else {
			chessBoard[myKnight.y][myKnight.x] = EMPTY;
			myKnight.x = stack[top].x;
			myKnight.y = stack[top].y;
			myKnight.currentIdx = stack[top].currentIdx+1;
			
		}
	} // while loop end.
	
	// Journey failed.
	return 0;
}



/*
 
 // yoon // main
 
 1. get number of cases
 2. run 'knightsTour'. it return 1 or 0
 3. return value 1 means tour being sucessfuly end.
 4. when tour ends successfully, print chessBoard with numbered path.
 
 */
int main() {
	
	int testCases, tripStep, i, j;
	int siz_x, siz_y, loc_x, loc_y;
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	
#else
	scanf("%d", &testCases);
	
#endif
	while ( testCases --> 0 ) {
		
#ifdef FILEIO
		fscanf(filein, "%d %d %d %d", &siz_y, &siz_x, &loc_y, &loc_x);
#else
		scanf("%d %d %d %d", &siz_y, &siz_x, &loc_y, &loc_x);
#endif
		
		printf("%d\n", tripStep = knightsTour(siz_x, siz_y, loc_x, loc_y) );
		
		if (tripStep != 0) {
			
			for (i = 0; i < siz_y; i++) {
				for (j = 0; j < siz_x; j++)
					printf("%2d ", chessBoard[i][j]);
				printf("\n");
			}
			
		}// prints chess board when knight finished his trip.
		
	}
	
	
	return 0;
}