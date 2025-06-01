// implementation of a queue using a linked list
#include <iostream> 
using namespace std;

class Queue {
    public:
        int val;
        Queue* next;

        Queue(int d) {
            this -> val = d;
            this -> next = NULL;
        }

        void enqueue(int element, Queue* &head, Queue* &tail) {
            Queue *newNode = new Queue(element);
            if (head == NULL) {
                // first element enqueue
                head = newNode;
                tail = newNode;
                return;
            } else {
                // assuming element is present
                tail -> next = newNode;
                tail = newNode;
            }
        }

        int dequeue(Queue* &head, Queue* &tail) {
            if (head == NULL) {
                // if no element is present
                return -1;
            } else {
                int ans = head->val;
                // edge case for last element
                if (head == tail) {
                    head = NULL;
                    tail = NULL;
                }
                head = head -> next;
                return ans; // return the value of dequeued node
            }
        }

        int front(Queue* &head) {
            if (head == NULL) {
                cout << "Queue Underflow " << endl;
                return -1; // or some error value
            } 
            else {
                return head -> val;
            }
        }
};