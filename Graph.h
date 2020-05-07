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
#include "Graph.cpp"
#endif