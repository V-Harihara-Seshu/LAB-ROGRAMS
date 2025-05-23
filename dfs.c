#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100 // Maximum number of nodes in the graph

// Function to perform DFS traversal
void dfs(int graph[MAX_NODES][MAX_NODES], bool visited[], int node, int num_nodes) {
    visited[node] = true; // Mark the current node as visited

    // Traverse all the adjacent nodes (neighbors) of the current node
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, num_nodes); // Recursively visit the neighboring node
        }
    }
}

// Function to check if the graph is connected
bool is_connected(int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    bool visited[MAX_NODES] = {false}; // Initialize all nodes as not visited

    // Start DFS from node 0 (can choose any node)
    dfs(graph, visited, 0, num_nodes);

    // Check if all nodes were visited
    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            return false; // If any node is not visited, the graph is not connected
        }
    }
    return true; // All nodes were visited, so the graph is connected
}

int main() {
    int num_nodes, num_edges;

    // Input the number of nodes and edges
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    // Initialize the adjacency matrix (graph)
    int graph[MAX_NODES][MAX_NODES] = {0};

    // Input the edges (undirected graph)
    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1; // Add an edge from node1 to node2
        graph[node2][node1] = 1; // Add an edge from node2 to node1 (undirected)
    }

    // Check if the graph is connected
    if (is_connected(graph, num_nodes)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
