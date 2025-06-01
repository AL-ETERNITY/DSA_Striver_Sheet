// implement queue using array
#include <iostream>
using namespace std;

class Queue {
    private:
        int *arr;
        int front;
        int rear;
        int size;
        
    public:
        Queue(){
            size = 100005;
            arr = new int[size];
            front = rear = 0;
        }

        void push(int x){
            if (rear == size) return;
            else{
                arr[rear] = x;
                rear++;
            }
        }

        int pop(){
            if (front == rear) return -1;
            else{
                int ans = arr[front];
                arr[front++] = -1;
                if (front == rear) {
                    front = rear = 0; // Reset queue when empty
                }
                return ans;
            }
        }

        bool isEmpty() {
            return (front == rear);
        }

        int getFront() {
            if (front == rear) return -1;
            return arr[front];
        }
};