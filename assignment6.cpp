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
    float costOfGas;
    cout << "What is the cost of gas? ";
    cin >> costOfGas;
    int otherCities[] = {1, 2, 3, 4};
    int shortestLength = 5000;
    int testLength;
    int shortestList[6];
    int testList[6];
    testList[0] = 0;
    testList[5] = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (adjacencyMatrix[i][j] == 0 && i != j){
                adjacencyMatrix[i][j] = adjacencyMatrix[0][i] + adjacencyMatrix[0][j];
            }
        }
    }
    sort(otherCities, otherCities + 4);
    do{
        testLength = 0;
        for (int i = 0; i < 4; i++){
            testList[i + 1] = otherCities[i];
        }
        for (int j = 0; j < 5; j++){
            testLength = testLength + adjacencyMatrix[testList[j]][testList[j+1]];
        }
        if (testLength < shortestLength){
            shortestLength = testLength;
            for (int i = 0; i < 6; i++){
                shortestList[i] = testList[i];
            }
        }
    }while (next_permutation(otherCities, otherCities + 4));
    cout << "The shortest path is: " << endl;
    for (int i = 0; i < 6; i++){
        cout << shortestList[i] << " " ;
    }
    cout << endl;
    cout << "It covers " << shortestLength << " miles" << endl;
    cout << "It will cost $" << (shortestLength/40)*costOfGas << endl;
    return 0;
}