// implementation of stack using array 
#include <iostream>
using namespace std;

class Stack{

    private:
        int *arr;
        int top;
        int size;
    
    public:
        Stack(int size) {
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int x){
            if(size - top > 1){
                top++;
                arr[top] = x;
            }
            else{
                return;
            }
        }

        int pop(){
            if(top >= 0){
                return arr[top--];
            }
            else{
                return -1;
            }
        }

        void peak(){
            if(top >= 0){
                cout << "Top element is: " << arr[top] << endl;
            }
            else{
                cout << "Stack is empty" << endl;
            }
        }

        bool isEmpty(){
            return (top == -1);
        }
};