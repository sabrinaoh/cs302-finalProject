#include "Graph.h"
#include <vector>
// Function to visit (output) a node or vertex
template <typename T>
void visit(T& item){
    cout << item << " ";
}
int main(){
    // Initialize a 2D vector, which is the adjacency matrix
    vector<vector<int> > adjacencyMatrix{  {0, 218, 518, 704, 443}, {218, 0, 0, 808, 564}, {518, 0, 0, 840, 425}, {704, 808, 840, 0, 0}, {443, 564, 425, 0, 0}   };
    // Create an object of type Graph
    Graph<int> travel(5);
    // Adding edges to the vector using the adjacency matrix
    for(int i = 0; i < adjacencyMatrix.size(); i++){
        for(int j = 0; j < adjacencyMatrix[i].size(); j++){
            if (adjacencyMatrix[i][j] != 0){
                travel.addEdge(i, adjacencyMatrix[i][j]);
            }
        }
    }
    cout << "The integers correspond to the following cities" << endl;
    cout << "0: Reno" << endl << "1: San Francisco" << endl << "2: Salt Lake City" << endl << "3: Seattle" << endl << "4: Las Vegas" << endl << endl;
    // Outputs the adjacencies of vertices
    travel.printGraph(5);
    // Code for finding shortest path or BFS or DFS
    // Must initialize shortest path to a local variable
    // Use to calculate cost of trip
    float costOfGas;
    cout << "What is the cost of gas? ";
    cin >> costOfGas;
    // Cost of Trip = costOfGas * shortest Path
    return 0;
}