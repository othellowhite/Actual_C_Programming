//
//  main.c
//  1039
//
//  Created by Yoonseung Choi on 2014. 8. 22..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
	
	int iptVal, swapTimes;
	int num[7], tmpArr[7], numLen=0, tmp;
	int i, didSwap=0;
	int maxVal, maxIdx, cnt = 0, err = -1;
	
	scanf("%d %d", &iptVal, & swapTimes);
	
	// 숫자를 배열로
	while (iptVal%10 != 0) {
		tmpArr[numLen++] = iptVal%10;
		iptVal /= 10;
	}
	
	// 배열을 원래 숫자모양으로
	tmp = numLen;
	i = 0;
	while (tmp-->0) {
		num[i++] = tmpArr[tmp];
	}
	
	//
	while (swapTimes != cnt) {
		maxVal = num[didSwap];
		maxIdx = didSwap;
		
		if (didSwap) {
			
		}
		
		for (i = didSwap+1; i < numLen; i++) {
			if (maxVal < num[i]) {
				maxIdx = i;
				maxVal = num[i];
			}
		}
		
		if (maxIdx != didSwap) {
			num[maxIdx] = num[didSwap];
			num[didSwap] = maxVal;
			didSwap++;
			cnt++;
		}
		else if(didSwap==numLen-1) break;
		
		else
		{
			didSwap++;
		}
	}
	
    return 0;
}
