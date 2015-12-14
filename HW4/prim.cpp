#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
// Number of vertices in the graph
#define Vertex 4

template <class T>
class Prim
{

private:

public:
  int minKey(int key[], bool mstSet[]);
  Prim(int nodes, int connections);
  int printMST(int parent[], int n, int graph[Vertex][Vertex]);
  void primMST(int graph[Vertex][Vertex]);
  int num_nodes;
  int num_connections;
};

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST


template <class T>
Prim<T>::Prim(int nodes, int connections){
  num_nodes = nodes;
  num_connections = connections;
}

template <class T>
int Prim<T>::minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < Vertex; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
template <class T>
int Prim<T>::printMST(int parent[], int n, int graph[Vertex][Vertex])
{
   std::cout << "Prim's MST:" << std::endl;
   int weight = 0;
   for (int i = 1; i < Vertex; i++){
      std::cout << "(" << parent[i] << ", " << i << ")" << std::endl;
      weight += graph[i][parent[i]];
    }

    std::cout << "Total Weight:" << weight << std::endl << std::endl;


}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
template <class T>
void Prim<T>::primMST(int graph[Vertex][Vertex])
{
     int parent[Vertex]; // Array to store constructed MST
     int key[Vertex];   // Key values used to pick minimum weight edge in cut
     bool mstSet[Vertex];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < Vertex; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < Vertex-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < Vertex; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // print the constructed MST
     printMST(parent, Vertex, graph);
}
 
 