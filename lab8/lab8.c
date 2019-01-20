#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define INF 10000
#define MAX_VERT 6
#define MAX_EDGE 10

struct Node {
	int source[MAX_VERT];
	int weight[MAX_VERT];
} route[MAX_VERT];

void shortestDistance(struct Node *edge) {
	int flag;
	int i;
	int j;
	int k;
	do {
		flag = 0;
		for (i = 0; i < MAX_VERT; i++) {
			for (j = 0; j < MAX_VERT; j++) {
				for (k = 0; k < MAX_VERT; k++) {
					if (edge[i].weight[j] > (edge[i].weight[k] + edge[k].weight[j])) {
						edge[i].weight[j] = edge[i].weight[k] + edge[k].weight[j];
						edge[i].source[j] = k;
						flag = 1;
					}
				}
			}
		}
	} while(flag);
		
	for (i = 0; i < MAX_VERT; i++) {
		for (j = 0; j < MAX_VERT; j++) {
			printf("%d\t", edge[i].weight[j]);
		}
		printf("\n");
	}

	return;
}
	
int main(int argc, char *argv[]) {
	int distance[MAX_VERT][MAX_VERT] = {{0,7,3,5,INF,INF},	
					    {7,0,3,INF,4,INF},	
					    {3,3,0,4,8,INF},	
					    {5,INF,4,0,7,9},	
					    {INF,4,8,7,0,2},
				 	    {INF,INF,INF,9,2,0}};
	int i;
	int j;

	for (i = 0; i < MAX_VERT; i++) {
		for (j = 0; j < MAX_VERT; j++) {
			distance[i][i] = 0;
			route[i].weight[j] = distance[i][j];
			route[i].source[j] = j;
		}
	}
	shortestDistance(route);
	return 0;
}
