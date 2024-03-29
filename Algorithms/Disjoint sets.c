#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

// Structure to represent a subset for union-find
typedef struct subset {
    int parent;
    int rank;
} subset;

// A structure to represent an undirected graph
typedef struct Graph {
    int V, E;
    int* parent;
    int* rank;
} Graph;

// Create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->parent = (int*)malloc(V * sizeof(int));
    graph->rank = (int*)malloc(V * sizeof(int));
    for (int v = 0; v < V; v++) {
        graph->parent[v] = v;
        graph->rank[v] = 0;
    }
    return graph;
}

// Find set of an element i (uses path compression technique)
int find(Graph* graph, int i) {
    if (graph->parent[i] != i)
        graph->parent[i] = find(graph, graph->parent[i]);
    return graph->parent[i];
}

// Perform union of two sets of x and y (uses union by rank)
void Union(Graph* graph, int x, int y) {
    int xroot = find(graph, x);
    int yroot = find(graph, y);

    if (graph->rank[xroot] < graph->rank[yroot])
        graph->parent[xroot] = yroot;
    else if (graph->rank[xroot] > graph->rank[yroot])
        graph->parent[yroot] = xroot;
    else {
        graph->parent[yroot] = xroot;
        graph->rank[xroot]++;
    }
}

// Function to determine the connected components of a graph
void connectedComponents(Graph* graph) {
    printf("Connected components:\n");
    for (int v = 0; v < graph->V; v++)
        printf("Vertex %d belongs to connected component %d\n", v, find(graph, v));
}

int main() {
    int V = 6, E = 5;
    Graph* graph = createGraph(V, E);

    // Add edges
    Union(graph, 0, 1);
    Union(graph, 1, 2);
    Union(graph, 3, 4);

    connectedComponents(graph);

    free(graph->parent);
    free(graph->rank);
    free(graph);
    
    return 0;
}
