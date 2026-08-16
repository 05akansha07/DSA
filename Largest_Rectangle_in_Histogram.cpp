// Given an array of integers heights representing the histogram's bar height where 
//the width of each bar is 1, return the area of the largest rectangle in the histogram.
// Examples
// Example 1:
// Input: heights = [2, 4, 4, 7, 2, 5, 8]
// Output: 14
// Explanation: The largest rectangle has a height of 2 and extends across all 7 bars (area = 2 * 7 = 14).
// Example 2:
// Input: heights = [2, 1, 5, 6, 2, 3]
// Output: 10
// Explanation: The largest rectangle is formed by bars [5, 6] with height 5 and width 2 (area = 5 * 2 = 10)
//Approach: Monotonic StackIntuition: For every bar i, we want to find the largest rectangle where 
//heights[i] is the limiting (shortest) height. To do this, we find:Previous Smaller Element: 
//Index of the first smaller bar to the left.Next Smaller Element: Index of the first smaller bar to the right.
//Stack Strategy: Maintain a stack of indices with strictly increasing bar heights.
//Trigger: Whenever we encounter a bar shorter than the bar at stack.top(), we pop from the stack and 
//compute the rectangular area with the popped bar's height.
//Width Calculation:
//*If stack is empty after pop:width = i 
//*If stack is not empty: width = i - stack.top() - 1
#include <iostream>
#include <stack>
using namespace std;
int largestRectangle(int arr[],int n)
{
    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            int height = arr[st.top()];
            st.pop();

            int width;
            
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            int area = height * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int height = arr[st.top()];
        st.pop();
        int width;
        if (st.empty())
            width = n;
        else
            width = n - st.top() - 1;

        int area = height * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main(){
    int arr[] = {2, 4, 4, 7, 2, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Largest Rectangle Area:"<<largestRectangle(arr,n)<<endl;
    return 0;
}