#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// --- Graph Structures ---
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct Graph {
    int V;
    struct AdjListNode** adjList;
};

struct AdjListNode* createNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct AdjListNode**)malloc(V * sizeof(struct AdjListNode*));
    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;
    return graph;
}

// Add a DIRECTED edge
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// --- Priority Queue (Min-Heap) Structures ---
struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode* array;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (struct MinHeapNode*)malloc(capacity * sizeof(struct MinHeapNode));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].dist < minHeap->array[smallest].dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right].dist < minHeap->array[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Extract the minimum node from heap
struct MinHeapNode extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return (struct MinHeapNode){-1, -1};
    
    struct MinHeapNode root = minHeap->array[0];
    struct MinHeapNode lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->size--;
    minHeapify(minHeap, 0);
    
    return root;
}

// Insert a new node into the heap (Lazy approach to avoid complex decreaseKey)
void pushMinHeap(struct MinHeap* minHeap, int v, int dist) {
    // If heap is full, resize (simplified here, assuming E < capacity)
    if(minHeap->size == minHeap->capacity) return; 

    int i = minHeap->size;
    minHeap->size++;
    minHeap->array[i].v = v;
    minHeap->array[i].dist = dist;

    // Bubble up
    while (i && minHeap->array[i].dist < minHeap->array[(i - 1) / 2].dist) {
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// --- Dijkstra's Algorithm ---
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int));
    
    // Max size of heap is E (number of edges) because of lazy deletion
    // In a dense graph, E can be V*V. We'll use a safe capacity.
    struct MinHeap* minHeap = createMinHeap(V * V); 

    // Initialize distances to infinity
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
    }
    
    // Source distance is 0
    dist[src] = 0;
    pushMinHeap(minHeap, src, 0);

    while (minHeap->size > 0) {
        // Extract the vertex with minimum distance
        struct MinHeapNode minNode = extractMin(minHeap);
        int u = minNode.v;
        int d = minNode.dist;

        // Lazy deletion: If we find a stale/outdated distance in the PQ, ignore it
        if (d > dist[u]) continue;

        // Traverse through all adjacent vertices of u
        struct AdjListNode* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->dest;
            int weight = temp->weight;

            // Relaxation step
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pushMinHeap(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print the calculated shortest distances
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            printf("%d \t Infinity\n", i);
        else
            printf("%d \t %d\n", i, dist[i]);
    }

    free(dist);
    free(minHeap->array);
    free(minHeap);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    // Creating a sample graph
    // 0 -> 1 (w:4), 0 -> 2 (w:1)
    // 2 -> 1 (w:2), 1 -> 3 (w:1)
    // 2 -> 3 (w:5), 3 -> 4 (w:3)
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 3);

    dijkstra(graph, 0);

    return 0;
}
