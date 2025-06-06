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
- **Spanning Forest:** Collection of spanning trees, one for each connected component <br><br>

## Weighted Graphs
In a *weighted graph*, each edge is assigned a weight (Some value, normally a number). <br>
The weight represents the cost to travel along the edge. (They can possibly be negative) <br>
- Dijkstras algorithm uses weighted graphs to find the shortest path between two vertices. But it can't handle negative weights, gotta use the Bellford-Whatever-the-fuck algo. <br><br>

## Connectivity
- Undirected graphs are **connected** if there is a path between any two vertices <br><br>
- Directed graphs are **Strongly connected** if there is a directed path from any vertex to another. You can get to any vertex from any starting vertex within a directed graph. <br><br>
- Digraphs are **weakly connected** if there is a path between any two vertices, ignoring direction. Still a directed graph, but not strongly connected

## Isomorphism and Subgraphs
- **Isomorphic Graphs:** Graphs with identical structure (Ignoring the names of the vertices). Isomorphic graphs have the name number of vertices, edges, and each pair of vertices are conencted in the same way. If One of these are violated, the graph is not isomorphic. <br><br>
- **Subgraph:** Graph that is isomorphic to a *part* of another graph <br><br>

## Degree
- **Degree of a vertex** represesnts the number of edges incident to a vertex <br><br>
- **Handshaking theorem:** If *G = (V, E)* is an undirected graph, then the number of vertices. ∑deg(v) = 2|E|.<br> Each pair of vertices only has one edge between the two. If you had two vertices connected to each other, there is only one edge, not two. The handshaking formula may make more sense when rearranged to be 1/2∑deg(v) = |E|. <br><br>

## Degree for directed graphs
- **In-Degree:** The number of edges entering *v*. Denoted as deg^- (v) <br><br>
- **Out-Degree:** The number of edges leaving *v*. Denoted as deg^+(v) <br><br>
- deg(v) = deg^-(v) + deg^+(v) <br><br>

## Graph Density
- **Sparse Graph:** has O(|V|) edges. Each vertex has at most O(1) neighbors. Remeber O(x) is an upperbound <br><br>
- **Dense Graph:** has Θ(|V^2|) edges. Eg if every vertex has O(|V|) neigbours. Eg a complete graph. <br><br>
- Anything inbetween is either on the spare side or on the dense side, depending critically on the context. <br><br>

## How many edges?
**At least:**
- Connected: *n - 1* edges. Eg a spanning tree <br>
- Not connected: 0 edges. A bunch of vertices with zero edges. <br><br>
**At most:**
- Simple: *n(n-1)/2* edges. Every vertex conenects to every other vertice. <br>
- Not simple: *Unbounded*. Imagine two vertices, with an infinite number of edges that connect the two. <br><br>

## Adjacency Matrix
- Vertices are stored in a matrix, with the indexes of the arrays representing each vertice. The intersecting cell signifies to us if there is an edge between the two vertice. You can use anything like a boolean for this. <br><br>
- Vertices can be stored in a hashmap so you can map vertice names to an integer value. Because an adjacency matrix is just two arrays, and arrays use integer indexes Kasper. <br><br>
- Edges can also be stored in a hashmap so you can map vertice names + edges to an integer value <br><br>
- **insertVertex(vertex v)** O(n) amortized. Like when you're inserting into an array. You might have to shift elements, and you also have to add edges. <br><br>
- **removeVertex(vertex v)** O(n) amortized. Like when you're removing from an array, you mught have to shift elements and also remove any corresponding edges. <br><br>
- **areAdjacent(vertex v, vertex u)** O(1). Arrays have O(1) lookup on its indexes which makes checking if two vertices are connected quick. <br><br>
- **incidentEdges(vertex v)** O(n). Check every value in a vertex's row (or column) and find which other vertices are connected to a vertex. <br><br>
- **Space usage:** O(n) + O(m) + O(n^2) = O(n^2).
- *m* is the edges. *n* is the vertices. <br><br>
- *Unweighted*: The matrix can contain booleans <br>
- *Weighted*: The matrix contains the edge weights. Use a value like infinity for edges that DNE. <br><br>

