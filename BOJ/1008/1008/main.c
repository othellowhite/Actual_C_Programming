//
//  main.c
//  1008
//
//  Created by Yoonseung Choi on 2014. 8. 21..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
	double val, toDiv;
	
	scanf("%lf %lf", &val, &toDiv);
	printf("%.10lf", val/toDiv);
	
    return 0;
}
