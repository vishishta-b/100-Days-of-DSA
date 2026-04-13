#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
    int* inDegree; // Array to store in-degrees of vertices
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    graph->inDegree = (int*)calloc(V, sizeof(int)); // Initialize all in-degrees to 0
    
    for (int i = 0; i < V; ++i) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add a DIRECTED edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // Increment the in-degree of the destination vertex
    graph->inDegree[dest]++;
}

// Function to perform Topological Sort using Kahn's Algorithm
void topologicalSortKahn(struct Graph* graph) {
    int V = graph->V;
    
    // Array-based Queue
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;
    
    // Array to store the final topological order
    int* topOrder = (int*)malloc(V * sizeof(int));
    int topIndex = 0;
    
    // Step 1 & 2: Enqueue all vertices with an in-degree of 0
    for (int i = 0; i < V; i++) {
        if (graph->inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    // Step 3: Process the Queue
    while (front < rear) {
        // Dequeue the front vertex
        int u = queue[front++];
        topOrder[topIndex++] = u; // Add to topological order
        
        // Iterate through all adjacent vertices of the dequeued vertex u
        struct Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->dest;
            
            // Decrement the in-degree of the adjacent node
            graph->inDegree[v]--;
            
            // If in-degree becomes 0, enqueue it
            if (graph->inDegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
    
    // Step 4: Check for cycles
    if (topIndex != V) {
        printf("Error: Graph contains a cycle. Topological sort is not possible.\n");
    } else {
        printf("Topological Sorting Order (Kahn's Algorithm):\n");
        for (int i = 0; i < topIndex; i++) {
            printf("%d ", topOrder[i]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    free(queue);
    free(topOrder);
}

int main() {
    // Create a DAG with 6 vertices (0 to 5)
    struct Graph* graph = createGraph(6);
    
    // Edges: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSortKahn(graph);

    return 0;
}
