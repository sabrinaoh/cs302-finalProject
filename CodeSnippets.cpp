#include "Graph.h"
#include <iterator>

template <typename T>
void breadthFirstSearch(T start, void visit(T&)){
    bool *visited = new bool[vertices];
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);
    list<int>::iterator i;
    while(!queue.empty()){
        start  = queue.front();
        visit(start);
        queue.pop_front();
        for (i = adjacency[start].begin(); i != adjacnecy[start].end; i++){
            if (!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

template <typename T>
void depthFirstSearch(T start, bool visited[], void visit(T&)){
    visited[start] = true;
    visit(start);
    list<int>::iterator i;
    for (i = adjacency[v].begin; i != adjacency[v].end(); i++){
        if (!visited[*i]){
            depthFirstSearch(*i, visited, visit(T&);)
        }
    }
}

//uses depthFirstSearch
template <typename T>
void DFS(T start){
    bool * visited = new bool[vertices]
    for (int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    depthFirstSearch(start, visited);
}
//Based off of Section 13, Presentation 3, Slide 14
template <typename T>
void shortestPath (Graph<T> theGraph, vector<vector<T> > adjacencyWithWeights){
    list<int> vertexSet;
    vertexSet.push_back(0);
    int n = numberOfVertices;
    for (int v = 0; v < n; v++){
        adjacencyWithWeights[v] = matrix[0][v];
    }
    for(int s = 2; s < n; s++){
        if(vertex is not in vertexSet){
            vertexSet.push_back(vertex);
            for(all vertices u not in vertexSet){
                if (weight[u] > weight[v] + matrix[u][v]){
                    weight[u] = weight[v] + matrix[v][u];
                }
            }
        }
    }
}

//Finds the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree
template <typename T>
T minDistance (T distance[], bool sptSet[]){
    int min = INT_MAX, min_index;
    for(int v = 0; v < vertices; v++){
        if(sptSet[v] == false && dist[v] <= min){
            min = dist[v],min_index = v;
        }
    }
    return min_index;
}