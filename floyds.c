#include <stdio.h>

#define INF 999
#define MAX 10

// Function to return the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Floyd's algorithm to find all-pairs shortest paths
void floyd(int n, int d[MAX][MAX]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int n;
    int a[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (use 999 for INF):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    floyd(n, a);

    printf("\nAll-Pairs Shortest Distance Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == INF)
                printf("  INF");
            else
                printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
