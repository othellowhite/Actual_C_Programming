

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int fibo_recursively(int n);
int fibo_repeatedly(int n);

int main(int argc, const char * argv[]) {
	
	int ipt;
	clock_t bgn, end;
	
	if (argc!=2) {
		printf("worng Arg.\n");
		exit(1);
	}
	else ipt = atoi(argv[1]);
	ipt = 100000;
	
	printf("Do Fibonacci(%d)\n\n", ipt);
	
	bgn = clock();
	//printf("1. reculsively\t-> result : %d \n", fibo_recursively(ipt));
	end = clock();
	printf(" >>> elapsed time : %d msec\n\n", (int)(end - bgn));
	
	bgn = clock();
	printf("2. repeatedly\t-> result : %d \n", fibo_repeatedly(ipt));
	end = clock();
	printf(" >>> elapsed time : %d msec\n\n", (int)(end - bgn));
	
    return 0;
}


int fibo_recursively(int n) {
	
	if (n <= 1) return n;
	else return fibo_recursively(n-1) + fibo_recursively(n-2);
}

int fibo_repeatedly(int n) {
	int i;
	int x_o_o = 1;
	int o_x_o = 1;
	int o_o_x = n;
	
	if (n <= 2) return 1;
	
	for (i = 2; i < n ; i++) {
		o_o_x = x_o_o + o_x_o;
		x_o_o = o_x_o;
		o_x_o = o_o_x;
	}
	return o_o_x;
}
