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
// Stack and Queue Classes
//////////////////////////////////////////////////////////////////

template <class LIT>
class Stack {

    public:
        Stack() : size(0) {}

        ~Stack() {
            while (!isEmpty()) {
                Pop();
            }
        }

        bool isEmpty () {
            return top == nullptr;
        }

        void Push (const LIT& e) {
            Node* newNode = new Node(e);
            newNode->next = top;
            top = newNode;
            size++;
        }

        LIT Pop() {
            Node* curr = top;
            top = top->next;
            LIT data = curr->data;
            delete curr;
            curr = nullptr;
            size--;
            return data;
        }

        int getSize () {
            return size;
        }
    
    private:
        struct Node {
            LIT data;
            Node* next;

            Node(const LIT& data, Node* next = nullptr) : data(data), next(next) {}
        };
        Node* top = nullptr;
        int size;

};


int main () {

    Stack<int> s;
    s.Push(1);
    s.Push(2);
    cout << s.getSize() << endl;

    return 0;

}