//
//  main.c
//  simpleFiboacci
//
//  Created by Yoonseung Choi on 2014. 8. 22..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

int main(void){
	int i ;
	int num;
	unsigned long long head = 0;
	unsigned long long mid = 0;
	unsigned long long rear = 1;
	
	printf("\n 피보나치 수 입력 : \n");
	scanf("%d" , &num) ;
	
	for(i = 1 ; i < num ; i++){
		printf("%lld " , head) ;
		mid = head+rear;
		head = rear;
		rear = mid;
	}
	
	printf("\n\n");
	
	return 0 ;
}