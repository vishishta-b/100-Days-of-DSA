#include <stdio.h>
#include <stdlib.h>

// --- Data Structures ---

// Structure for a node in the linked list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the Graph
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of pointers to nodes
};

// --- Function Prototypes ---
struct Node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);

// --- Main Function ---
int main() {
    int n, m;
    
    // Input: number of vertices (n)
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    
    struct Graph* graph = createGraph(n);
    
    // Input: number of edges (m)
    printf("Enter the number of edges (m): ");
    scanf("%d", &m);
    
    // Input: the edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Assuming a directed graph. 
        // For an undirected graph, also call: addEdge(graph, v, u);
        addEdge(graph, u, v);
    }
    
    // Output: Adjacency list representation
    printf("\nGraph Adjacency List:\n");
    printGraph(graph);
    
    // Clean up memory
    freeGraph(graph);

    return 0;
}

// --- Graph Operations ---

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
    
    // Allocate an array of pointers to Node structures
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    
    // Initialize each adjacency list to NULL (empty)
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Add an edge from 'src' to 'dest'
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination
    struct Node* newNode = createNode(dest);
    
    // Add the new node at the beginning of the list for 'src'
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d:", i);
        while (temp != NULL) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the allocated memory for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}
