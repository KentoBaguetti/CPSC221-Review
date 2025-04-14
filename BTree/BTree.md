# B-Trees
- Puts more relevant data together in a single block to minimize disk accesses <br>
- Do this by increasing the number of keys and children per node <br>

## B-Tree Properties
- B-Tree of order *m* <br>
- Internal Node: # keys = # children - 1 <br>
- All leaves are at the same depth <br>
- All leaves hold no more than m - 1 keys <br>
- All **non-root** internal nodes have between (ceiling) m/2 and m children <br>
- The root can be a leaf or have at least 2 children <br>
- **Max number of keys in a B-Tree of order *m* and height *h*:** m^(h+1) - 1 (The exact same equation used for the max number of nodes in a binary tree just slightly modified) <br>
- **Min Number of keys in a B-Tree of order *m* and height *h*:** 2(m/2)^h - 1 (When we divide m, we do ceiling division) <br><br>

## Search
- For each node, we need to perform a linear search through m - 1 keys, so **O(m)** per node, or **O(logm)** with Binary Search <br>
- We need to search nodes down a single path, so **O(height) == O(logn)** <br>
- B-Tree search is then **(mlogn)** <br>
- 
