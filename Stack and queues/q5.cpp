#include <iostream>
using namespace std;

// Implementation of Stack using Linked List
class Stack{
    public:
    int val;
    Stack* next;


    Stack(int d){
        this -> val = d;
        this -> next = NULL;
    }
    
    void push(int element,Stack* &head,Stack* &tail){
        Stack *newNode = new Stack(element);
        if( head == NULL){
            //first element push
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            //assuming element is present
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop(Stack* &head,Stack* &tail){
        if( head == NULL){
            //if no element is present
            cout << "Stack Underflow "<<endl;
        }
        else{
            //edge case for last element
            if( head == tail){
                head = NULL;
                tail = NULL;
                return;
            }
            Stack* temp = head;
            while( temp -> next != tail){
                temp = temp -> next;
            }
            temp -> next = NULL;
            tail = temp;

        }
    }

    int peek(Stack* &tail){
        if( tail == NULL){
            cout << "Stack Underflow " << endl;
        }
        else{
            return tail -> val;
        }
    }

    bool isEmpty(Stack* &head){
        if( head == NULL){
            return true;
        }else return false;
    }

};