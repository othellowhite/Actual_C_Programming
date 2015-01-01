
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 A. hotel
 
 - 손님이 들어갈 객실 호실수를 출력
 
 << 조건 >>
 1. 손놈은 개을러서 무조건 '엘리베이터에서 가까운 방'을 선호한다.
 2. 호실 번호는 엘리베이터로옆 방부터 1부터 시작여 점점 커진다.
 3. 층수와 층당호실수는 99를 넘지 않는다.

 << 입력 >>
 1. 테스트케이스
 2. 층수, 층 당 호실수, 손님 순번
 
 << 출력 >>
 1. 손님이 들어갈 객실 호실수
 
 */

#include <stdio.h>

//#define CONSOLE
#define FILEIO

FILE *infile;

/*
 int weAtTheHotelMotel(int h, int person)
 
 - 호텔의 높이와 손님의 순번을 받아온다
 - 손님이 들어가게 될 객실 호수를 반환한다.
 
 */
int weAtTheHotelMotel(int h, int person) {
	
	int floor, step=0;
	
	while (person/h!=0) {
		person-=h;
		step++;
	}
	floor = person;
	
	if (floor==0) return (h)*100 + (step); // yoon // suite room // 꼭대기에선 삐꾸남
	
	return (floor)*100 + (step+1);
}

/*
 int main()
 
 -	가끔은 주석보다 C가 더 잘 읽힐때도 있다.
 
*/
int main(int argc, const char * argv[]) {
	int testCases;
	int h, w, person;// yoon // 층, 층별객실수, 순번
	
#ifdef FILEIO
	if((infile = fopen("input.txt", "r"))==NULL) exit(1);;
	fscanf(infile, "%d", &testCases);
#else
	scanf("%d", &testCases);
#endif
	
	while (testCases-->0) {
		
#ifdef FILEIO
		fscanf(infile, "%d %d %d", &h, &w, &person);
#else
		scanf("%d %d %d", &h, &w, &person);
#endif
		printf("%d\n", weAtTheHotelMotel(h, person));
	}
	
    return 0;
}

/* ipt
 
 9
 6 12 5
 6 12 6
 6 12 7
 6 12 10
 6 12 11
 6 12 12
 6 12 13
 6 12 14
 30 50 72
 
 */

/* opt
 
 402
 1213
 
 */
