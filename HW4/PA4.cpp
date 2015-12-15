// Maybe not the best practices when it comes to including, but works for now
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

int main()
{
    int num_nodes;
    int num_connections;
    int start_node;
    string raw_input;
    vector<int> connection_input;

    // Edge Entry 


    cout << "Enter number of Node and Edges(s): " << endl;
    cin >> raw_input;


    // Split input based on token
    istringstream iss(raw_input);
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

    // Large Data Entry

    cout << "Enter Node A and Node B and Undirected Edge Weight(s): " << endl;

    for (int i = 0; i < num_connections; i++)
    {
        cin >> raw_input;
        rows[i] = raw_input;
        temp_array.clear();
    }

    cout << "Enter the start node:" << endl;
    cin >> start_node;



    Kruskal <int>kruskal;
    Prim <int>prim(num_nodes, num_connections);
    Sollin <int>sollin(num_nodes, num_connections);


    // Prepare all datatypes as a function of entry above
    // Prim and Sollin are by a graph, kruskal by a list
    
    struct Graph* kruskal_graph = kruskal.createGraph(num_nodes, num_connections);

    int **prim_graph;
    prim_graph = new int*[num_nodes]; // dynamic `array (size 4) of pointers to int`

    int **sollin_graph;
    sollin_graph = new int*[num_nodes]; // dynamic `array (size 4) of pointers to int`


    for (int i = 0; i < num_nodes; i++) {
        prim_graph[i] = new int[num_nodes];
    // each i-th pointer is now pointing to dynamic array (size 10) of actual int values
    }
    for (int i = 0; i < num_nodes; i++) {
        sollin_graph[i] = new int[num_nodes];
    // each i-th pointer is now pointing to dynamic array (size 10) of actual int values
    }

 
    // WHERE THE MAGIC HAPPENS
    // From each link in the connection separate, put into proper datatype
    for (int i = 0; i < num_connections; i++)
    {
        // Separate text input
        istringstream iss(rows[i]);
        string s;
        vector<string> temp_array;
        while ( getline( iss, s, '-') ) {
        // Append each number to a vector array
        temp_array.push_back(s.c_str());
        }

        // Asset all the neccesary input was entered
        assert(temp_array.size() == 3);

        // Convert vector array to ss to then convery to int
        // Have to do both separately for some reason
        stringstream k_src(temp_array.at(0)); 
        stringstream p_src(temp_array.at(0));
        stringstream s_src(temp_array.at(0));
        
        stringstream k_dest(temp_array.at(1)); 
        stringstream p_dest(temp_array.at(1)); 
        stringstream s_dest(temp_array.at(1)); 
    
        stringstream k_weight(temp_array.at(2)); 
        stringstream p_weight(temp_array.at(2)); 
        stringstream s_weight(temp_array.at(2)); 

        // Will hold data to put into graph
        int src_p, dest_p, weight_p, src_k, dest_k, weight_k, src_s, dest_s, weight_s;

        // Prepare to add to graph
        p_src >> src_p;
        p_dest >> dest_p;
        p_weight >> weight_p;
        s_src >> src_s;
        s_dest >> dest_s;
        s_weight >> weight_s;
        k_src >> src_k;
        k_dest >> dest_k;
        k_weight >> weight_k;

        // Add to kruskal list
        kruskal_graph->edge[i].src = src_k;
        kruskal_graph->edge[i].dest = dest_k;
        kruskal_graph->edge[i].weight = weight_k;

        // Add data to graph - Since graph is symetrical you can assign both sides at a time
        prim_graph[src_p][dest_p] = weight_p;
        prim_graph[dest_p][src_p] = weight_p;

        sollin_graph[src_s][dest_s] = weight_s;
        sollin_graph[dest_s][src_s] = weight_s;

        // Clear array for next iteration
        temp_array.clear();
    }
 
    // SOLVE FOR ALL GRAPHS
    kruskal.KruskalMST(kruskal_graph);
    prim.primMST(prim_graph, start_node);
    sollin.sollinMST(sollin_graph, start_node);
    

    return 0;
}
