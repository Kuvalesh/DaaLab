#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Function to perform Depth-First Search
void dfs(int node, int n, bool visited[], int adjacencyMatrix[][MAX_NODES]) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[node][i] && !visited[i]) {
            dfs(i, n, visited, adjacencyMatrix);
        }
    }
}

// Function to find connected components using DFS
void findConnectedComponents(int n, int adjacencyMatrix[][MAX_NODES]) {
    bool visited[MAX_NODES] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Connected Component: ");
            dfs(i, n, visited, adjacencyMatrix);
            printf("\n");
        }
    }
}

int main() {
    int n; // Number of nodes in the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Connected Components:\n");
    findConnectedComponents(n, adjacencyMatrix);

    return 0;
}
