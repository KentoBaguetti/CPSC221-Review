# Graph Notes for 221
### What is a Graph?
Collection of vertices (nodes) connected via edges. <br><br>
**G = (V, E)** <br><br>
**V** is a set of vertices; {v_1, v_2, v_3, ..., v_n} <br><br>
**E** is a set of edges; {e_1, e_2, e_3, ..., e_m} where each e_i is a pair of vertices: e_i = (V x V) <br><br>
If each edge is an ordered pair, eg (A,B) != (B,A) then the graph is **directed** (The edges have a direction, they act like a one way street) otherwise the graph is **undirected** <br><br>
![Basic Graphs](./assets/basic_graph.jpeg)
### Graph Terminology:
**Vertices Adjacent to *V*:** *N(v)* Neighbouring vertices to a vertex. Represented as a set of vertices <br><br>
**Edges Incident to *V*:** *I(v)* Set of edges attached to a particular vertex <br><br>
**Degree of *V*:** *|I(v)|* The number of edges connected to a vertex (Integer)<br><br>