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
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (since it's undirected)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

bool isCyclicUtil(struct Graph* graph, int v, bool visited[], int parent) {

    visited[v] = true;

    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adjNode = temp->dest;

        if (!visited[adjNode]) {
            if (isCyclicUtil(graph, adjNode, visited, v)) {
                return true;
            }
        }
        
        else if (adjNode != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool isCyclic(struct Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            // Start DFS with -1 as the parent for the root node
            if (isCyclicUtil(graph, i, visited, -1)) {
                free(visited);
                return true;
            }
        }
    }

    free(visited);
    return false;
}

int main() {
  
    struct Graph* graph1 = createGraph(3);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 2, 0);

    if (isCyclic(graph1)) printf("YES\n");
    else printf("NO\n");

   
    struct Graph* graph2 = createGraph(3);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);

    if (isCyclic(graph2
