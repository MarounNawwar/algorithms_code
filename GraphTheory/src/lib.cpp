#include <iostream>
using namespace std;


// Function that finds if all pair of vertices are adjacent (connected)
// @param : A 2-dimensional matrix containing all the edges
// @return: Truth/False value 
bool is_complete_graph(int* grap){

    // TODO: Implement Function
    // Constraint: Check if the number of edges is m = n(n-1)/2
    return false;

}


// Function that finds if a given graph can have its vertices partitioned into 2 sets
// such that every vertice in the 1st set is available in the 2nd set
// @param : A 2-dimensional matrix containing all the edges
// @return: Truth/False value 
bool is_bipartite_graph(int* graph){

    // TODO: Implement Function
    // Constraint: Check if the graph is composed of 2 sets with relations from each one to another one of the other set
    return false;

}


// Function that finds if a given graph is complete and also bipartite
// @param : A 2-dimensional matrix containing all the edges
// @return: Truth/False value 
bool is_complete_bipartite(int* graph){

    return is_complete_graph(graph) && is_bipartite_graph(graph);

}


// Function that finds if a given graph is cyclic
// @param : A 2-dimensional matrix containing all the edges
// @return: Truth/False value 
bool is_cyclic_graph(int* graph){

    // TODO: Implement Function
    // Constraint check if a graph makes a cycle
    return false;

}


// Function that finds if a given graph is a tree
// @param : A 2-dimensional matrix containing all the edges
// @return: Truth/False value 
bool is_tree(int* graph){

    // TODO: Implement Function
    // Constraint check if a graph is a tree
    return false;

}

bool is_graphical(){

}


int main(){
                                
    //Here make the logic needed
    return 0;
            
}