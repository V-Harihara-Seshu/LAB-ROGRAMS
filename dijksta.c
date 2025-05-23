#include <stdio.h>
#include <stdlib.h>

#define INF 999

void dijkstra(int cost[10][10], int n, int source, int v[10], int d[10]) {
    int i, j, u, min;

    for (i = 1; i <= n; i++) {
        v[i] = 0;
        d[i] = cost[source][i];
    }

    v[source] = 1;
    d[source] = 0;

    for (i = 2; i <= n; i++) {
        min = INF;
        u = -1;

        for (j = 1; j <= n; j++) {
            if (!v[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break; // No reachable unvisited node

        v[u] = 1;

        for (j = 1; j <= n; j++) {
            if (!v[j] && (d[u] + cost[u][j] < d[j])) {
                d[j] = d[u] + cost[u][j];
            }
        }
    }
}

int main() {
    int n, cost[10][10], v[10], d[10];
    int i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Adjacency Matrix (999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j)
                cost[i][j] = 0;
            else if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter the source node (1 to %d): ", n);
    scanf("%d", &source);

    dijkstra(cost, n, source, v, d);

    printf("Shortest distances from source node %d:\n", source);
    for (i = 1; i <= n; i++) {
        if (d[i] == INF)
            printf("To %d = INF (unreachable)\n", i);
        else
            printf("To %d = %d\n", i, d[i]);
    }

    return 0;
}
