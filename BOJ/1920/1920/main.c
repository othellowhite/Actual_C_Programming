
#include <stdio.h>
#include <stdlib.h>


int uphill (void *first, void *second) {
	return (*(int*)first - *(int*)second) ;
};


int main(int argc, const char * argv[]) {
	int arrLeng, testCases, toFind, i;
	int arr[100001];
	
	scanf("%d", &arrLeng);
	for (i = 0; i < arrLeng; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &testCases);

	qsort(arr, arrLeng, sizeof(int), uphill);
	while (testCases-->0) {
		scanf("%d", &i);
		printf("%d", bsearch(, <#const void *#>, <#size_t#>, <#size_t#>, <#int (*)(const void *, const void *)#>));
	}

	
    return 0;
}
