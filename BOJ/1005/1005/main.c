// longest Path...

//bfs로 풀란다



#include <stdio.h>
#include <memory.h>

#define INFINITE -1

int main(int argc, const char * argv[]) {

	int buildTimes[100001];
	int costOfPath[100001];
	int needToBuild[1001][1001];
	int numOfBuildings, path;
	int i, step;
	int src, dst, runTimes;
	int x, y;
	
	scanf("%d", &runTimes);
	
	while ( runTimes --> 0) {
		
		memset(needToBuild, INFINITE, sizeof(int)*1000*1000);
		
		scanf("%d %d", &numOfBuildings, &path );
		
		for (i = 1; i <= path; i++) {scanf("%d", &buildTimes[i]);}
		
		for (i = 1; i <= path; i++) {
			scanf("%d %d", &x, &y);
			needToBuild[x][y] = 1;
		}
		// init end.
		
		// use costOfPath for "DistanceArray[]"
		memset(costOfPath, INFINITE, sizeof(int)*100001);
		costOfPath[1]=buildTimes[1];
	
		for (step = 1; step <= numOfBuildings; step++) {
			
			for (src = 1; src <= numOfBuildings; src++) {
				
				for (dst = 1; dst <= numOfBuildings; dst++) {
					
					// 비교할 것은 '있던 값'과 '이전노드[j] + 현재노드(CostOfPath[][])'
					if (needToBuild[src][dst]==1) {
						costOfPath[dst] =
						costOfPath[dst] > costOfPath[src]+buildTimes[dst] ?
						costOfPath[dst] : costOfPath[src]+buildTimes[dst] ;
					
					}
				}
				
				// 출력확인
				/*
				printf("step. %d : ", src);
				for (i = 1; i <= numOfBuildings; i++)
					printf("[%d] ", costOfPath[i]);
				printf("\n");
				*/
			}
			
			
		}
		
		
		scanf("%d", &i);
		printf("%d\n", costOfPath[i]);
		
	}
	
    return 0;
}
