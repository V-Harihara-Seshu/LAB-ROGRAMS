#include <stdio.h>

#define MAX 10 // Maximum number of vertices

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int stack[MAX];      // Stack to store topological order
int top = -1;        // Stack top index

// Function to push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function to visit nodes
void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }

    push(v); // Push after visiting all adjacent nodes
}

// Topological sort function
void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0; // Mark all as unvisited
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, n);
        }
    }

    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// Driver code
int main() {
    int n, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (format: src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed edge from u to v
    }

    topologicalSort(n);

    return 0;
}
