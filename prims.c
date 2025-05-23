 #include <stdio.h>
#include <stdlib.h>

void prims(int cost[10][10], int n) {
    int visited[10] = {0}, mincost = 0;
    int a, b, u, v, i, j, min, ne = 1;

    visited[1] = 1; // Start from node 1
    printf("\nThe edges of the minimum spanning tree are:\n");

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[v]) {
            printf("%d) Edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // Mark edge as used
    }

    printf("\nMinimum total cost = %d\n", mincost);
}

int main() {
    int n, i, j, cost[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Replace 0 with a high value
            }
        }
    }

    prims(cost, n);
    return 0;
}
