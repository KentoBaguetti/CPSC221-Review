#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
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

struct GraphAdjacencyList {
    // Adjacency list: each node has a list of its neighbors
    unordered_map<int, list<int>> adjList;
    set<int> vertices;

    // Add a vertex to the graph 
    void addVertex(int vertex) {
        adjList[vertex];
    }

    void addEdge(int src, int dest, bool undirected = true) {
        adjList[src].push_back(dest);
        if (undirected) {
            adjList[dest].push_back(src);
        }
    }

    void printGraph() const {
        for (const auto& pair : adjList) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

void BFS (GraphAdjacencyList G, int vertex, unordered_map<pair<int, int>, bool>& visitedEdges, unordered_map<int, bool>& visitedVertices) {

    queue<int> q;
    q.push(vertex);
    visitedVertices[vertex] = true;

    while (!q.empty()) {

        int curr = q.front();
        q.pop();
        for (int neighbor : G.adjList[curr]) {

            // if the neighboring vertex hasn't been visited
            if (!visitedVertices[neighbor]) {

                visitedEdges[{curr, neighbor}] = true;
                visitedVertices[neighbor] = true;
                q.push(neighbor);

            } else if (visitedEdges.find({curr, neighbor}) == visitedEdges.end()) { // if the vertex has been visited but not the edge

                visitedEdges[{curr, neighbor}] = false;

            }

        }

    }

}

void Algorithm_Traverse_BFS (GraphAdjacencyList G) {

    // true = Discovery
    // false = Cross
    // unvisited edges don't need to be stored as we will "visit" every edge by the time BFS terminates
    unordered_map<pair<int, int>, bool> vistedEdges;

    // false = Unvisited
    // true = Vistied
    unordered_map<int, bool> visitedVertices;

    for (int vertex : G.vertices) {
        visitedVertices[vertex] = false;
    }

    for (int vertex : G.vertices) {
        if (visitedVertices[vertex] = false) BFS(G, vertex, vistedEdges, visitedVertices);
    }

}

void DFS (GraphAdjacencyList G, int vertex, unordered_map<pair<int, int>, bool>& visitedEdges, unordered_map<int, bool>& visitedVertices) {

    visitedVertices[vertex] = true;

    for (int neighbor : G.adjList[vertex]) {

        if (!visitedVertices[neighbor]) { // if the vertex is unexplored

            visitedEdges[{vertex, neighbor}] = true;
            DFS(G, neighbor, visitedEdges, visitedVertices);

        } else if (visitedEdges.find({vertex, neighbor}) == visitedEdges.end()) { // if the vertex has been visited but not the edge

            visitedEdges[{vertex, neighbor}] = false;

        }


    }

}

void Algorithm_Traverse_DFS (GraphAdjacencyList G) {

     // true = Discovery
    // false = back
    // unvisited edges don't need to be stored as we will "visit" every edge by the time BFS terminates
    unordered_map<pair<int, int>, bool> vistedEdges;

    // false = Unvisited
    // true = Vistied
    unordered_map<int, bool> visitedVertices;

    for (int vertex : G.vertices) {
        visitedVertices[vertex] = false;
    }

    for (int vertex : G.vertices) {
        if (visitedVertices[vertex] = false) DFS(G, vertex, vistedEdges, visitedVertices);
    }

}

int main () {

    return 0;

}