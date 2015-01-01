
#include <stdio.h>

int main(int argc, const char * argv[]) {

	int iptNum, origNum, cycle = 1;
	int first, second;
	
	scanf("%d", &iptNum);
	origNum = iptNum;
	
	while (1) {
		first = iptNum/10;
		second = iptNum%10;
		iptNum = (second*10) + (first + second)%10;
		
		if (iptNum == origNum)
			break;

		else cycle++;
	}
	printf("%d\n", cycle);
    return 0;
}
