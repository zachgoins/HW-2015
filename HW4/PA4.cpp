#include "kruskal.cpp"
#include "prim.cpp" 
#include "sollin.cpp"
#include <string>
#include <iostream>
#include <sstream>      // std::istringstream
#include <vector>
#include <stdlib.h>     /* atoi */
#include <assert.h>     /* assert */

#ifndef DATA_HELPERS_H_
#define DATA_HELPERS_H_

#include "data_helpers.h"

#endif

using namespace std;

// driver program to test above function
int main()
{
    int num_nodes;
    int num_connections;
    int start_node;
    string temp_input;
    vector<int> connection_input;

    /*

    // Edge Entry 

    cout << "Enter number of Node and Edges(s): " << endl;
    cin >> temp_input;

    // Split input based on token
    istringstream iss(temp_input);
    string s;
    vector<string> temp_array;
    while ( getline( iss, s, '-') ) {
    temp_array.push_back(s.c_str());
    }

    assert(temp_array.size() == 2);
    
    // Assign separated values to individual variables
    stringstream str(temp_array.at(0)); 
    str >> num_nodes;
    stringstream str2(temp_array.at(1)); 
    str2 >> num_connections;
    temp_array.clear();

    // Create variable to hold large data based on the last input
    string* rows = new string[num_connections];
    int graph[num_connections][num_connections];

    // Large Data Entry

    cout << "Enter Node A and Node B and Undirected Edge Weight(s): " << endl;

    for (int i = 0; i < num_connections; i++)
    {
        cin >> temp_input;
        rows[i] = temp_input;
        temp_array.clear();
    }

    cout << "Enter the start node:" << endl;
    cin >> start_node;

    */

    num_nodes = 4;
    num_connections = 5;
    string* rows = new string[num_connections];
    rows[0] = "0-1-5";
    rows[1] = "1-3-4";
    rows[2] = "3-2-2";
    rows[3] = "2-0-7";
    rows[4] = "1-2-10";
    start_node = 0;

    Kruskal <int>kruskal;
    Prim <int>prim(num_nodes, num_connections);
    Sollin <int>sollin;

    // Kruskal Area

    

    struct Graph* kruskal_graph = kruskal.createGraph(num_nodes, num_connections);
    struct Graph* sollin_graph = sollin.createGraph(num_nodes, num_connections);
    int graph[Vertex][Vertex];
 
    for (int i = 0; i < num_connections; i++)
    {
        istringstream iss(rows[i]);
        string s;
        vector<string> temp_array;
        while ( getline( iss, s, '-') ) {
        temp_array.push_back(s.c_str());
        }

        stringstream k_src(temp_array.at(0)); 
        stringstream s_src(temp_array.at(0)); 
        stringstream src(temp_array.at(0));
        
        stringstream k_dest(temp_array.at(1)); 
        stringstream s_dest(temp_array.at(1)); 
        stringstream dest(temp_array.at(1)); 
    
        stringstream k_weight(temp_array.at(2)); 
        stringstream s_weight(temp_array.at(2)); 
        stringstream weight(temp_array.at(2)); 

        int src_i, dest_i, weight_i;

        src >> src_i;
        dest >> dest_i;
        weight >> weight_i;

        k_src >> kruskal_graph->edge[i].src;
        s_src >> sollin_graph->edge[i].src;
        k_dest >> kruskal_graph->edge[i].dest;
        s_dest >> sollin_graph->edge[i].dest;
        k_weight >> kruskal_graph->edge[i].weight;
        s_weight >> sollin_graph->edge[i].weight;

        graph[src_i][dest_i] = weight_i;
        graph[dest_i][src_i] = weight_i;

        temp_array.clear();
    }
 
    kruskal.KruskalMST(kruskal_graph);
    sollin.sollinMST(sollin_graph);
    prim.primMST(graph);

    return 0;
}
