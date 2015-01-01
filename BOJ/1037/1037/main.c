

#include <stdio.h>
#include <stdlib.h>

int downhill (void *first, void *second) {
	return (*(int*)first < *(int*)second) ? 1 : -1;
}
int main(int argc, const char * argv[]) {
	
	int length, i, arr[51];
	
	scanf("%d", &length);
	for (i = 0; i < length; i++)
		scanf("%d", &arr[i]);
	qsort(arr, length, sizeof(int), downhill);
	printf("%d\n", arr[0]*arr[length-1]);
    return 0;
}