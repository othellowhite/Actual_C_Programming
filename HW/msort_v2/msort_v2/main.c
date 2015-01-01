
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <alloca.h>
#include <string.h>

#define ACTIVE_MAIN

#define MAX_THRESH 4

// non-recur 구현을 위한 디파인 함수
#define STACK_SIZE	(CHAR_BIT * sizeof(size_t))
#define PUSH(low, high)	((void) ((top->leftEnd = (low)), (top->rightEnd = (high)), ++top))
#define	POP(low, high)	((void) (--top, (low = top->leftEnd), (high = top->rightEnd)))
#define	STACK_NOT_EMPTY	(stack < top)

/* Byte-wise swap two items of size SIZE. */
#define SWAP(a, b, size)					\
do {										\
register size_t __size = (size);		\
register char *__a = (a), *__b = (b);	\
do {									\
char __tmp = *__a;					\
*__a++ = *__b;						\
*__b++ = __tmp;						\
} while (--__size > 0);					\
} while (0)

#define min(x, y) ((x) < (y) ? (x) : (y))

typedef struct {
	char *leftEnd;
	char *rightEnd;
}stackNode;

void
msort (void *const pbase, size_t totalElems, size_t size,
	   int (*cmp)(const void *, const void *)) {
}

/*
 // The merge sort divides the array into two sub-arrays, sorts them and then
 // calls merge to merge the two arrays back together.

void merge_sort( int key[], int n )
{
	int j, k, m, *w;
	for( m = 1; m < n; m *= 2 );
	if (m != n)
	{
		printf ("ERROR: Size of the array is not power of 2.");
	}
	else
	{
		w = calloc( n, sizeof(int) );
		for( k = 1; k < n; k *= 2 )
		{
			for( j = 0; j < (n - k); j += 2 * k )
			{
				Merge(key + j, key + j + k, w + j, k, k);
			}
			
			for ( j = 0; j < n; j++) key[j] = w[j];
		}
		free(w);
	}
}
void Merge( int a[], int b[], int c[], int m, int n )
{
	int i = 0, j = 0, k = 0;
	while (i < m && j < n)
	{
		if( a[i] < b[j] )
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
 
	while ( i < m )
	{
		c[k++] = a[i++];
	}
 
	while ( j < n )
	{
		c[k++] = b[j++];
	}
}

*/


#ifdef ACTIVE_MAIN

int uphill (void *first, void *second) {
	return (*(int*)first - *(int*)second) ;
};

int main() {
	int testCases, capacity, i;
	int arr[100];
	
	scanf("%d", &testCases);
	while (testCases-->0) {
		scanf("%d", &capacity);
		for (i = 0; i < capacity; i++) scanf("%d", &arr[i]);
		
		msort(&arr, capacity, sizeof(int), uphill);
		
		for (i = 0; i < capacity; i++) printf("%d ", arr[i]);
		printf("\n");
	}
	
}

#endif

