// LCM

#include <stdio.h>

int GCD(int a, int b) {
	//printf(">> %d %d\n", a, b);
	if (b==0) return a;
	else return GCD(b, a%b);
};

int main(int argc, const char * argv[]) {
	int testCases;
	int a, b;
	
	scanf("%d", &testCases);
	
	while (testCases-->0) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a*b/GCD(a,b));
	}
	
}
