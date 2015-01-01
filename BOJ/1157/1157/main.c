//
//  main.c
//  1157
//
//  Created by Yoonseung Choi on 2014. 8. 22..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int StrUpr( char *str )
{
	int loop = 0;
	while( str[loop] != '\0' ) {
		if( str[loop] >= 97 && str[loop] <= 122 )
			str[loop] = str[loop] - 32;
		loop++;
	}
	return loop;
}

int main(int argc, const char * argv[]) {
	
	char str[1000001];
	int alphabet[26], strLeng, i, maxVal=0, maxIdx = 0, flag;
	
	memset(alphabet, 0, sizeof(int)*26);
	
	scanf("%s", &str);
	strLeng = StrUpr(str);
	
	for (i = 0; i < strLeng; i++) alphabet[str[i]-'A']++;

	maxIdx = 0;
	maxVal = alphabet[0];
	flag= 0;
	
	for (i = 1; i < 26; i++) {
		if (alphabet[i]==maxVal) {
			flag = 1;
		}
		else if (alphabet[i] > maxVal) {
			flag = 0;
			maxVal = alphabet[i];
			maxIdx = i;
		}
	}
	if (flag==1) printf("?");
	else printf("%c", maxIdx+'A');
	
    return 0;
}

// a = 65 A = 97

/*
 
	int a = 'a', A = 'A';
	printf("%d %d\n", a, A);
*/