#include <stdio.h>
#include <stdlib.h>

// --- Function Prototypes ---
int** createMatrix(int n);
void addEdge(int** matrix, int u, int v, int isDirected);
void printMatrix(int** matrix, int n);
void freeMatrix(int** matrix, int n);

// --- Main Function ---
int main() {
    int n, m, isDirected;
    
    // Input: number of vertices (n)
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    
    // Create the n x n adjacency matrix initialized to 0
    int** matrix = createMatrix(n);
    
    // Check if the graph is directed or undirected
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);
    
    // Input: number of edges (m)
    printf("Enter the number of edges (m): ");
    scanf("%d", &m);
    
    // Input: the edges
    // Note: Assuming 0-based indexing for vertices (0 to n-1)
    printf("Enter the %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Ensure inputs are within bounds
        if (u >= 0 && u < n && v >= 0 && v < n) {
            addEdge(matrix, u, v, isDirected);
        } else {
            printf("Invalid edge: %d %d. Vertices must be between 0 and %d.\n", u, v, n - 1);
            i--; // Decrement i to retry this edge
        }
    }
    
    // Output: Adjacency matrix representation
    printf("\nAdjacency Matrix:\n");
    printMatrix(matrix, n);
    
    // Clean up memory
    freeMatrix(matrix, n);

    return 0;
}

// --- Graph Operations ---

// Dynamically allocate an n x n matrix and initialize it to 0
int** createMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int)); // calloc initializes elements to 0
    }
    return matrix;
}

// Add an edge to the adjacency matrix
void addEdge(int** matrix, int u, int v, int isDirected) {
    matrix[u][v] = 1; // Add edge from u to v
    
    if (!isDirected) {
        matrix[v][u] = 1; // If undirected, also add edge from v to u
    }
}

// Print the adjacency matrix
void printMatrix(int** matrix, int n) {
    // Print column headers
    printf("   ");
    for (int i = 0; i < n; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    // Print rows
    for (int i = 0; i < n; i++) {
        printf("%2d ", i); // Row header
        for (int j = 0; j < n; j++) {
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
}

// Free the allocated memory for the matrix
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
