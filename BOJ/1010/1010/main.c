//
//  main.c
//  1010
//
//  Created by Yoonseung Choi on 2014. 8. 21..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

long long combi(int n, int r) {
	
	long long rslt=1;
	int i;
	
	if( n-r < r )
		r = n-r;
	
	for( i = 1; i <= r; i++ )
	{
		rslt *= (n-r+i);
		rslt /= i;
	}
	
	return  rslt;
}

int main(int argc, const char * argv[]) {

	int runTimes, n, r;
	
	scanf("%d", &runTimes);
	while (runTimes-->0) {
		
		scanf("%d %d", &r, &n);
		printf("%lld \n", combi(n,r));
	
	}
	
    return 0;
}