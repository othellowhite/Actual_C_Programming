//
//  main.c
//  1212
//
//  Created by Yoonseung Choi on 2014. 8. 26..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long toBin (unsigned long dec, unsigned long ciphers);

int main(int argc, const char * argv[]) {

	char oct[333335];
	int  i=0;
	unsigned long ciphers, dec = 0;
	
	scanf("%s", &oct);
	ciphers = strlen(oct);
	
	while (ciphers-->0) {
		if(49<=oct[ciphers]&&oct[ciphers]<=57)
			dec += (oct[ciphers]-48)*pow(8, i++);
		else i++;
	}

	printf("%d", toBin(dec, ciphers) );
	
    return 0;
}

unsigned long long toBin (unsigned long dec, unsigned long ciphers) {
	int i = 0;
	
	for (i = 0; dec>0; i++) {
		bin[i] = dec%2;
		dec/=2;
	}
	i--;
	for (; i>=0; i--)
		printf("%d", bin[i]);
	
	return 0;
}


