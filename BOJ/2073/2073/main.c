//
//  main.c
//  2073
//
//  Created by Yoonseung Choi on 2014. 8. 21..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
	int dist, pipes;
	int diArr[351], ciArr[351];
	int i, j, ciMax=0;
	
	scanf("%d %d", &dist, &pipes);
	
	for (i = 0; i < pipes; i++) {
		scanf("%d %d", &diArr[i], &ciArr[i]);
	}
	
	
	for (i = 0; i < pipes; i++) {
		for (j = 0; j < pipes; j++) {
			
			if ( (i!=j) && (diArr[i]+diArr[j]==dist) )
					ciMax = (ciArr[i] > ciArr[j] ? ciArr[j]:ciArr[i]) < ciMax ?
					ciMax : (ciArr[i] > ciArr[j] ? ciArr[j]:ciArr[i]);
				
			
		}
	}
	
	printf("%d", ciMax);
	
    return 0;
}
