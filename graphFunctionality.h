#ifndef GRAPHFUNCTIONALITY_H
#define GRAPHFUNCTIONALITY_H


#include <iostream>
#include <vector>
#include <list>
#include "graph.h"
using namespace std;

template<class T>
class Graph;
template <typename T>
class GraphInterface:public Graph<T>{
    public:
    vector<T> *cityList;
GraphInterface();
GraphInterface(T newVertex);
    int getNumEdges();
    void add (T vertex, int city, int distance);
    void remove (T vertex, T position);
    void getCityConnection(int Start, int last);
    ~GraphInterface() {}
    void DepthRecur(int vertex, bool visit[]);
    void Depth(int rootvertex);
    void bread(int rootvertex);
    T* list2matrix();
};



template<class T>
GraphInterface<T>::GraphInterface(){}
template<class T>
GraphInterface<T>::GraphInterface(T newVertex):Graph<T>(newVertex){
    cityList = new vector<T>[Graph<T>::getVertices()];
}

template<class T>
void GraphInterface<T>::add (T vertex, int city, int distance){
    Graph<T>::addEdge(vertex,distance);
cityList[vertex].push_back(city);
}

template<class T>
void GraphInterface<T>::remove(T vertex,T position){
cityList[vertex].erase(position);
}
template<class T>
void GraphInterface<T>::getCityConnection(int start, int last){
    int pos = 0;

for (vector<int> ::iterator i = cityList[start].begin(); i != cityList[start].end(); ++i)
if(cityList[start].at(pos) == last){
cout << "City " << start << " is connected to City " << last << " with distance ";
 Graph<T>::getEdgeWeight(start,pos++); //<< '/n';
}
}
template<class T>
void GraphInterface<T>::DepthRecur(int vertex, bool visit[])
{
//Sets Current vertex as visited
    visit[vertex] = true;
    cout << "City: " << vertex << '\n';

//Going through all vertexes city points to
    for (vector<int>::iterator i = cityList[vertex].begin(); i != cityList[vertex].end(); i++){
            //If haven't visited yet
        if (!visit[*i])
        //Recurssion - Does function again but with i as new vertex
            DepthRecur(*i, visit);
    }

}
template<class T>
void GraphInterface<T>::Depth(int rootVertex)
{
    cout << "Depth First Search \n";
 //Bool array of visited vertexes
    bool *visit = new bool[Graph<T>::getVertices()];
    //Sets all array elements as false but it is false by default so this is redundant
    /*for (int i = 0; i < Graph<T>::getVertices(); i++)
        visited[i] = false; */
//Sends starting vertex and the bool array
    DepthRecur(rootVertex, visit);
}
template<class T>
void GraphInterface<T>::bread(int rootVertex){
    cout << "Breadth First Search\n";
    //bool array of visited cities. root vertex set to true
    bool *visit = new bool[Graph<T>::getVertices()];
        visit[rootVertex] = true;
//create queue and send root
    list<int> queue;
    queue.push_back(rootVertex);
    while(!queue.empty())
    {
    //Print
    cout << "City: "<< queue.front() << '\n';
    //Goes through vertex list. If not visited, send to queue
        for (vector<int> ::iterator i = cityList[queue.front()].begin(); i != cityList[queue.front()].end(); ++i)
            if (!visit[*i]){
                visit[*i] = true;
                queue.push_back(*i);
    }
    //pop current vertex
    queue.pop_front();
    }
}
template <class T>
T* GraphInterface<T>::list2matrix(){
    //Code I was working on but not enough time to debug
 //T* matrix[Graph<T>::getVertices()][Graph<T>::getVertices()];
    //return matrix;
}

#endif // GRAPHFUNCTIONALITY_H
