
#include <stdio.h>

#define CAPACITY 5

void foo(int* arr) { // �������迭
	int i;
	for (i = 0;  i < 5; i ++) {
		
		printf("%d", *(arr+i) );
		
	}
	
	printf(" <- function foo\n\n");
}

void foo2(int* arr) { // arr�� main���� dar�� �����ּ�.
	int i, j;
	
	
	for (i = 0; i < CAPACITY; i++) {
		for (j = 0; j < CAPACITY; j++) {
			printf("%d", *(arr + (i*CAPACITY) + j)); // arr[i][j]
		}
	}
	
	printf(" <- function foo2\n ");
}

int main(int argc, const char * argv[]) {
	
	int arr[CAPACITY] = {1,2,3,4,5}, i, j;
	int darr[CAPACITY][CAPACITY] ; //�������迭����!
	int adr;
	
	printf("num = %d, filename = %s, ipt = %s\n\n", argc, argv[0], argv[1]);
	
	printf("address of 'arr[] : '%d\n\n", adr = &arr);
	
	printf("%d", *(arr+0) );
	printf("%d", *(arr+1) );
	printf("%d", *(arr+2) );
	printf("%d", *(arr+3) );
	printf("%d", *(arr+4) );
	printf(" <- main\n");
	
	foo(&arr);
	
	for (i = 0; i < CAPACITY; i++) {
		for (j = 0; j < CAPACITY; j++) {
			darr[i][j]=(i+1);
			printf("%d", darr[i][j]); // �Ҵ�Ȯ��
		}
	}
	
	printf(" <- main\n");
	foo2(&darr);//������ �迭 �����ּҸ� �����.
	
}
