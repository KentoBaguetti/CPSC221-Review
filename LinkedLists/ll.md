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
3. Make your current pointer point to your new node (The one ur inserting)
4. Make the next pointer of your new node point to the node stored in our temporary variable
5. Success <br><br>

##### Removing from a Linked List
- Similar concept to inserting into a linked list <br>
- This time, just make ur current node, the one previous to the node you want to remove, point to the next node of the node you want to remove <br>
- Make sure to **delete** the node you want to remove to clear up memory <br><br>

##### Singly Linked List
- Like a one way road, can only go in one direction <br>
- Can have a tail pointer so you can insert at the tail in **O(1)** time <br>
- Insertions in the middle of the list still take **O(n)** time <br>
- Removals also still take **O(n)** time, since we only have a pointer to the last node and not the second last node <br><br>

##### Doubly Linked List
- Two-way road, can traverse the list in two directions <br>
- Nodes provide pointers to its previous and next nodes <br>
- Insertions require you to manipulate more pointers but still trivial <br>
- Removals requrie you to manipulate more pointers but still trivial <br><br>

##### Linked List Variations
- **Circular Linked List:** A linked list whose tail pointer points to the head pointer (vice versa for a doubly linked list) <br>
- **Sentinal Nodes:** "Dummy" nodes at the ends of the list which do not contain any data. They eliminate the special edge cases for list modifcations so you don't need to point to a nullptr <br><br>
