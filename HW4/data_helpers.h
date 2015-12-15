
// weighted edge
struct Edge
{
    int src, dest, weight;
};
 
// conected graph.
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges.
    Edge* edge;
};
 
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 