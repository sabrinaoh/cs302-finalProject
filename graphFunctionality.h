#ifndef GRAPHFUNCTIONALITY_H
#define GRAPHFUNCTIONALITY_H
#include "graph.h"
template<class T>
class Graph;
template <typename T>
class GraphInterface:public Graph<T>{
    public:
    vector<T> *cityList;
GraphInterface();
GraphInterface(T newVertex);
    int getNumVertices();
    int getNumEdges();
    bool add (T vertex, int city, int distance);
    bool remove (T start, T end);
    int getEdgeWeight(T start, T end);
    void depthFirstTraversal (T start, void visit(T&));
    void breadthFirstTraversal (T start, void visit(T&));
    ~GraphInterface() {}
    friend class Graph<T>;
};



template<class T>
GraphInterface<T>::GraphInterface(){

}
template<class T>
GraphInterface<T>::GraphInterface(T newVertex):Graph<T>(newVertex){
    cityList = new vector<T>[Graph<T>::getVertices()];
}

template<class T>
bool GraphInterface<T>::add (T vertex, int city, int distance){
Graph<T>::addEdge(vertex,distance);
cityList[vertex].push_back(city);
}
template<class T>
void GraphInterface<T>::depthFirstTraversal(T start, void visit(T&)){
    //This is just to test Inheritance
std::cout << Graph<T>::getVertices();
}

#endif // GRAPHFUNCTIONALITY_H
