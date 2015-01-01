//
//  main.c
//  1152
//
//  Created by Yoonseung Choi on 2014. 8. 22..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
	
	char sentence[1000001];
	char* p;
	int rslt=0;
	
	fgets(sentence, 1000001, stdin);
	
	p = strtok(sentence, " ");
	while (p) {
		p=strtok(NULL, " ");
		rslt++;
	}
	
	printf("%d", rslt);
	
    return 0;
}
