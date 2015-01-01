
// Kookmin Univ. Dept. of CS
// 20103390 Yoonseung Choi

/*
 
 G. mutation
 
 - �߲ٳ� ���⼭���� ������ �ȿ� ��� �� �ֳ� ���
 
 << ���� >>
 1. �������� 1000000������, �߲ٳ� ���⼭���� 100������
 
 << �Է� >>
 1. �׽�Ʈ���̽�
 2. ����������, �߲ٳ� ���⼭������
 
 << ��� >>
 1. ������ �� �߲ٳ� ���⼭�� ���� ����
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define CAPACITY 1000001

#define A 0
#define G 1
#define T 2
#define C 3

#define RM_1ST_MRK	\
if (sequence[i-1]=='A') mutatableMarker[A]--;		\
else if (sequence[i-1]=='G') mutatableMarker[G]--;	\
else if (sequence[i-1]=='T') mutatableMarker[T]--;	\
else if (sequence[i-1]=='C') mutatableMarker[C]--;

#define ADD_NEW_MRK		\
if (sequence[i+mrkLen-1]=='A') mutatableMarker[A]++;		\
else if (sequence[i+mrkLen-1]=='G') mutatableMarker[G]++;	\
else if (sequence[i+mrkLen-1]=='T') mutatableMarker[T]++;	\
else if (sequence[i+mrkLen-1]=='C') mutatableMarker[C]++;

#define CMP_SEQ \
if ( mutatableMarker[A]==a	\
&& mutatableMarker[G]==g	\
&& mutatableMarker[T]==t	\
&& mutatableMarker[C]==c )	countMutableStr++;

char* sequence;
int count;

/*
 int dnaCompare(int a, int g, int t, int c , int seqLen, int mrkLen) {
 
 -	���� �ܼ��ϰ� ���� ����� �ִ�. 
	sequence�� ó������ marker ���̸�ŭ �������� �� ��,
	�ű�ȿ� �ִ� ��� ���⼭�� ������ ã�Ƴ�. 
	�ϸ� mutetion �غ��� ������ ������ ���ƾ� �ϴϱ�. <- Ű����Ʈ !!
	�׸��� ���� �������� 1 �� ������Ű�鼭 ���⼭�� ������ üũ�ϸ� �ȴ�.
	�ð����⵵ n = strlen(sequence);

 */
int dnaCompare(int a, int g, int t, int c , int seqLen, int mrkLen) {
	
	int i , countMutableStr = 0;
	int mutatableMarker[4] = {0,};
	int j;
	
	
	// yoon // init mutableMarker arr
	for (i = 0; i < mrkLen; i++) {
		if (sequence[i]=='A') mutatableMarker[A]++;
		else if (sequence[i]=='G') mutatableMarker[G]++;
		else if (sequence[i]=='T') mutatableMarker[T]++;
		else if (sequence[i]=='C') mutatableMarker[C]++;
	}
	
	printf("current scope[%d] : \n %c {", 0, 'X');
	for(j = 0; j < mrkLen; j++)printf("%c ", sequence[j]);
	printf("}%c\n", sequence[j]);
	
	// yoon // cmp first seq scope
	CMP_SEQ;
	
	
	/*
	 1. ������ �������� �ű�. 
	 2. �׿� ���ÿ� mutableMarker ���� �� �����̶� ���� ���� ���� ���Ұ� ���ϰ�
	 3. ���� �� �� ������ ����, ������ ����.
	 */
	for (i = 1; i <= seqLen - mrkLen; i++) {
		
		// yoon // move scope & set mutableMarker
		RM_1ST_MRK;
		ADD_NEW_MRK;
		
		printf("current scope[%d] : \n %c {", i, sequence[i-1]);
		for(j = 0; j < mrkLen; j++)printf("%c ", sequence[i+j]);
		printf("}%c\n", sequence[i+j]);
		
		// yoon // mutation comparing
		CMP_SEQ;
	}
	
	return countMutableStr;
}
/*
 int main()
 */

int main() {
	int testCases, i;
	int seqLen, mrkLen;
	int a, g, t, c;
	
	char marker[101];
	sequence = (char*)malloc(sizeof(char)*CAPACITY);
	// yoon // ������ �ʹ� ��� �迭�� ������ �ȵȴ�. �����Ҵ�����  �� ������ ������ ������ �д�.
	
	scanf("%d", &testCases);
	while (testCases-->0) {
		
		scanf("%d %d", &seqLen, &mrkLen); // ������ ����, ��Ŀ ���� �Է�
		
		memset(sequence,'\0', sizeof(char)*seqLen+1);
		a = 0;  g = 0; t = 0; c = 0;
		count = 0;
		
		
		scanf("%s", sequence); // yoon // �̰� �� �� ����. �� Ǯ����� ���⵵ ���غ���
		scanf("%s", &marker);
		
		for (i = 0; i < mrkLen; i++) {
			if (marker[i]=='A') a++;
			else if (marker[i]=='G') g++;
			else if (marker[i]=='T') t++;
			else if (marker[i]=='C') c++;
		}
		memset(marker, '\0', sizeof(char)*101);
		
		//dnaCompare_mkTree(a,g,t,c,marker,0);
		//printf("%d\n", count);
		
		printf("%d\n", dnaCompare(a, g, t, c, seqLen, mrkLen));
	}
}

/* ipt
 
 3
 6 4 
 ATGGAT 
 AGGT 
 6 4 
 ATGGAT AGCT
 17 4
 ATGGATATGGATATGGA
 AGGT
 17 5
 ATGGATATGGATATGGA
 AGGTA
 */


/* opt
3
0
*/

/*
 void dnaCompare_mkTree(int a, int g, int t, int c, char* marker, int lv)
 - ���⼭�� ������ ����, ������ ���⹮��迭, �Լ����Ƚ�� �� �޾ƿ´�
 - �������� �ش� ���Ⱑ ������ count ������ �����Ѵ�.
 
 << Ʈ���� �����ؼ� ��Ʈ�� ����� �ϴ°� ���� '����'�̴�. ������ �� �ۿ� ���� ����. ���� �������� ������� �ʴ´�. >>
 */
void dnaCompare_mkTree(int a, int g, int t, int c, char* marker, int lv) {
	
	if (a != 0) {
		marker[lv] = 'A';
		dnaCompare_mkTree(a-1, g, t, c, marker, lv+1);
	}
	if (g != 0) {
		marker[lv] = 'G';
		dnaCompare_mkTree(a, g-1, t, c, marker, lv+1);
	}
	if (t != 0) {
		marker[lv] = 'T';
		dnaCompare_mkTree(a, g, t-1, c, marker, lv+1);
	}
	if (c != 0) {
		marker[lv] = 'C';
		dnaCompare_mkTree(a, g, t, c-1, marker, lv+1);
	}
	
	//if (a==0 && t==0 && c==0 && g==0) printf("%s\n", marker);
	if (a==0 && t==0 && c==0 && g==0
		&& strstr(sequence, marker)!=NULL)
		count ++;
}