#include <stdio.h>
#include <stdlib.h>

/**
 * Helper function to perform DFS and mark all cities in the same province as visited.
 */
void dfs(int** isConnected, int* visited, int n, int currentCity) {
    for (int neighbor = 0; neighbor < n; neighbor++) {
        // If there is a connection and the neighbor hasn't been visited yet
        if (isConnected[currentCity][neighbor] == 1 && !visited[neighbor]) {
            visited[neighbor] = 1; // Mark as visited
            dfs(isConnected, visited, n, neighbor);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int provinceCount = 0;
    
    // Allocate a visited array and initialize to 0 (false)
    int* visited = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        // If the city has not been visited, it belongs to a new province
        if (!visited[i]) {
            provinceCount++;
            visited[i] = 1; // Mark the starting city of the province
            dfs(isConnected, visited, n, i);
        }
    }
    
    free(visited);
    return provinceCount;
}
