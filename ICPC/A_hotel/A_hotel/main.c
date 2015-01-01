
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 A. hotel
 
 - �մ��� �� ���� ȣ�Ǽ��� ���
 
 << ���� >>
 1. �ճ��� �������� ������ '���������Ϳ��� ����� ��'�� ��ȣ�Ѵ�.
 2. ȣ�� ��ȣ�� ���������ͷο� ����� 1���� ���ۿ� ���� Ŀ����.
 3. ������ ����ȣ�Ǽ��� 99�� ���� �ʴ´�.

 << �Է� >>
 1. �׽�Ʈ���̽�
 2. ����, �� �� ȣ�Ǽ�, �մ� ����
 
 << ��� >>
 1. �մ��� �� ���� ȣ�Ǽ�
 
 */

#include <stdio.h>

//#define CONSOLE
#define FILEIO

FILE *infile;

/*
 int weAtTheHotelMotel(int h, int person)
 
 - ȣ���� ���̿� �մ��� ������ �޾ƿ´�
 - �մ��� ���� �� ���� ȣ���� ��ȯ�Ѵ�.
 
 */
int weAtTheHotelMotel(int h, int person) {
	
	int floor, step=0;
	
	while (person/h!=0) {
		person-=h;
		step++;
	}
	floor = person;
	
	if (floor==0) return (h)*100 + (step); // yoon // suite room // ����⿡�� �߲ٳ�
	
	return (floor)*100 + (step+1);
}

/*
 int main()
 
 -	������ �ּ����� C�� �� �� �������� �ִ�.
 
*/
int main(int argc, const char * argv[]) {
	int testCases;
	int h, w, person;// yoon // ��, �������Ǽ�, ����
	
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
