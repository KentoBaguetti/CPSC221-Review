# Graph Notes for 221

## What is a Graph?
Collection of vertices (nodes) connected via edges. <br><br>
**G = (V, E)** <br><br>
**V** is a set of vertices; {v_1, v_2, v_3, ..., v_n} <br><br>
**E** is a set of edges; {e_1, e_2, e_3, ..., e_m} where each e_i is a pair of vertices: e_i = (V x V) <br><br>
If each edge is an ordered pair, eg (A,B) != (B,A) then the graph is **directed** (The edges have a direction, they act like a one way street) otherwise the graph is **undirected**.  <br><br>
![Basic Graphs](./assets/basic_graph.jpeg)

## Graph Terminology:
- **Vertices Adjacent to *V*:** *N(v)* Neighbouring vertices to a vertex. Represented as a set of vertices <br><br>
- **Edges Incident to *V*:** *I(v)* Set of edges attached to a particular vertex <br><br>
- **Degree of *V*:** *|I(v)|* The number of edges connected to a vertex (Integer)<br><br>
- **Path:** Sequence of vertices connected by edges <br><br>
- **Simple Path:** A path with no repeated vertices. No Dupes <br><br>
- **Cycle:** A path with the same start and end vertex <br><br>
- **Simple Graph:** No self-loops or multi edges. **Self-loops** are when a vertex has an edge that points to itself. **Multi-Edges** are when two vertices have multiple edges between each other. <br><br>
- **Subgraph of *G = (V, E)*:** Small part of the graph *G*. All the vertices in the subgraph G' are also in *V*. All edges in G' are in *E*. If (u, v) is in E', then u and v are in V'. <br><br>
- **Complete Graph:** A graph where every vertex is connected to every other vertex <br><br>
- **Connected Graph:** A graph where there exists a path between every pair of vertices <br><br>
- **Connected Component:** A connected subgraph <br><br>
- **Acyclic Graph:** A graph with no cycles <br><br>
- **Spanning Tree of *G = (V, E)*:** Acyclic, connected graph with vertex set *V*. It contains all the vertices of the original graph and its connected. It "spans" the entire graph. Spanning trees have *n - 1* edges, *n* being the number of vertices. There can be many different possible spanning trees for a graph.<br><br>

## Weight Graphs
In a *weighted graph*, each edge is assigned a weight (Some value, normally a number). <br>
The weight represents the cost to travel along the edge. (They can possibly be negative) <br>
- Dijkstras algorithm uses weighted graphs to find the shortest path between two vertices. But it can't handle negative weights, gotta use the Bellford-Whatever-the-fuck algo. <br><br>

## Connectivity
- Undirected graphs are **connected** if there is a path between any two vertices <br><br>
- Directed graphs are **Strongly connected** if there is a directed path from any vertex to another. You can get to any vertex from any starting vertex within a directed graph. <br><br>
- Digraphs are **weakly connected** if there is a path between any two vertices, ignoring direction. Still a directed graph, but not strongly connected