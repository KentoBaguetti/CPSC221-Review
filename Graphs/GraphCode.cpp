#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct GraphMatrix {
    
    vector<vector<int>> AdjacencyMatrix;
    vector<int> vertices;
    vector<pair<int,int>> edges;

    void insertVertex (int vertexData);
    void insertEdge (int edgeData);
    void removeVertex (int vertex);
    void removeEdge (int edge);

    vector<pair<int,int>> incidentEdges (int vertex);
    bool areAdjacent (int vertex1, int vertex2);

};