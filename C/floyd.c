#include <stdio.h>

#define INF 99999
#define V 4

void floydWarshall(int graph[V][V]) {
    int i, j, k;

    // 플로이드-와샬 알고리즘 수행
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // 결과 출력
    printf("플로이드 최단 경로 행렬:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%3d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, INF, 6},
        {3, 0, 7, INF},
        {5, INF, 0, 4},
        {INF, INF, 2, 0}
    };

    floydWarshall(graph);
    return 0;
}
