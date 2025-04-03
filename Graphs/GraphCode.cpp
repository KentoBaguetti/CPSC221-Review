#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;

//////////////////////////////////////////////////////////////////
// Graph implementations
// !!!!! These implementations are my quick implementations !!!!!!
//////////////////////////////////////////////////////////////////

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

struct WeightedGraph {

    // Vertex : [{neighbor, weight},...]
    unordered_map<int, list<pair<int, int>>> adjList;
    set<int> vertices;

};

/////////////////////////////////
// Disjoint Set Implementation # to be used by some algos
/////////////////////////////////

struct DisjointSet {

    unordered_map<int, int> disjointSet;

    void addNode (int i) {
        disjointSet[i] = -1;
    }

    // find with path compression
    int find (int i) {

        if (disjointSet[i] < 0) return i;
        disjointSet[i] = find(disjointSet[i]);
        return disjointSet[i];

    }

    bool inSameSet (int i, int j) {
        
        int rootI = find(i);
        int rootJ = find(j);

        return rootI == rootJ;

    }

    void mergeSets (int i, int j) {

        int rootI = find(i);
        int rootJ = find(j);

        if (rootI == rootJ) return;

        if (disjointSet[rootI] <= disjointSet[rootJ]) {

            disjointSet[rootI] += disjointSet[rootJ];
            disjointSet[rootJ] = rootI;

        } else {

            disjointSet[rootJ] += disjointSet[rootI];
            disjointSet[rootI] = rootJ;

        }

    }

};

/////////////////////////////////
// Breadth First Search
/////////////////////////////////

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

/////////////////////////////////
// Depth First Search
/////////////////////////////////

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

/////////////////////////////////
// Topological sort(s)
/////////////////////////////////

// khan's algoritm for topological sort
vector<int> topological_sort_khan (GraphAdjacencyList G) {

    // the resulting topologically sorted graph to be returned
    vector<int> res;

    unordered_map<int, int> inDegreeCount;

    // set each in-degree as 0
    for (int vertex : G.vertices) {
        inDegreeCount[vertex] = 0;
    }

    // update the in-degrees of every vertex
    for (int vertex : G.vertices) {
        for (int neighbour : G.adjList[vertex]) {
            inDegreeCount[neighbour]++;
        }
    }

    // initialize the queue with all the 0-degree vertices
    queue<int> q;
    for (int vertex : G.vertices) {
        if (inDegreeCount[vertex] == 0) q.push(vertex);
    }

    while (!q.empty()) {

        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // reduce the in-degree counts for each vertice adjacent to our current vertex | add new vertices with in-degree 0 to the queue
        for (int neighbor : G.adjList[curr]) {
            inDegreeCount[neighbor]--;
            if (inDegreeCount[neighbor] == 0) q.push(neighbor);
        }

    }

    // we can check if the graph has a cycle if the length of res != |V|
    return res;

}

/////////////////////////////////
// MST Algorithms
/////////////////////////////////


unordered_map<int, list<pair<int, int>>> KruskalsAlgorithm (WeightedGraph G) {

    int numberOfVertices = G.vertices.size();
    int edgeCount = 0;

    unordered_map<int, list<pair<int, int>>> res;
    int totalWeight = 0;

    priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<>> pq;

    // PQ stores { weight, { node, adjacentNode } }
    for (int vertex : G.vertices) {

        for (pair<int, int> neighbor : G.adjList[vertex]) {

            pq.push({neighbor.second, {vertex, neighbor.first}});

        }

    }

    DisjointSet ds;
    for (int vertex : G.vertices) {
        ds.addNode(vertex);
    }

    while (edgeCount != numberOfVertices - 1 && !pq.empty()) {

        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;
        int edgeWeight = curr.first;
        
        if (ds.inSameSet(i, j)) continue;

        totalWeight += edgeWeight;
        edgeCount++;
        res[i].push_back({j, edgeWeight});

        ds.mergeSets(i, j);

    }

    return res;

}

unordered_map<int, list<pair<int, int>>> PrimsAlgorithm (WeightedGraph G) {

    // { vertex, { adjVertex, weight } }
    unordered_map<int, list<pair<int, int>>> res;

    // stores { weight, { vertex, adjacentVertex } }
    priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<>> pq;

    // initialize the PQ
    for (int vertex : G.vertices) {

        for (pair<int,int> neighbor : G.adjList[vertex]) {

            pq.push({neighbor.second, {vertex, neighbor.first}});

        }

    }

    set<int> seenVertices;
    int maxVertices = G.vertices.size(); // number of vertices in the graph

    pair<int, pair<int, int>> firstVertex = pq.top();
    pq.pop();

    // add the first vertex to the MST
    seenVertices.insert(firstVertex.second.first);
    res[firstVertex.second.first].push_back({firstVertex.second.second, firstVertex.first});


    while (seenVertices.size() < maxVertices) {

        pair<int, pair<int, int>> curr = pq.top();
        int currVertex = curr.second.first;
        int adjVertex = curr.second.second;
        int weight = curr.first;

        if (seenVertices.contains(currVertex)) continue;

        res[currVertex].push_back({adjVertex, weight});
        seenVertices.insert(currVertex);

    }

    return res;

}

int main () {

    return 0;

}