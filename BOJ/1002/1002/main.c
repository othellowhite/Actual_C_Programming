//
//  main.c
//  1002
//
//  Created by Yoonseung Choi on 2014. 8. 21..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {

	int runTimes;
	int p1_x, p1_y, p1_dist;
	int p2_x, p2_y, p2_dist;
	int distanceBetweenTwoPoints;
	
	scanf("%d", &runTimes);
	while (runTimes-->0) {
		
		scanf("%d %d %d %d %d %d", &p1_x, &p1_y, &p1_dist, &p2_x, &p2_y, &p2_dist);
		distanceBetweenTwoPoints = sqrt( pow(p1_x-p2_x, 2) + pow(p1_y-p2_y, 2) );
		
		// case 1 동일원
		if (p1_x==p2_x && p1_y==p2_y && p1_dist==p2_dist)
			printf("-1\n");

		// case 2 접점
		else if (distanceBetweenTwoPoints == p1_dist+p2_dist ||
				 p1_dist == distanceBetweenTwoPoints+p2_dist ||
				 p2_dist == distanceBetweenTwoPoints+p1_dist )
			printf("1\n");

		// case 3 안만남
		else if (distanceBetweenTwoPoints > p1_dist+p2_dist ||
				 p1_dist > distanceBetweenTwoPoints+p2_dist ||
				 p2_dist > distanceBetweenTwoPoints+p1_dist )
			printf("0\n");
		
		// case 4 두점만남
		
		else printf("2\n");
	
	
	}
    return 0;
}
