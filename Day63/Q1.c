#include <stdio.h>
#include <stdlib.h>

// --- Data Structures ---

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// --- Function Prototypes ---
struct Node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void DFS_recursive(struct Graph* graph, int vertex);
void DFS(struct Graph* graph, int startVertex);

// --- Main Function ---
int main() {
    int n, e, source;
    
    // Example Input
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    struct Graph* graph = createGraph(n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Assuming a directed graph. 
        // For undirected, also call addEdge(graph, v, u);
        addEdge(graph, u, v); 
    }
    
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    
    printf("\nDFS Traversal Order starting from %d: ", source);
    DFS(graph, source);
    printf("\n");

    return 0;
}

// --- DFS Algorithm ---

// The recursive utility function for DFS
void DFS_recursive(struct Graph* graph, int vertex) {
    // Mark the current node as visited and print it
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    
    // Traverse all adjacent vertices of the current vertex
    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        
        // If the adjacent vertex is not visited, recursively call DFS on it
        if (graph->visited[adjVertex] == 0) {
            DFS_recursive(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Wrapper function to initialize DFS
void DFS(struct Graph* graph, int startVertex) {
    // Ensure the visited array is reset before starting
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
    
    // Call the recursive helper function
    DFS_recursive(graph, startVertex);
}

// --- Utility Functions ---

// Create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with 'n' vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add a directed edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    // Add the new node at the beginning of the list for the source vertex
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
