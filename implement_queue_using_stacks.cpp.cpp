/*
 * Problem: Implement Queue using Stacks (LeetCode 232)
 * Platform: LeetCode / GFG
 * Difficulty: Easy / Medium
 * 
 * Description:
 * Implement a first-in, first-out (FIFO) queue using only two stacks.
 * The implemented queue should support all standard queue operations:
 * push(x), pop(), peek(), and empty().
 * 
 * Approach:
 * - Use two stacks: `innerStack` (input inbox) and `OuterStack` (output outbox).
 * - `push()`: Always push into `innerStack`.
 * - `pop()` / `peek()`: If `OuterStack` is empty, transfer all elements from `innerStack` 
 *   to `OuterStack` (reversing their order to achieve FIFO behavior).
 * 
 * Complexities:
 * - Time Complexity:
 *     - push(): O(1)
 *     - pop(): Amortized O(1), Worst-case O(N) during transfer
 *     - peek(): Amortized O(1), Worst-case O(N) during transfer
 *     - empty(): O(1)
 * - Space Complexity: O(N) to store elements across the two stacks.
 */
#include<iostream>
#include<stack>
using namespace std;
class MyQueue{
    private:
    stack<int>innerStack;
    stack<int>OuterStack;
    
    void tranfer(){
        if(OuterStack.empty()){
            while(!innerStack.empty()){
                OuterStack.push(innerStack.top());
                innerStack.pop();
            }
        }
    }
    public:
    MyQueue() {}
    void push(int x){
        innerStack.push(x);
    }
    int pop(){
        tranfer();
        int val =OuterStack.top();
        OuterStack.pop();
        return val;
    }
    int peek(){
        tranfer();
        return OuterStack.top();
    }
    bool empty(){
        return innerStack.empty() && OuterStack.empty();
    }
};
int main(){
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; 
    cout << "Popped: " << q.pop() << endl;         
    cout << "New Front: " << q.peek() << endl;     

    return 0;
}
