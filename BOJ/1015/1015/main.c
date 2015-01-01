//
//  main.c
//  1015
//
//  Created by Yoonseung Choi on 2014. 8. 21..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
	
	int i, j, idxOfMinValue, Capacity;
	int arrToSort[1001], tmpForSwap;
	
	scanf("%d", &Capacity);
	tmpForSwap = Capacity;
	
	for (i = 0; i < Capacity; i ++) scanf("%d", &arrToSort[i]);
	
	for (i = 0; i < Capacity; i++) {
		idxOfMinValue = i;
		
		for (j = i + 1; j < Capacity; j++) {
			
			if (arrToSort[j] <= arrToSort[idxOfMinValue])
				idxOfMinValue = j;
			
		}
		
		//swap value
		tmpForSwap		= arrToSort[i];
		arrToSort[i]	= arrToSort[idxOfMinValue];
		arrToSort[idxOfMinValue] = tmpForSwap;
		
	}
	
	for (i = 0; i < Capacity; i ++) printf("%d", arrToSort[i]);
	
	
    return 0;
}
