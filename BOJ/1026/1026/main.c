//
//  main.c
//  1026
//
//  Created by Yoonseung Choi on 2014. 8. 21..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <memory.h>

int main(int argc, const char * argv[]) {
	
	int arrA[101], arrB[101], arrSize, i;
	
	scanf("%d", &arrSize);
	
	for (i = 0; i < arrSize; i++) scanf("%d", &arrA[i]);
	for (i = 0; i < arrSize; i++) scanf("%d", &arrB[i]);
	
	printf("%d", foo(&arrA, &arrB, arrSize, 0));
		
    return 0;
}

int foo(int* mutableArr, int* immutableArr, int siz, int idx) {
	
	int i;
	int arr[siz], minRslt = 9999, getval;
	
	int a;
	
	if (siz==1)
		return mutableArr[0] * immutableArr[idx];
	
	
	for (i = 0; i < siz; i++) {
		
		memcpy(arr, mutableArr,sizeof(int)*siz-i);
		memcpy(arr, mutableArr+idx,sizeof(int)*siz-i);
		
		printf("\n [idx = %d] : ", idx);
		for (a = 0; a < siz-1; a++) {
			printf("%d ", arr[a]);
		}
		
		minRslt = minRslt < mutableArr[i]*immutableArr[idx] + (getval = foo(arr, immutableArr, siz-1, idx+1) )
		? minRslt : getval;
		
	}
	return minRslt;
}