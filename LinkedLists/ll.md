## Linked Lists
##### General Overview
- A linked list is a dynamic data structure that consists of nodes linked together <br>
- A **Node** is a data structre that contains data and pointers to the next node(s) <br>
- The pointers store an address to other nodes <br>
- A linked list is a *chain* of nodes <br>
- In C++ the memory locations are not stored in a sequence but scattered throughout memory unlike an array <br>
- Two main types of linked lists: **Singly** and **Doubly** Linked lists <br>
- Singly linked lists have ony pointer to the next node <br>
- Doubly linked lists have two pointers, one to the node that points to it, prev, and the next node in the sequence <br>

##### Traversing a Linked List
- Generally, traversing a linked list happens in **O(n)** time as you have to iterate over each node, unlike an array where you can access indexes <br>
- If you have pointers to specific nodes, then you can access them in **O(1)** time, such as the head pointer or sometimes the tail pointer as well <br>
- Iterate over a linked list by accessing the next node pointer stored in your current node <br><br>

##### Inserting into a Linked List
- When inserting, you first need to find the insertion location **O(n)** <br>
- Update the pointers accordingly **O(1)** <br><br>
- In a singly linked list:
1. Find the insertion location by updating your current node
2. Store the pointer of the next node of the current node in a temp variable
3. 