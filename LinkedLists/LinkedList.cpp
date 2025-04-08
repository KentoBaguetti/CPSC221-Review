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
// Linked Node Structs
//////////////////////////////////////////////////////////////////

template <class LIT>
struct SinglyLinkedNode {
    LIT data;
    SinglyLinkedNode* next; // pointer to the next node
    SinglyLinkedNode (LIT data, SinglyLinkedNode* next=nullptr) : data(data), next(next) {} // constructor
};

template <class LIT>
struct DoublyLinkedNode {
    LIT data;
    DoublyLinkedNode* prev;
    DoublyLinkedNode* next;
    DoublyLinkedNode (LIT data, DoublyLinkedNode* prev=nullptr, DoublyLinkedNode* next=nullptr) : data(data), prev(prev), next(next) {} // constructor
};

template <class LIT>
SinglyLinkedNode<LIT>* reverse (SinglyLinkedNode<LIT>* head) {

    SinglyLinkedNode* curr = head;
    SinglyLinkedNode* prev = nullptr;

    while (curr) {

        SinglyLinkedNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

    }

    return prev;

}