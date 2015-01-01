//
//  main.c
//  1550
//
//  Created by Yoonseung Choi on 2014. 8. 26..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]) {
	
	int ciphers;
	char ipt[6];
	int toCal[6], dec = 0, rslt = 0;
	
	scanf("%s", &ipt);
	
	for (ciphers = 0; ciphers < 6; ciphers++) {
		
		if (ipt[ciphers]=='\0') break;
		
		else if (122 >= ipt[ciphers]&&ipt[ciphers] >= 97) // a~z
			toCal[ciphers] = ipt[ciphers]-87;
		
		else if (90 >= ipt[ciphers]&&ipt[ciphers] >= 65) // A~Z
			toCal[ciphers] = ipt[ciphers]-55;
		
		else if (57 >= ipt[ciphers]&&ipt[ciphers] >= 49)
			toCal[ciphers] = ipt[ciphers]-48;
		else
			toCal[ciphers] = 0;
	}
	
	while (ciphers-->0)
		rslt+= toCal[ciphers]*pow(16, dec++);
	
	printf("%d", rslt);
	
    return 0;
}
