//
//  main.c
//  n003_ASCIIprint-1.0.0
//
//  Created by Yoonseung Choi on 2014. 2. 8..
//  Copyright (c) 2014년 Yoonseung Choi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
	int i = 33;
	for (; i<=126; i++) printf("%c %d %o 0x%x\n", i, i, i, i);
    return 0;
}

