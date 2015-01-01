
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

//#define CONSOLE // yoon // for debug
#define FILEIO

#define LARGEVAL 9999
#define CAPACITY 10
#define STUCKED -1
#define ABLETOGO 0

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}

int chessBoard[CAPACITY][CAPACITY];
int boardSize;

struct knight {
	int x, y;
	int step;
} myKnight;

int nextPath(struct knight next) {
	int count = 0;
	
	if ( (next.x-2 >= 0 && next.y-1 >= 0) &&
		chessBoard[next.x-2][next.y-1]==0) {
		count++;
	}
	if ( (next.x-2 >= 0 && next.y+1 <= CAPACITY) &&
		chessBoard[next.x-2][next.y+1]==0) {
		count++;
	}
	if ( (next.x-1 >= 0 && next.y+2 <= CAPACITY) &&
		chessBoard[next.x-1][next.y+2]==0) {
		count++;
	}
	if ( (next.x+1 <= CAPACITY && next.y+2 <= CAPACITY) &&
		chessBoard[next.x+1][next.y+2]==0) {
		count++;
	}
	if ( (next.x+2 <= CAPACITY && next.y+1 <= CAPACITY) &&
		chessBoard[next.x+2][next.y+1]==0) {
		count++;
	}
	if ( (next.x+2 <= CAPACITY && next.y-1 >= 0) &&
		chessBoard[next.x+2][next.y-1]==0) {
		count++;
	}
	if ( (next.x+1 <= CAPACITY && next.y-2 >= 0) &&
		chessBoard[next.x+1][next.y-2]==0) {
		count++;
	}
	if ( (next.x-1 >= 0 && next.y-2 >= 0) &&
		chessBoard[next.x-1][next.y-2]==0) {
		count++;
	}
	/*
	if (count==0)
		return STUCKED;
	
	else return count;
	 */
	return count;
}

int touring() {
	
	struct knight dummy = myKnight;
	int min_cnt=LARGEVAL;
	int min_x, min_y;
	
	// according to Warnsdorff's Rule, Knight loves to go narrow path.
	
	// << needs to know >>
	//  1. able to go
	//  2. never have been there
	//  3. least next path to go
	
	// <i-2, j-1>, <i-2, j+1>, <i-1, j+2>, <i+1, j+2>,
	// <i+2, j+1>, <i+2, j-1>, <i+1, j-2>, <i-1, j-2>
	
	
	// yoon // find next path
	
	//path 1
	dummy.x = myKnight.x-2;
	dummy.y = myKnight.y-1;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	//path 2
	dummy.x = myKnight.x-2;
	dummy.y = myKnight.y+1;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	//path 3
	dummy.x = myKnight.x-1;
	dummy.y = myKnight.y+2;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	//path 4
	dummy.x = myKnight.x+1;
	dummy.y = myKnight.y+2;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	//path 5
	dummy.x = myKnight.x+2;
	dummy.y = myKnight.y+1;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	//path 6
	dummy.x = myKnight.x+2;
	dummy.y = myKnight.y-1;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	//path 7
	dummy.x = myKnight.x+1;
	dummy.y = myKnight.y-2;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&
		chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	//path 8
	dummy.x = myKnight.x-1;
	dummy.y = myKnight.y-2;
	if (0<=dummy.x && dummy.x<=CAPACITY &&
		0<=dummy.y && dummy.y<=CAPACITY &&chessBoard[dummy.x][dummy.y] == ABLETOGO &&
		nextPath(dummy)!=STUCKED && nextPath(dummy)<min_cnt) {
		min_cnt = nextPath(dummy);
		min_x = dummy.x;
		min_y = dummy.y;
	}
	
	
	// yoon // move my knight
	if (min_cnt == LARGEVAL)
		return STUCKED;
		
	else {
		chessBoard[myKnight.x][myKnight.y] = myKnight.step++;
		myKnight.x = min_x;
		myKnight.y = min_y;
		
		if (myKnight.step==boardSize) {
			chessBoard[myKnight.x][myKnight.y] = myKnight.step;
		}
		return 1;
	}
}

int knightsTour(int siz_x, int siz_y, int loc_x, int loc_y) {
	
	int i, j;
	
	myKnight.x = loc_x-1;
	myKnight.y = loc_y-1;
	myKnight.step = 1;
	
	// set ChessBoard
	memset(chessBoard, STUCKED, sizeof(int)*CAPACITY*CAPACITY);
	for (i = 0; i < siz_y; i++)
		memset((*chessBoard+(i*CAPACITY)), 0, sizeof(int)*siz_x);
	
	// go trip
	boardSize = siz_x*siz_y;
	while (myKnight.step < boardSize) {	// 1. end loop when knight ends his trip.
		if (touring()==STUCKED) break;		// 2. break loop when knight cannot move more.
		
		
#ifdef CONSOLE
		printf("\n>> step %d\n>>", myKnight.step-1);
		for (i = 0; i < siz_y; i++) {
			for (j = 0; j < siz_x; j++)
				printf("%3d ", chessBoard[i][j]);
			printf("\n>>");
		}
		printf("\n");
#endif
		
	}
	
	// notify to main
	return (myKnight.step == siz_x*siz_y ? 1 : 0);
}


int main() {
	int testCases, tripFinished, i, j;
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
		
		printf("%d\n", tripFinished = knightsTour(siz_x, siz_y, loc_x, loc_y) );
		
		if (tripFinished) {
			
			for (i = 0; i < siz_y; i++) {
				for (j = 0; j < siz_x; j++)
					printf("%2d ", chessBoard[i][j]);
				printf("\n");
			}
			
		}// prints chess board when knight finished his trip.

	}

	
	return 0;
}
/*
 3 
 6 8 3 4
 6 5 1 2 
 4 4 1 2
*/