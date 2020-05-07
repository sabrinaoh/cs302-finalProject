#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
class Graph{
    public:
    Graph();
    Graph(T newVertex);
    Graph(Graph & newGraph);
    void addEdge(T vertex, T length);
    const T getVertices();
    void setVertices(T numVertices);
    void printGraph(T vertices);
    int getEdgeWeight(T vertex, T position);
    //int mindistance(int test,int matrix[][test], int rootVertex);
    private:
    T vertex;
    vector<T> *adjacency;
};

template <typename T>
Graph<T>::Graph(){
    vertex = 0;
}
template <typename T>
Graph<T>::Graph(T newVertex){
    this -> vertex = newVertex;
    adjacency = new vector<T>[vertex];
}
template <typename T>
Graph<T>::Graph(Graph & newGraph){
    vertex = newGraph.vertex;
}
template <typename T>
void Graph<T>::addEdge(T vertex, T length){
    adjacency[vertex].push_back(length);
}
template <typename T>
const T Graph<T>::getVertices(){
    return vertex;
}
template <typename T>
void Graph<T>::setVertices(T numVertices){
    vertex = numVertices;
}
template <typename T>
void Graph<T>::printGraph(T vertices){
    for (int v = 0; v < vertices; v++){
        cout << "Adjacency list of vertex " << v << endl;
        cout << "head";
        for (auto x : adjacency[v]){
            cout << " -> " << x;
        }
        cout << endl << endl;
    }
}
template <class T>
int Graph<T>::getEdgeWeight(T vertex, T position){
return adjacency[vertex].at(position);
}

//template <typename T>
//Ignore this it doesn't work
/*int Graph<T>::mindistance(int numVertex,int matrix[][getVertices()], int rootVertex){
vector<int> queue;
for(int i = 0;i < numVertex;i++)
if(i != rootVertex)
    queue.push_back(i);
int mini;
do{
    int current = 0;
           int k = rootVertex;
        for (int i = 0; i < queue.size(); i++) {
            current += matrix[k][queue[i]];
            k = queue[i];
        }
    current += matrix[k][numVertex];
    mini = min(current,mini);
}while(std::next_permutation(queue.begin(),queue.end()));//brute force check through method
return mini;
};*/

#endif // GRAPH_H
