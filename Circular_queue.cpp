// Implement a Circular Queue using an array. The queue should support the following operations:
// enqueue() — Add an element to the queue.
// dequeue() — Remove an element from the queue.
// peek() — Display the front element without removing it.
// display() — Display all elements of the queue.
// isEmpty() — Check whether the queue is empty.
// isFull() — Check whether the queue is full.
// The circular queue should reuse the empty spaces created after deleting elements.
#include <iostream>
using namespace std;
class CircularQueue
{
    const int n = 5;
    int arr[5];
    int front = -1;
    int rear = -1;

public:
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return (rear+1)%n==front;
    }
    void enqueue(int value)
    {
        if (!isFull())
        {
            if (isEmpty)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                rear = (rear + 1) % n;
            }
            arr[rear] = value;
        }
        else
        {
            cout << "Queue is full"<<endl;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty"<<endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            cout<<"Deleted: "<<arr[front]<<endl;
            front = (front + 1) % n;
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Front: "<<arr[front]<<endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            int i=front;
            while(true){
                cout<<arr[i]<<" ";
                if(i==rear)
                    break;
                i=(i+1)%n;
            }
        }
        cout<<endl;
    }
};
int main()
{
    CircularQueue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.dequeue();
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.enqueue(70);
    q1.peek();
    q1.display();
    return 0;
}