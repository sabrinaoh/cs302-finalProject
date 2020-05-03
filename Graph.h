#ifndef GRAPH_H_
#define GRAPH_H_
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
    T getVertices();
    void setVertices(T numVertices);
    void printGraph(T vertices);

    private:
    T vertex;
    vector<T> *adjacency;
};
#endif

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
T Graph<T>::getVertices(){
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
