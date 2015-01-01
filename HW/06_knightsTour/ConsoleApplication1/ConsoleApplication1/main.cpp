// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi
 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
 
#define CAPACITY    10
#define STUCKED     -1
#define TRUE        1
#define EMPTY       0
#define FALSE       0
 
// + ��� ����ü�� ����� �� ��ġ�� ������ Ƚ���� ���� ������ ������.
struct knight { 
    int x, y;
    int step;
} myKnight;
 
int boardSize;
int chessBoard[CAPACITY][CAPACITY];
 
//	U : up, D : down, L : left, R : right 
//	ULL : up left left

#define ABLE_ULL(knight)    (knight.y-1 >= 0 && knight.x-2 >= 0)
#define ABLE_UUL(knight)    (knight.y-2 >= 0 && knight.x-1 >= 0)
#define ABLE_UUR(knight)    (knight.y-2 >= 0 && knight.x+1 <= CAPACITY)
#define ABLE_URR(knight)    (knight.y-1 >= 0 && knight.x+2 <= CAPACITY)
#define ABLE_DRR(knight)    (knight.y+1 <= CAPACITY && knight.x+2 <= CAPACITY)
#define ABLE_DDR(knight)    (knight.y+2 <= CAPACITY && knight.x+1 <= CAPACITY)
#define ABLE_DDL(knight)    (knight.y+2 <= CAPACITY && knight.x-1 >= 0)
#define ABLE_DLL(knight)    (knight.y+1 <= CAPACITY && knight.x-2 >= 0)
 
#define BORD_ULL(knight)    chessBoard[knight.y-1][knight.x-2]
#define BORD_UUL(knight)    chessBoard[knight.y-2][knight.x-1]
#define BORD_UUR(knight)    chessBoard[knight.y-2][knight.x+1]
#define BORD_URR(knight)    chessBoard[knight.y-1][knight.x+2]
#define BORD_DRR(knight)    chessBoard[knight.y+1][knight.x+2]
#define BORD_DDR(knight)    chessBoard[knight.y+2][knight.x+1]
#define BORD_DDL(knight)    chessBoard[knight.y+2][knight.x-1]
#define BORD_DLL(knight)    chessBoard[knight.y+1][knight.x-2]
 
#define MOVE_ULL(knight)    knight.y -= 1; knight.x -= 2;
#define MOVE_UUL(knight)    knight.y -= 2; knight.x -= 1;
#define MOVE_UUR(knight)    knight.y -= 2; knight.x += 1;
#define MOVE_URR(knight)    knight.y -= 1; knight.x += 2;
#define MOVE_DRR(knight)    knight.y += 1; knight.x += 2;
#define MOVE_DDR(knight)    knight.y += 2; knight.x += 1;
#define MOVE_DDL(knight)    knight.y += 2; knight.x -= 1;
#define MOVE_DLL(knight)    knight.y += 1; knight.x -= 2;
 
#define RSET_ULL(knight)    chessBoard[knight.y][knight.x]=0; knight.y += 1; knight.x += 2; step--;
#define RSET_UUL(knight)    chessBoard[knight.y][knight.x]=0; knight.y += 2; knight.x += 1; step--;
#define RSET_UUR(knight)    chessBoard[knight.y][knight.x]=0; knight.y += 2; knight.x -= 1; step--;
#define RSET_URR(knight)    chessBoard[knight.y][knight.x]=0; knight.y += 1; knight.x -= 2; step--;
#define RSET_DRR(knight)    chessBoard[knight.y][knight.x]=0; knight.y -= 1; knight.x -= 2; step--;
#define RSET_DDR(knight)    chessBoard[knight.y][knight.x]=0; knight.y -= 2; knight.x -= 1; step--;
#define RSET_DDL(knight)    chessBoard[knight.y][knight.x]=0; knight.y -= 2; knight.x += 1; step--;
#define RSET_DLL(knight)    chessBoard[knight.y][knight.x]=0; knight.y -= 1; knight.x += 2; step--;
 
#define RECORD_PATH(knight) chessBoard[knight.y][knight.x]=step; step++;
 
FILE *filein;
 
void ErrHandling(char* msg) {
    fputs(msg, stdout);
    fputc('\n', stdout);
    exit(1);
}

int totalStep; // + ���� ��ǥ�� �ϴ� ������ Ƚ��. ü������ ũ��� �� ���� ����.
 
/*
 // yoon // knightsTour 
  
 >> ABLE_(DST) : �߸��� ��η� ���� �ʰ� �ε����� ���� �������� Ȯ��.
 >> BORD_(DST) : �ش� ��� ü�� ĭ�� ����.
 >> MOVE_(DST) : ���� ������.
 >> RSET_(DST) : �ش� ��η� ���� ���ϹǷ� �Ʊ��� �������� �ٽ� ����.
  
 */
int touring(struct knight dummy, int step) { // yoon // brute-force [recursive]
     
    int isJourneyEnd = FALSE;
     
    if (step==totalStep) {
        RECORD_PATH(dummy);
        return TRUE;
    }
     
	/* +	
		if ( ABLE_ULL(dummy)		- �ش� ��ΰ� ������ �ε����� ���� ����̰� 
		BORD_ULL(dummy)!=STUCKED	- ü���� �ܺη� �Ѿ�� ������  
		BORD_ULL(dummy)==EMPTY )	- ��簡 �ѹ��� �� ���� ���� ���� �� 

			RECORD_PATH(dummy);		- ü���ǿ� ����� �����
			MOVE_ULL(dummy);		- ��縦 �Ű���.

				if ((isJourneyEnd=touring(dummy, step))==FALSE)
				RSET_ULL(dummy);	- ���� ����� ������ �����ߴٸ� �ű� ���� ������

				else isJourneyEnd = TRUE; - ������ �����ٸ� ������ �̸� ��ģ��.
	*/
			
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

int touring_usingStack(struct knight dummy) { // yoon // brute-force [non recursive, using stack]

	struct knight stack[CAPACITY*CAPACITY]={0,};
	int top = 0, isJourneyEnd = FALSE;

	while (TRUE) {

		if (ABLE_ULL(dummy) && BORD_ULL(dummy)!=STUCKED
        && BORD_ULL(dummy)==EMPTY && isJourneyEnd == FALSE) {
			//PUSH_UUL(dummy);
		}

	}

}
int touring_Warnsdorff(struct knight dummy) { // yoon // Warnsdorff's Rule [non recursive]

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
    //return touring_usingStack(myKnight);
    //return touring_Warnsdorff(myKnight);
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
     
    if((filein = fopen("input.txt", "r")) == NULL)
        ErrHandling("no input file");
     
    fscanf(filein, "%d", &testCases);
     
    while ( testCases --> 0 ) {
         
        fscanf(filein, "%d %d %d %d", &siz_y, &siz_x, &loc_y, &loc_x);

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