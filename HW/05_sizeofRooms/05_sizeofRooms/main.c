
// Kookmin University
// Department of ComputerScience
// 20103390 Yoonseung Choi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define CONSOLE // yoon // for debug
//#define FILEIO

#define CAPACITY 102
#define EMPTY '.'

FILE *filein;

void ErrHandling(char* msg) {
	fputs(msg, stdout);
	fputc('\n', stdout);
	exit(1);
}

char room[CAPACITY][CAPACITY];

void putBreadDropper(int bread, int x, int y) {
	
	room[x][y] = bread;
	
	//right
	if (0<= y+1&&y+1 <=CAPACITY
		&& room[x][y+1]==EMPTY) {
		room[x][y+1]=bread;
		putBreadDropper(bread, x, y+1);
	}
	//down
	if (0<= x+1&&x+1 <=CAPACITY
		&& room[x+1][y]==EMPTY) {
		room[x+1][y]=bread;
		putBreadDropper(bread, x+1, y);
	}
	//left
	if (0<= y-1&&y-1 <=CAPACITY
		&& room[x][y-1]==EMPTY) {
		room[x][y-1]=bread;
		putBreadDropper(bread, x, y-1);
	}
	//up
	if (0<= x-1&&x-1 <=CAPACITY
		&& room[x-1][y]==EMPTY) {
		room[x-1][y]=bread;
		putBreadDropper(bread, x-1, y);
	}
}


int downhill (void *first, void *second) {
	return (*(int*)first < *(int*)second) ? 1 : -1;
}
/* 
  << Bread Shuttle Algorithm... >>
 
 1. find empty room.
 2. if room is empty, put bread shuttle into the room.
 3. bread shuttle will wander and fill the room with numbered bread.
 4. after doing that. all room will fill with breads.
 5. only left thing to do is counting numbered breads.
 
 */

int main() {
	int testCases, x, y;
	char tmpstr[CAPACITY];
	int i, j, bread;
	int bakery[CAPACITY];
	
	
#ifdef FILEIO
	
	if((filein = fopen("input.txt", "r")) == NULL)
		ErrHandling("no input file");
	
	fscanf(filein, "%d", &testCases);
	
#else
	scanf("%d", &testCases);
#endif
	
	while ( testCases --> 0 ) {
		
		bread = '1';
		memset(bakery, 0, sizeof(int)*CAPACITY);
		
		// yoon // scan room
#ifdef FILEIO
		
		fscanf(filein, "%d %d", &x, &y);
		for (i = 0; i < y; i++) {
			fscanf(filein, "%s", &tmpstr);
			memcpy((*room+(i*CAPACITY)), tmpstr, sizeof(char)*strlen(tmpstr));
		 } // set room
		
		
		
		
#else
		scanf("%d %d", &x, &y);
		for (i = 0; i < y; i++) {
			scanf("%s", &tmpstr);
			memcpy((*room+(i*CAPACITY)), tmpstr, sizeof(char)*strlen(tmpstr));
		}
		
		printf(">> room set.\n\n>> ");
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				printf("%c", room[i][j]);
			}
			printf("\n>> ");
		}
		printf("\n>> Now we release Bread Shuttle.\n");
#endif
		
		// yoon // fill room with bread
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				
				if (room[i][j]==EMPTY) {
					putBreadDropper(bread, i, j);
					bread+=1;
				}
				
			}
		}
		
#ifdef CONSOLE // yoon // make sure all room is filled with breads.
		printf("\n>> and now, Bread Shuttle finished his travel.\n\n>> ");
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				printf("%c", room[i][j]);
			}
			printf("\n>> ");
		}
		printf("\n");
#endif
		
		// yoon // count breads.
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++){
				if (room[i][j]!='+') {
					bakery[room[i][j]+1 - '1']++;
				}
			}
		}
		
#ifdef CONSOLE
		printf("\n>> before sort.%d\n>> ", (bread-'1'));
		for (i = 1; i <= bread-'1'; i++) {
			printf("%d ", bakery[i]);
		}
		printf("\n");
	
#endif
		
		printf("%d\n", (bread-'1'));
		qsort(bakery+1, (bread-'1'), sizeof(int), downhill);
		for (i = 1; i < (bread-'1'+1); i++) {
			printf("%d ", bakery[i]);
		}
		printf("\n");
		
	}// test cases end.

	return 0;
}
/*
 4
 
 29 13
 +++++++++++++++++++++++++++++ 
 +.......+.......+...........+ 
 ++++....+++++...+....++++...+ 
 +..+........+...+....+..+...+ 
 +..+++++....+++++....++++...+ 
 +...........+...+....+..+...+ 
 +..++++++++++...++++++..+...+ 
 +..+.........+++........+...+ 
 +..+.........+.+..+++...+...+ 
 +..+.........+.+..+++...+...+ 
 +...+........+.+..+++...+...+ 
 +....+.......+.+........+...+ 
 +++++++++++++++++++++++++++++
 
 5 3
 +++++ 
 +...+ 
 +++++ 
 
 3 3
 +++ 
 +.+ 
 +++
 
 
 10 10
 +.+.+.+.+.
 .+.+.+.+.+
 +.+.+.+.+.
 .+.+.+.+.+
 +.+.+.+.+.
 .+.+.+.+.+
 +.+.+.+.+.
 .+.+.+.+.+
 +.+.+.+.+.
 .+.+.+.+.+
*/