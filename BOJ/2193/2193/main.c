//
//  main.c
//  2193
//
//  Created by Yoonseung Choi on 2014. 8. 22..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

/*
int pinary(int boolean, int currentLevel) {
	
	if (currentLevel==givenCiphers) {
		
		switch (boolean) {
			case 0: return 2;
			case 1: return 1;
		}
	}
	else {
		
		switch (boolean) {
			case 0: return pinary(1, currentLevel+1)+pinary(0, currentLevel+1);
			case 1: return pinary(0, currentLevel+1);
		}
	}
	return 0;
}// heavy jobtime
*/
/*
int fibo(int num){
	if(num == 0) return 0;
	else if(num == 1) return 1;
	else return fibo(num-1) + fibo(num-2);
}
*/

unsigned long long fibo(int num) {
	int i ;
	unsigned long long head = 0;
	unsigned long long mid = 0;
	unsigned long long rear = 1;
	
	
	for(i = 1 ; i < num ; i++){
		mid = head+rear;
		head = rear;
		rear = mid;
	}
	return head;
}

int main(int argc, const char * argv[]) {
	
	int givenCiphers;
	int idx_0, idx_1;
	scanf("%d", &givenCiphers);
	
	idx_0 = givenCiphers;
	idx_1 = givenCiphers - 1;
	
	if (givenCiphers==1 ||
		givenCiphers == 2) {
		printf("1");
	}
	else printf("%lld", fibo(idx_1)+ fibo(idx_0));
	
    return 0;
}
