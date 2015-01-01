#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define CAPACITY 101

struct teams{
	int totScore;
	int submitCount;
	int score[CAPACITY];
};

void swap(int *i, int *j) {
	int tmp=*i;
	*i=*j;
	*j=tmp;
	return;
}


int main() {

	int testCases, i;
	int n, k, t, m;//팀수, 문제수, 아이디, 로그 수
	int id, pNum, score;
	struct teams team[CAPACITY];
	int rank[CAPACITY], rnkIdx;

	scanf("%d", &testCases);
	while (testCases-->0) {
		
		for(i = 0; i < CAPACITY; i++) {
			team[i].totScore = 0;
			team[i].submitCount = 0;
			memset(team[i].score, 0, sizeof(int)*CAPACITY);
			rank[i]=i;
		}

		scanf("%d %d %d %d", &n, &k, &t, &m);
		
		while(m-->0) {

			scanf("%d %d %d", &id, &pNum, &score);
			team[id].submitCount++;

			if ( team[id].score[pNum] < score ) {
				
				team[id].totScore -= team[id].score[pNum];
				team[id].score[pNum] = score;
				team[id].totScore += team[id].score[pNum];

				for (i = 1; i < CAPACITY; i++) {
					if (rank[i]==id) {
						rnkIdx = i+1;
						break;
					}
				}
				while (rnkIdx-->2)
				{
					if( team[ rank[rnkIdx] ].totScore > team[ rank[rnkIdx-1] ].totScore )
						swap(&rank[rnkIdx], &rank[rnkIdx-1]);


					else if ( team[ rank[rnkIdx] ].totScore == team[ rank[rnkIdx-1] ].totScore
							&& team[rank[rnkIdx-1]].submitCount > team[rank[rnkIdx]].submitCount)
								swap(&rank[rnkIdx], &rank[rnkIdx-1]);
					
				}
			}
			
		}
		for (i = 1; i < CAPACITY; i++) {
				if (rank[i]==t) {
					printf("sys : %d\n", i);
					break;
				}
			}//prnit
	
	}
	return 0;
}

/*
2
3 4 3 5
1 1 30
2 3 30
1 2 40
1 2 20
3 1 70
4 4 1 10

*/