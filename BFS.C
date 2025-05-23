#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10 // maximum number of nodes in the graph

void bfs(int a[MAX_NODES][MAX_NODES], int n, int source) {
    int q[MAX_NODES];
    int front = 0;
    int rear = -1;
    int v[MAX_NODES] = {0}; // Array to track visited nodes
    int node, i;
    
    // Mark the source node as visited and add it to the queue
    v[source] = 1;
    q[++rear] = source;

    printf("Nodes reachable from node %d: ", source);

    // Start BFS traversal
    while (front <= rear) {
        node = q[front++]; // Dequeue a node from the front of the queue

        printf("%d ", node); // Print the current node

        // Explore all adjacent nodes of the current node
        for (i = 0; i < n; i++) {
            // If there's an edge and the node has not been visited
            if (a[node][i] == 1 && v[i] == 0) {
                v[i] = 1; // Mark the node as visited
                q[++rear] = i; // Enqueue the node to explore later
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 4;  // Number of nodes
    int source = 0; // Starting node

    // Example adjacency matrix for a simple undirected graph
    int a[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    bfs(a, n, source);

    return 0;
}
