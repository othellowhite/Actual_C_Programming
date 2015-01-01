
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

//#define CONSOLE // yoon // for debug
#define FILEIO

#define CAPACITY	10
#define STUCKED		-1
#define TRUE		1
#define EMPTY		0
#define FALSE		0

struct knight {
	int x, y;
	int step;
} myKnight;

int boardSize;
int chessBoard[CAPACITY][CAPACITY];

#define ABLE_ULL(knight)	(knight.y-1 >= 0 && knight.x-2 >= 0)
#define ABLE_UUL(knight)	(knight.y-2 >= 0 && knight.x-1 >= 0)
#define ABLE_UUR(knight)	(knight.y-2 >= 0 && knight.x+1 <= CAPACITY)
#define ABLE_URR(knight)	(knight.y-1 >= 0 && knight.x+2 <= CAPACITY)
#define ABLE_DRR(knight)	(knight.y+1 <= CAPACITY && knight.x+2 <= CAPACITY)
#define ABLE_DDR(knight)	(knight.y+2 <= CAPACITY && knight.x+1 <= CAPACITY)
#define ABLE_DDL(knight)	(knight.y+2 <= CAPACITY && knight.x-1 >= 0)
#define ABLE_DLL(knight)	(knight.y+1 <= CAPACITY && knight.x-2 >= 0)

#define BORD_ULL(knight)	chessBoard[knight.y-1][knight.x-2]
#define BORD_UUL(knight)	chessBoard[knight.y-2][knight.x-1]
#define BORD_UUR(knight)	chessBoard[knight.y-2][knight.x+1]
#define BORD_URR(knight)	chessBoard[knight.y-1][knight.x+2]
#define BORD_DRR(knight)	chessBoard[knight.y+1][knight.x+2]
#define BORD_DDR(knight)	chessBoard[knight.y+2][knight.x+1]
#define BORD_DDL(knight)	chessBoard[knight.y+2][knight.x-1]
#define BORD_DLL(knight)	chessBoard[knight.y+1][knight.x-2]

#define MOVE_ULL(knight)	knight.y -= 1; knight.x -= 2;
#define MOVE_UUL(knight)	knight.y -= 2; knight.x -= 1;
#define MOVE_UUR(knight)	knight.y -= 2; knight.x += 1;
#define MOVE_URR(knight)	knight.y -= 1; knight.x += 2;
#define MOVE_DRR(knight)	knight.y += 1; knight.x += 2;
#define MOVE_DDR(knight)	knight.y += 2; knight.x += 1;
#define MOVE_DDL(knight)	knight.y += 2; knight.x -= 1;
#define MOVE_DLL(knight)	knight.y += 1; knight.x -= 2;

#define RSET_ULL(knight)	chessBoard[knight.y][knight.x]=0; knight.y += 1; knight.x += 2; step--;
#define RSET_UUL(knight)	chessBoard[knight.y][knight.x]=0; knight.y += 2; knight.x += 1; step--;
#define RSET_UUR(knight)	chessBoard[knight.y][knight.x]=0; knight.y += 2; knight.x -= 1; step--;
#define RSET_URR(knight)	chessBoard[knight.y][knight.x]=0; knight.y += 1; knight.x -= 2; step--;
#define RSET_DRR(knight)	chessBoard[knight.y][knight.x]=0; knight.y -= 1; knight.x -= 2; step--;
#define RSET_DDR(knight)	chessBoard[knight.y][knight.x]=0; knight.y -= 2; knight.x -= 1; step--;
#define RSET_DDL(knight)	chessBoard[knight.y][knight.x]=0; knight.y -= 2; knight.x += 1; step--;
#define RSET_DLL(knight)	chessBoard[knight.y][knight.x]=0; knight.y -= 1; knight.x += 2; step--;

#define RECORD_PATH(knight)	chessBoard[knight.y][knight.x]=step; step++;

#ifdef CONSOLE
	int countKnightsAllSteps =0;
#endif

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}


int totalStep;

/*
 // yoon // knightsTour 
 
 >> ABLE_(DST) : mem access error handling.
 >> BORD_(DST) : look up the board for knowing dst is
 >> MOVE_(DST) : move dummy knight.
 >> RSET_(DST) : cannot go there. reset dummy's location
 
 */
