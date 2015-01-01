
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 C. grid
 
 - ����̵� �׷������� ����Ŭ�� ������
 
 << ���� >>
 1. ��� ������ ������ �ѹ��� ��´�.
 2. ����Ŭ�̶�°� ���� ó�� ���������� ���ư��°� ���ϴ°Ű���?
 3. ����̵�׷��� ��Ʈ���� ũ��� 100�� ���� �ʾ�.
 
 << �Է� >>
 1. �׽�Ʈ���̽�
 2. ����̵�׷��� ��Ʈ���� ũ��(x,y)
 
 << ��� >>
 1. �� ���� ����
 2. �� ���� �� ����Ŭ �̵�����
 
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
 
 -	�����ڴ� �����¿������ ���� �ɰž�.
	���� ������ �ݴ� �ǳ������� ���Եɰž�
	�����ϸ鼭 ������ ������ ����.
	�� �̻� �� ���� ������ ������ ����� ����.
 
	basecase�� ����Ƚ���� ��Ʈ���� ũ�Ⱑ �����ϰ�, 
	�����¿� �� �ϳ��� ������.
 
	<< Ư�� ���̽����� �ʹ� ���� �ɸ��� ������ �ִ�. ���� �ش� ���������� ������� �ʴ´�. >>
 
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
		
		// ������⼱��
		xToGo = myTraveler.xpos + direction[i][X];
		yToGo = myTraveler.ypos + direction[i][Y];
		
		// ���� ����� ��
		if (xToGo == x_width) xToGo = 0;
		if (xToGo == -1) xToGo = x_width-1;
		if (yToGo == y_axis) yToGo = 0;
		if (yToGo == -1) yToGo = y_axis-1;
		
		// ������� ���� ���� ��
		if (mat[yToGo][xToGo] == EMPTY) {
			
			mat[yToGo][xToGo] = 'O';
			xBack = myTraveler.xpos;
			yBack = myTraveler.ypos;
			myTraveler.xpos = xToGo;
			myTraveler.ypos = yToGo;
			
			// ����������� ����Ŭ�� �ϼ���.
			if((travelEnds = gridTraversal_Bruteforce())==TRUE) break;
			else {
				// ��������� �߸���. �ٽ� ����.
				mat[myTraveler.ypos][myTraveler.xpos] = EMPTY;
				myTraveler.xpos =xBack;
				myTraveler.ypos =yBack;
				myTraveler.step--;

			}
		}
		// �� ������ ��
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
 
 -	��� �ش� �������� false�� �����ϴ� ���� ����.
	ġ�������� �츰 �ٻ� ����̴�, �׳� �� �� �ִ� ��� �� �ϳ��� ����ϰ� ��� �ϳ��� ���� �ھƹ�����.
 
 */
void gridTraversal_Nasty(int x_width, int y_axis){
	int i, j; // i �� x�� idx, j �� y�� idx
	
	printf("1\n");
	
	for (i = 0; i < x_width; i++)
		printf("(0,%d)\n", i);
	

	for (i = x_width-1 ; i >= 0 ; i--) {
		// idx�� 0���� �����ϴ� "x%2==0"�̸� Ȧ�����̴�.
		
		if (i%2 != 0) { // ¦���� �� �Ʒ��� �ٽ� ��������
			for (j = 1; j < y_axis; j++)
				printf("(%d,%d)\n", j, i);
		}
		else {	// Ȧ���� ���� ���� �ö󰡿�
			for (j = y_axis-1; j >= 1 ; j--)
				printf("(%d,%d)\n", j, i);
		}
		
	}

	return;
}


/*
 int main()
 
 -	������ �ּ����� C�� �� �� �������� �ִ�.
 
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
		
		//if (gridTraversal_Bruteforce()==FALSE) printf("-1\n"); // yoon // Ư�� ���̽����� �ð��� �ʹ� �����ɸ�
		gridTraversal_Nasty(x_width, y_axis);

	}
}






