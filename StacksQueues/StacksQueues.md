## Stacks
- **FILO:** First in, Last out. Or **LIFO:** Last in, First out<br>
- Think about a stack of plates. When you stack them one by one, when you remove a plate, you remove the most recently placed plate. So the last plate removed will be the first plate that was added. <br>
- A Singly Linked List is a good data structure for a stack <br>
- You can also use arrays, but they have resizing cases which may be annoying <br><br>

## Queues
- **FIFO:** First in, First out. *Fair data structure* <br>
- Items are inserted at the tail and removed from the front <br>
- Like a queue for a cashier <br><br>

## Implementations
- Both stacks and queues are quite similar to each other so they can be implemented with the same data structures <br><br>

 #### Array Implementation
 - O(1) for pop operations
 - O(n) upper bound for push, averge of O(1)
 - O(n) upper bound in the case we need to resize the array <br>

#### Linked List Implementation
- O(1) for all operations
- Assuming a good implementation of the stack eg tail and head pointer <br><br>

## Circular Arrays
- The end of the array "wraps" around to the start of the array <br>
- We can do with use the *modulo* operator, using it to calculate the front and back positions in a circular array <br>

## Array Resizing
- Arrays are static, vectors resize automatically but we may want more control ourselves <br>
- When an array fills up and we need more space, we need to resize the array <br>
- We can do this by creating a new array with a bigger capacity, copy elements from the old array into the new array, and make the old array pointer point to our new array. Then delete the old array <br>
- Creating the new array is constant, so O(1) time. Copying elements takes O(n) time. Managing  pointers is also constant, so O(1) <br>
- Overall time to resize is O(n) <br>
- Avg insertion into an array is O(1) <br>
- Worst case scenario, insertion is O(n) <br>