## Adjacency List
- Vertices are stored in a hashmap (or even an array if the index corresponds to a vertex). The key (or index) is the vertex, and the value stores a linked list of all adjacent vertices. Use a doubly-linked list for O(1) removals. O(n) space used<br><br>
- Edges are also stored in a hashmap (or array) where the key (or index) represents the edge name, and it stores a pair of vertices, which are the two vertices the edge connects. O(m) space used. <br><br>
- **insertVertex(vertex v)** O(1) <br><br>
- **removeVertex(vertex v)** deg(v). You need to remove its connection to every other vertex v is connected to. <br><br>
- **areAdjacent(vertex v, vertex u)** worst case: max(deg(v), deg(u)). Since you need to go through every incident edge.
if the list tracks its length: min(deg(v), deg(u)) <br><br>
- **incidentEdges(vertex v)** deg(v) <br><br>
- **Space usage:** O(n + m) <br><br>

## Edge List
- Edges are stored in a hashmap or array <br><br>
- Uses less space but poor perofrmance for most operations <br><br>

## Time Complexities of Graph Implementations
![Graph Runtimes](./assets/graph_implementaion_rt.jpeg)
<br><br>

## Graph Traversals
- **Objective:** Visit every vertex and every edge in the graph <br><br>

## Breadth First Search (BFS)
- Similar to the level order traversal of a tree. You vist each "distance" level from a starting vertex. Use a queue to implement this algorithm just like with level order traversal. <br><br>
#### Full traversal algo of G with BFS:
- First label all vertices as **UNVISITED** <br>
- First label all edges as **UNEXPLORED** <br>
- For all unvisited vertices, run the **BFS** algorithm <br>
- The BFS algo won't run on all vertices unless the graph has zero edges. Best case scenario we run BFS once. <br><br>

#### BFS Algo
- Takes a graph and vertex as input parameters <br>
- Similar to a level-order traversal, use a Q to store unvisited vertices <br>
- Push the first vertex into the queue and run a while loop to iterate while the queue is not empty. <br>
- Pop *v* from the queue. Loop through all adjacent vertices to *v* <br>
- If the neighbouring vertex is unvisited, set it as visited, label the edge to it as **discovery** and add *v* to the queue <br>
- If the neighboring vertex has been visited but the edge to it has not been "crossed", label the edge as **Cross** <br><br>

#### General Observations of BFS
- For *n* vertices, there are *n-1* discovery edges <br>
- The discovery edges form a spanning tree <br>
- The "distances" form the length of the shortest path from the starting vertex and the predecessor vertices form a shortest path in the sequence of vertices <br>
- One BFS() vists one connected component <br>
- Running time of **O(n + m)** (with adjacency list) <br>
- Checks all edges and vertices <br><br>


## Depth First Search (DFS)
- Like the other three tree traversals, uses a **stack**. Can be done recursively by taking advantage of the call stack. <br><br>
- Visits vertices along a single path as far as it can go, like how in pre-order traversal we go down one side of a tree as far as we can go. <br>
- Then backtracks to the first junction and goes down that path. <br>
- Process repeats until all vertices in the given component has been visited. <br><br>

#### Full Traversal algo of G with DFS
- Label the edges of *G* as **discovery** or **back** edges <br>
- We do the same thing we did with BFS where we set all vertices as unvisited and all edges as unexplored <br>
- Then for all unvisited vertices, we run the DFS algo <br><br>

#### DFS Algo
- Set the current vertex as **visited** <br>
- For all neighbours of the current vertex, if the neighbor hasn't been visited, label the edge to it as **Discovery** and recursively call DFS on that neighbour <br>
- If the neighbor has been visited, but the edge is unexplored, label the edge as **back** <br>

#### General Observations
- The discovery edges form a spanning tree <br>
- One DFS instance visits one connected component <br>
- Time complexity of DFS: **O(n + m)** (with adjacency list)

## DAG
- Directed Acyclic Graph <br>
- Has a direction
- Does not contain cylces
- Can be weighted

## Topological Sort (Khan's Algorithm)
- Linear ordering of vertices in a **DAG** such that for every directed edge "u -> v", "u" comes before "v" <br><br>
Adjacency List | Adjacency Matrix 
- Initialize each vertex's *in-degree* (# of inbound edges) O (m + n) | O(n^2) <br> 
- Initialize a queue to contain all vertices with an in-degree of zero O(n) <br>
- While the queue is not empty (queue contains vertices): (n times)
- Dequeue a vertex *v* from the queue and output it O(1)
- Reduce the in-degree of all vertices adjacent to *v* O(deg(v)) | O(n)
- Enqueue any vertices with an updated in-degree of zero into the queue O(1)
- Remove *v* from the queue O(1) <br><br>

