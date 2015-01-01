

#include <stdio.h>

#define WRONG_CALENDER  -1
#define CONSOLE
//#define FILEIO

int findDoomsday_bf(int M, int N, int x, int y) {
	int years = 1, doomsdayLeftYears = 0;
	int orig_x = x, orig_y = y;
	
	while (1) {
		
		years++;
		x++;
		y++;
		
		if (x%(M+1)==0)		x=1;
		if (y%(N+1)==0)		y=1;
		
#ifdef CONSOLE 
		printf("\n>> today is <%3d,%3d >, %3d years passed.", x, y, years);
#endif
		
		if (x==M&&y==N) {
			printf("\n>> OMG, today is a doomsday. lol.");
			break;
		}
		if (x==orig_x&&y==orig_y) {
			printf("\n>> there's no doomsday. yeah!");
			years=WRONG_CALENDER;
			break;
		}
	}
	if (years != WRONG_CALENDER) {
		doomsdayLeftYears = years-1;
		x=1;y=1;
		while (1) {
			years++;
			x++;
			y++;
			
			if (x%(M+1)==0)		x=1;
			if (y%(N+1)==0)		y=1;
			
			if (x==orig_x&&y==orig_y) {
				printf("\n>> doomsday is %d year, orig year is %d.\n", years, years - doomsdayLeftYears);
				break;
			}
		}
	}
	return years - doomsdayLeftYears;
};

int findDoomsday(int M, int N, int x, int y) {
	return 0;
}
int main() {

	int testCases;
	int M, N, x, y; // yoon // << M, N >> is a doomsday
	
	scanf("%d", &testCases);
	
	while (testCases-->0) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		printf("%d\n", findDoomsday(M, N, x, y));
	}
	
	
	
    return 0;
}
/*

 3
 10 12 3 9
 10 12 7 2
 13 11 5 6
 
*/