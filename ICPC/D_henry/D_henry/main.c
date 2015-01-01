
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 D. henry
 
 -	�ڸ��� �м��� �ʹ� �����Ѵ�. �μ����� �ع����� �ʹ�.
	�ڸ��м��� ���ϸ� 5/7 = 1/2 + 1/5 + 1/70 �̴�. �߰ߵǴ� ������ �� �����̴�.
	���⼭ ���� ū �и���� '70'�̴�.
	�ƹ�ư �м��� ������ �ڸ� �м��� '���� ū �и��'�� ����Ѵ�.
 
 << ���� >>
 1. 1/3+1/3�� �ڸ��м��� �ƴϴ�.
 2. ���ڰ� 1�� �ƴϸ� �ڸ��м��� �ƴϴ�.
 3. �Էµ� ����, �и�� 10000���� �۴�
 
 << �Է� >>
 1. �׽�Ʈ���̽�
 2. ����, �и�
 
 << ��� >>
 1. �ڸ��м��� '���� ū �и��'
 
 */

#include <stdio.h>

#define CONSOLE
//#define FILEIO

FILE* infile;


/*
 int henry(int child, int mother)
 
 -	�и� �޾� �ڸ��м��� ���� ū �и���� ��ȯ�Ѵ�.
	����� ������ ����.
 
	1) 1/2���� �и� 1�� �ø��� �������� ��
	2) ���� �м��� ��, ������ �� �м��� ���Ѵ�.
	3) ���⼭ �� ���� ������.
		basecase - ���ڰ� 1�̸� ���⼭�� �и� ���� ��ȯ
		rcurstep - �� �ܿ� �ٽ� �ڸ��� ������
 
 */
unsigned long long henry (unsigned long long child, unsigned long long mother, unsigned long long mkHenryNum) {

	// �� �κ��� ����
	mkHenryNum = mother/child ;
	while (child*(mkHenryNum) < mother){
		// printf("."); // yoon // for count calcCnt
		mkHenryNum++;
	}
	
	child = (child*mkHenryNum) - mother;
	mother *= mkHenryNum;
	
#ifdef CONSOLE
	printf(">> sub 1/%llu, %llu/%lluleft\n", mkHenryNum, child, mother);
#endif
	
	if (child == 1) return mother ; // basecase
	else if (child == 0) return mkHenryNum; // yoon // basecase // �Ʊ� ���� 1
	return henry(child, mother, mkHenryNum+1); // recur step
}
/*
 int main()
 
 - ������ �ּ����� C�� �� �� �������� �ִ�.
 
 */

int main(int argc, const char * argv[]) {
	
	int testCases;
	int child, mother;
	
#ifdef FILEIO
	if((infile = fopen("input.txt", "r"))==NULL) exit(1);;
	fscanf(infile, "%d", &testCases);
#else
	scanf("%d", &testCases);
#endif
	
	while (testCases-->0) {
		
#ifdef FILEIO
		fscanf(infile, "%d %d", &child, &mother);
#else
		scanf("%d %d", &child, &mother);
#endif
		
		printf("%llu\n", henry(child, mother, 2));
		
	}
	
    return 0;
}
/* ipt

 3
 4 23 
 5 7 
 8 11
 
*/

/* opt
138
70
4070
*/