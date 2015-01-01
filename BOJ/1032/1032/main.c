//
//  main.c
//  1032
//
//  Created by Yoonseung Choi on 2014. 8. 22..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
	
	int runTimes, i;
	unsigned long strLeng, patternLeng = 52;
	char str[51], strToCmp[51];
	
	scanf("%d", &runTimes);
	
	//fgets(str, sizeof(str), stdin);
	scanf("%s", str);
	strLeng = strlen(str);
	patternLeng = strLeng;
	
	while (runTimes-->1) {
		
		//fgets(strToCmp, sizeof(str), stdin);
		scanf("%s", strToCmp);
		
		strLeng = strlen(str);
		patternLeng = strLeng < patternLeng ? strLeng : patternLeng;
		
		for (i = 0; i < patternLeng; i++) {
			if (str[i]!=strToCmp[i]) str[i]='?';
		}
	}
	
	for (i = 0; i < patternLeng; i++) {
		printf("%c", str[i]);
	}
	
    return 0;
}
