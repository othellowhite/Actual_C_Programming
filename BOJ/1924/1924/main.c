
#include <stdio.h>

int main(int argc, const char * argv[]) {
	// 2007 1 1 : mon
	
	int mn, dy, i;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int monthName[7][4]={
		{'S','U','N','\0'},
		{'M','O','N','\0'},
		{'T','U','E','\0'},
		{'W','E','D','\0'},
		{'T','H','U','\0'},
		{'F','R','I','\0'},
		{'S','A','T','\0'}};
	int bgnDays=0;
	
	scanf("%d %d", &mn, &dy);
	
	for (i = 1; i < mn; i++) {
		bgnDays+=month[i];
	}
	bgnDays+=dy;
	for (i = 0; i < 3; i++)
		printf("%c", monthName[bgnDays%7][i]);
	printf("\n");

    return 0;
}
