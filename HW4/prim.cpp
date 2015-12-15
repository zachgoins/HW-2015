#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


template <class T>
class Prim
{

private:

public:
  int minKey(int key[], bool mstSet[]);
  Prim(int nodes, int connections);
  int printMST(int parent[], int n, int (**graph));
  void primMST(int (**graph), int des_start);
  int num_nodes;
  int num_connections;
  int des_start;

};

// Constructor
template <class T>
Prim<T>::Prim(int nodes, int connections){
  num_nodes = nodes;
  num_connections = connections;
}

// Finds the key with the min index
template <class T>
int Prim<T>::minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < num_nodes; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
template <class T>
int Prim<T>::printMST(int parent[], int n, int (**graph))
{
   std::cout << "Prim's MST:" << std::endl;
   int weight = 0;
   for (int i = 1; i < num_nodes; i++){
      std::cout << "(" << parent[i] << ", " << i << ")" << std::endl;
      weight += graph[i][parent[i]];
    }

    std::cout << "Total Weight:" << weight << std::endl << std::endl;


}
 

// Solve for Prim's MST
template <class T>
void Prim<T>::primMST(int (**graph), int des_start)
{
     int parent[num_nodes]; // Array to store constructed MST
     int key[num_nodes];   // Key values used to pick minimum weight edge in cut
     bool mstSet[num_nodes];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < num_nodes; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st num_nodes in MST.
     key[0] = des_start;     // Make key 0 so that this num_nodes is picked as first num_nodes
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < num_nodes-1; count++)
     {
        // Pick thd minimum key num_nodes from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked num_nodes to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked nodes. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < num_nodes; v++)
        {
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
          {
            parent[v]  = u, key[v] = graph[u][v];
          }

        }
              
     }
 
     // print the constructed MST
     printMST(parent, num_nodes, graph);
}
 
 