AIM:To implement an approximation algorithm for Vertex Cover in C, which selects vertices such that every edge in the graph is covered.
PROGRAM:
#include <stdio.h>

#define V 5   // Number of vertices

// Function to find approximate vertex cover
void findVertexCover(int graph[V][V]) 
{ 
    int visited[V];  // Array to mark selected vertices

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++) 
    { 
        visited[i] = 0; 
    } 

    // Traverse all edges
    for (int u = 0; u < V; u++) 
    { 
        for (int v = u + 1; v < V; v++)   
        { 
            // If there is an edge between u and v
            if (graph[u][v] == 1) 
            { 
                // Include both vertices in the vertex cover
                visited[u] = 1; 
                visited[v] = 1; 
            } 
        } 
    } 

    printf("Approximate Vertex Cover: "); 

    int count = 0; 

    // Print selected vertices
    for (int i = 0; i < V; i++) 
    { 
        if (visited[i]) 
        { 
            printf("%d ", i); 
            count++; 
        } 
    } 

    // Print total vertices in cover
    printf("\nTotal vertices in the cover: %d\n", count);
} 

int main() 
{ 
    // Adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 1, 0, 0, 0}, 
        {1, 0, 1, 1, 0}, 
        {0, 1, 0, 1, 1}, 
        {0, 1, 1, 0, 1}, 
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n"); 

    // Call function
    findVertexCover(graph); 

    return 0; 
}
OUTPUT:
Executing Vertex Cover Approximation...
Approximate Vertex Cover: 0 1 2 3 4 
Total vertices in the cover: 5