- When using an adjacency list, the number of vertices/edges that have been processed it equal to ∑deg^-(v) (The sum of the in-degrees of every vertice) <br>
- Topological sort can be used for cycle detection if there are still vertice(s) remaining with in-degrees in a connected graph <br><br> 
[Topological Sort Question Leetcode](https://leetcode.com/problems/course-schedule/description/?envType=problem-list-v2&envId=topological-sort) <br><br>

## Spanning Tree
- **Spanning Tree of *G = (V, E)*:** Acyclic, connected graph with vertex set *V*. It contains all the vertices of the original graph and its connected. It "spans" the entire graph. Spanning trees have *n - 1* edges, *n* being the number of vertices. There can be many different possible spanning trees for a graph.<br><br>
- Touches all vertices in the graph
- Forms a tree, connected, contains no cycles, i.e. minimally connected
- You can make a spanning tree with the discovery edges from **BFS/DFS** <br><br><br>
- **Spanning Forest:** Collection of spanning trees, one for each connected component <br><br>
- Weighted graphs can have a **Minimum spanning tree** <br>
- The spanning tree with the least total edge cost <br><br>

## Minimum Spanning Trees (MST)
- Given a graph *G = (V, E)* with unconstrained (Positive or Negative) edge weights: <br>
- G' = (V, E') is an output graph with the following traits
- G' is a subgraph of G
- G' is connected and acyclic
- The sum of the edge weights of E' is minimal among all such spanning trees <br><br>

### Kruskal's Algorithm
- Builds a spanning tree from several *connected components* <br>
- Repeatedly chooses the min-weight joining two connected components <br><br>

Kens explanation cuz fuck slides
- Build the MST one at a time, starting from 0 <br>
- Add the smallest weight edge that does not cause a cycle (Use a priority Q and disjoint set) <br>
- Keep adding vertices until you have *|V| - 1* edges <br>
- Skip edges that would cause a cycle <br><br>

- Using a heap priority Q will cost us *|E|* time to build the PQ and *log|E|* for each removeMin, so *|E|log|E|* total <br>
- Using an ordered array PQ will cost us *|E|log|E|* time to build (using a good sorting algo) and *O(1)* for each removal, so *|E|log|E|* total <br><br>

- Maze construction is similar to Kruskal's algorithm, just change the use of a PQ for a random edge selection <br><br>

### Prim's Algorithm
- Build the spanning tree from initially one vertex <br>
- Repeatedly choose the min-weight edge from a vertex in the tree, to a vertex outside the tree (That does nott cause a cycle) and connect that vertex to the tree <br><br>

Kens version
- Build the MSt from one starting vertex <br>
- Continue building the tree by always adding the min-weight edge from the current tree to a new (nonconnected) vertex <br>
- Instead of iterating until we have *|V| - 1* edges, go until we've visited every vertice <br>
- Only needs a PQ, does not require a disjoint set <br><br>

- Interperse insertion and removal operations <br>
- Max number of insertions into the PQ is *|E|* in the worst case <br>
- Total cost of all insertions is O(|E|log|E|) <br>
- For dense graphs, |E| == O(|V|^2), which means log|E| is in O(2*log|V|) which is in O(log|V|) <br>
- Total time complexity of Prim's Algo is *O(|E|log|V|)*<br><br>



## Dijkstras Algorithm
Goal: Given a graph and a starting vertex *s*, find the shortest path from *s* to every other vertice in the graph<br>

#### How it Works:
1) Set the distance to the starting vertex as 0. Set the distance to every other vertice as infinity <br>
2) Use a PQ to find the vertex with the smallest distance from *s*
3) For each neighbor *v* of the chosen node *u*, check if the path from *s* to *v* is shorter through *u*, compared to the currently known shortest path. If it is shorter, update *v*'s distance
4) Once a vertex is extracted from the PQ, mark it as visited, its shortest distance has already been established as no alt routes go to it, therefore we can't find a shorter path
5) Repeat until all the vertices have been visited
[Visualization](https://visualgo.net/en/sssp) <br><br>

Time Complexity:
O((V + E)log(V))

## Time Complexities