#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
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
    for (int i = 0; i < V; ++i) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}
bool isCyclicUtil(struct Graph* graph, int v, bool visited[], bool recStack[]) {
    // If we haven't visited this node yet
    if (!visited[v]) {
        // Mark the current node as visited and part of the recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Traverse all adjacent vertices
        struct Node* temp = graph->adjList[v];
        while (temp != NULL) {
            int adjNode = temp->dest;

            // If not visited, recursively visit it
            if (!visited[adjNode] && isCyclicUtil(graph, adjNode, visited, recStack)) {
                return true;
            }
            // If it IS visited AND it is in the recursion stack, we found a back edge!
            else if (recStack[adjNode]) {
                return true;
            }
            temp = temp->next;
        }
    }
    
    // Remove the vertex from recursion stack before returning (backtracking)
    recStack[v] = false;
    return false;
}

bool isCyclic(struct Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    bool* recStack = (bool*)calloc(graph->V, sizeof(bool));

    // Check all components of the graph
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, visited, recStack)) {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }

    free(visited);
    free(recStack);
    return false;
}

int main() {
    // Example 1: Directed Graph with a cycle
    // 0 -> 1 -> 2 -> 3 -> 1 (cycle)
    struct Graph* graph1 = createGraph(4);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 2, 3);
    addEdge(graph1, 3, 1);

    printf("Graph 1 Cycle: ");
    if (isCyclic(graph1)) printf("YES\n");
    else printf("NO\n");

    // Example 2: Directed Graph without a cycle (DAG)
    // 0 -> 1 -> 2, 0 -> 2
    struct Graph* graph2 = createGraph(3);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 2);

    printf("Graph 2 Cycle: ");
    if (isCyclic(graph2)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
