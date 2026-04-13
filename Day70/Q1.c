#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a directed edge
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    struct Edge* edge; // Array of edges
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}
void bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int* dist = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            free(dist);
            return;
        }
    }

    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            printf("%d \t Infinity\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }

    free(dist);
}

int main() {
    int V = 4; // Number of vertices
    int E = 4; // Number of edges

    struct Graph* graph = createGraph(V, E);

    // Graph with a negative cycle: 1 -> 2 -> 3 -> 1 (Weight: 3 - 6 + 2 = -1)
    // Edge 0
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 2;

    // Edge 1
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 3;

    // Edge 2
    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = -6;

    // Edge 3
    graph->edge[3].src = 3;
    graph->edge[3].dest = 1;
    graph->edge[3].weight = 2;

    bellmanFord(graph, 0);

    // Free the graph memory
    free(graph->edge);
    free(graph);

    return 0;
}