int touring(struct knight dummy, int step) { // yoon // brute-force solution
	
	int isJourneyEnd = FALSE;
	
#ifdef CONSOLE
	int i, j;
	printf("\033[12A"); // yoon // for static print
	if (totalStep != 0) {
		printf("\n>> Step : %d, dummy now : {%d, %d} [%d]\n>> ", step-1, dummy.x+1, dummy.y+1, ++countKnightsAllSteps);
		for (i = 0; i < CAPACITY; i++) {
			for (j = 0; j < CAPACITY; j++) {
				if (j==dummy.x && i==dummy.y) {
					printf(" X ");
				}
				else printf("%2d ", chessBoard[i][j]);
			}
			printf("\n>> ");
		}
		
	}
#endif
	
	if (step==totalStep) {
		RECORD_PATH(dummy);
		return TRUE;
	}
	
	if (ABLE_ULL(dummy) && BORD_ULL(dummy)!=STUCKED
		&& BORD_ULL(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_ULL(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_ULL(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	if (ABLE_UUL(dummy) && BORD_UUL(dummy)!=STUCKED
		&& BORD_UUL(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_UUL(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_UUL(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	if (ABLE_UUR(dummy) && BORD_UUR(dummy)!=STUCKED
		&& BORD_UUR(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_UUR(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_UUR(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	if (ABLE_URR(dummy) && BORD_URR(dummy)!=STUCKED
		&& BORD_URR(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_URR(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_URR(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	if (ABLE_DRR(dummy) && BORD_DRR(dummy)!=STUCKED
		&& BORD_DRR(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_DRR(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_DRR(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	if (ABLE_DDR(dummy) && BORD_DDR(dummy)!=STUCKED
		&& BORD_DDR(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_DDR(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_DDR(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	if (ABLE_DDL(dummy) && BORD_DDL(dummy)!=STUCKED
		&& BORD_DDL(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_DDL(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_DDL(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	if (ABLE_DLL(dummy) && BORD_DLL(dummy)!=STUCKED
		&& BORD_DLL(dummy)==EMPTY && isJourneyEnd == FALSE) {
		
		RECORD_PATH(dummy);
		MOVE_DLL(dummy);
		if ((isJourneyEnd=touring(dummy, step))==FALSE){
			RSET_DLL(dummy);
		}
		else isJourneyEnd = TRUE;
	}
	return isJourneyEnd;
}




/*
 // yoon // knightsTour -> (1 || 0)
 
 1. set struct 'knight'
 2. set chessBoard
 3. go tour
 4. notify to main that tour being successfully end, or not.
 
 */
int knightsTour(int siz_x, int siz_y, int loc_x, int loc_y) {
	
	int i, j;
	
	myKnight.x = loc_x-1;
	myKnight.y = loc_y-1;
	myKnight.step = 1;
	
	
	// set ChessBoard
	totalStep = siz_x * siz_y;
	memset(chessBoard, STUCKED, sizeof(int)*CAPACITY*CAPACITY);
	for (i = 0; i < siz_y; i++)
		memset((*chessBoard+(i*CAPACITY)), 0, sizeof(int)*siz_x);
	
	
	// go tour and notify to main
	return touring(myKnight, 1);
}




/*
 
 // yoon // main
 
 1. get number of cases
 2. run 'knightsTour'. it return 1 or 0
 3. return value 1 means tour being sucessfuly end.
 4. when tour ends successfully, print chessBoard with numbered path.
 
 */
int main() {
	
	int testCases, trip, i, j;
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
		countKnightsAllSteps=0;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n"); // yoon // for static print
#endif
		
		printf("%d\n", trip = knightsTour(siz_x, siz_y, loc_x, loc_y) );
		
		if (trip != FALSE) {
			
			for (i = 0; i < siz_y; i++) {
				for (j = 0; j < siz_x; j++)
					printf("%2d ", chessBoard[i][j]);
				printf("\n");
			}
			
		}// prints chess board when knight finished his trip.
		
	}// all test cases end.
	
	
	return 0;
}
/*
 4
 6 8 3 4
 6 5 1 2
 4 4 1 2
 8 8 3 4
 */



