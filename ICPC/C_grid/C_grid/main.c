
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 C. grid
 
 - 토로이드 그래프에서 사이클을 만들어보자
 
 << 조건 >>
 1. 모든 정점은 무조건 한번만 찍는다.
 2. 사이클이라는건 물론 처음 시작점으로 돌아가는걸 말하는거겠지?
 3. 토로이드그래프 매트릭스 크기는 100을 넘지 않아.
 
 << 입력 >>
 1. 테스트케이스
 2. 토로이드그래프 매트릭스 크기(x,y)
 
 << 출력 >>
 1. 해 존재 여부
 2. 해 있을 때 사이클 이동방향
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define CONSOLE
#define FILEIO

#define CAPACITY 101

#define UP		{-1, 0}
#define DOWN	{ 1,-0}
#define LEFT	{ 0,-1}
#define RIGHT	{ 0, 1}

#define EMPTY	'.'
#define FALSE	0
#define TRUE	1
#define Y		0
#define X		1

FILE* infile;

int y_axis, x_width;
char mat[CAPACITY][CAPACITY];

int count = 0;

struct traveler {
	int xpos, ypos;
	int step;
}myTraveler;

/*
void gridTraversal_Bruteforce()
 
 -	여행자는 상하좌우순으로 돌게 될거야.
	벽에 닿으면 반대 건너편으로 가게될거야
	진행하면서 지도에 흔적을 남김.
	더 이상 갈 데가 없으면 흔적을 지우고 복귀.
 
	basecase는 진행횟수와 메트릭스 크기가 동일하고, 
	상하좌우 중 하나가 시작점.
 
	<< 특정 케이스에서 너무 오래 걸리는 문제가 있다. 따라서 해당 문제에서는 사용하지 않는다. >>
 
 */
int gridTraversal_Bruteforce() {
	
	int xToGo, yToGo, i;
	int xBack, yBack;
	int direction[4][2] = {UP, RIGHT, DOWN,  LEFT};
	int travelEnds = FALSE;
	
	myTraveler.step++;
	
	printf("%d\n", count++);
	
#ifdef CONSOLE
	int j;
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf(">> ");
		for (j = 0; j < 10; j++) {
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
#endif

	
	for (i = 0; i < 4; i++) {
		
		// 진행방향선택
		xToGo = myTraveler.xpos + direction[i][X];
		yToGo = myTraveler.ypos + direction[i][Y];
		
		// 벽에 닿았을 시
		if (xToGo == x_width) xToGo = 0;
		if (xToGo == -1) xToGo = x_width-1;
		if (yToGo == y_axis) yToGo = 0;
		if (yToGo == -1) yToGo = y_axis-1;
		
		// 진행방향 진행 가능 시
		if (mat[yToGo][xToGo] == EMPTY) {
			
			mat[yToGo][xToGo] = 'O';
			xBack = myTraveler.xpos;
			yBack = myTraveler.ypos;
			myTraveler.xpos = xToGo;
			myTraveler.ypos = yToGo;
			
			// 진행방향으로 사이클을 완성함.
			if((travelEnds = gridTraversal_Bruteforce())==TRUE) break;
			else {
				// 진행방향이 잘못됨. 다시 복귀.
				mat[myTraveler.ypos][myTraveler.xpos] = EMPTY;
				myTraveler.xpos =xBack;
				myTraveler.ypos =yBack;
				myTraveler.step--;

			}
		}
		// 다 돌았을 시
		else if (myTraveler.step == y_axis*x_width
				 && xToGo == 0 && yToGo == 0){
			printf("1\n");
			return TRUE;
		}
		
	}
	
	if (travelEnds==TRUE) {
		printf("(%d,%d)\n", xToGo, yToGo);
		return TRUE;
	}
	return FALSE;
}

/*
 void gridTraversal_Nasty()
 
 -	사실 해당 문제에서 false를 리턴하는 경우는 없다.
	치사하지만 우린 바쁜 사람이니, 그냥 돌 수 있는 방법 중 하나를 출력하게 방법 하나를 때리 박아버린다.
 
 */
void gridTraversal_Nasty(int x_width, int y_axis){
	int i, j; // i 는 x축 idx, j 는 y축 idx
	
	printf("1\n");
	
	for (i = 0; i < x_width; i++)
		printf("(0,%d)\n", i);
	

	for (i = x_width-1 ; i >= 0 ; i--) {
		// idx가 0부터 시작하니 "x%2==0"이면 홀수열이다.
		
		if (i%2 != 0) { // 짝수일 땐 아래로 다시 내려가용
			for (j = 1; j < y_axis; j++)
				printf("(%d,%d)\n", j, i);
		}
		else {	// 홀수일 때엔 위로 올라가용
			for (j = y_axis-1; j >= 1 ; j--)
				printf("(%d,%d)\n", j, i);
		}
		
	}

	return;
}


/*
 int main()
 
 -	가끔은 주석보다 C가 더 잘 읽힐때도 있다.
 
 */
int main() {
	
	int testCases, i, result;
	
#ifdef FILEIO
	if( (infile = fopen("input.txt", "r"))==NULL ) exit(1);
	fscanf(infile, "%d", &testCases);
#else
	scanf("%d", &testCases);
#endif
	
	while (testCases-->0) {
		
#ifdef FILEIO
		fscanf(infile, "%d %d", &y_axis, &x_width);
#else
		scanf("%d %d", &x_width, &y_axis);
#endif
		
		memset(mat, 'X', sizeof(char)*CAPACITY*CAPACITY);
		for (i = 0; i < y_axis; i++)
			memset(*(mat+i), '.', sizeof(char)*x_width);
		
		myTraveler.xpos = 0;
		myTraveler.ypos = 0;
		myTraveler.step = 0;
		mat[0][0]='O';
		
		//if (gridTraversal_Bruteforce()==FALSE) printf("-1\n"); // yoon // 특정 케이스에서 시간이 너무 오래걸림
		gridTraversal_Nasty(x_width, y_axis);

	}
}






