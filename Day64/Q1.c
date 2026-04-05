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

// Structure for the Queue
struct Queue {
    int* items;
    int front;
    int rear;
};

// --- Function Prototypes ---
struct Node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
struct Queue* createQueue(int size);
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
int isEmpty(struct Queue* q);
void BFS(struct Graph* graph, int source);

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
    
    printf("\nBFS Traversal Order starting from %d: ", source);
    BFS(graph, source);
    printf("\n");

    return 0;
}

// --- BFS Algorithm ---
void BFS(struct Graph* graph, int source) {
    struct Queue* q = createQueue(graph->numVertices);
    
    // Mark the source node as visited and enqueue it
    graph->visited[source] = 1;
    enqueue(q, source);
    
    while (!isEmpty(q)) {
        // Dequeue a vertex and print it
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        
        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjLists[currentVertex];
        
        while (temp) {
            int adjVertex = temp->vertex;
            
            // If adjacent vertex is not visited, mark it and enqueue it
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    
    // Free the queue memory
    free(q->items);
    free(q);
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
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Create a queue
struct Queue* createQueue(int size) {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->items = malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->rear == -1) 
        return 1;
    else 
        return 0;
}

// Add an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Remove an element from the queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        // Reset the queue if it becomes empty
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}
