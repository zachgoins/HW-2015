#include "kruskal.cpp"
#include "prim.cpp" 
#include "sollin.cpp"

#ifndef DATA_HELPERS_H_
#define DATA_HELPERS_H_

#include "data_helpers.h"

#endif

// driver program to test above function
int main()
{

    Kruskal <int>kruskal;
    Prim <int>prim;
    Sollin <int>sollin;
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[Vertex][Vertex] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    prim.primMST(graph);

    int Vert = 4;  // Number of vertices in kruskal_graph
    int E = 5;  // Number of edges in kruskal_graph
    struct Graph* kruskal_graph = kruskal.createGraph(Vert, E);
 
    // add edge 0-1
    kruskal_graph->edge[0].src = 0;
    kruskal_graph->edge[0].dest = 1;
    kruskal_graph->edge[0].weight = 10;
 
    // add edge 0-2
    kruskal_graph->edge[1].src = 0;
    kruskal_graph->edge[1].dest = 2;
    kruskal_graph->edge[1].weight = 6;
 
    // add edge 0-3
    kruskal_graph->edge[2].src = 0;
    kruskal_graph->edge[2].dest = 3;
    kruskal_graph->edge[2].weight = 5;
 
    // add edge 1-3
    kruskal_graph->edge[3].src = 1;
    kruskal_graph->edge[3].dest = 3;
    kruskal_graph->edge[3].weight = 15;
 
    // add edge 2-3
    kruskal_graph->edge[4].src = 2;
    kruskal_graph->edge[4].dest = 3;
    kruskal_graph->edge[4].weight = 4;
 
    kruskal.KruskalMST(kruskal_graph);


    Vert = 4;  // Number of vertices in graph
    E = 5;  // Number of edges in graph
    struct Graph* sollin_graph = sollin.createGraph(Vert, E);
 
 
    // add edge 0-1
    sollin_graph->edge[0].src = 0;
    sollin_graph->edge[0].dest = 1;
    sollin_graph->edge[0].weight = 10;
 
    // add edge 0-2
    sollin_graph->edge[1].src = 0;
    sollin_graph->edge[1].dest = 2;
    sollin_graph->edge[1].weight = 6;
 
    // add edge 0-3
    sollin_graph->edge[2].src = 0;
    sollin_graph->edge[2].dest = 3;
    sollin_graph->edge[2].weight = 5;
 
    // add edge 1-3
    sollin_graph->edge[3].src = 1;
    sollin_graph->edge[3].dest = 3;
    sollin_graph->edge[3].weight = 15;
 
    // add edge 2-3
    sollin_graph->edge[4].src = 2;
    sollin_graph->edge[4].dest = 3;
    sollin_graph->edge[4].weight = 4;
 
    sollin.sollinMST(sollin_graph);
 
    return 0;
}
