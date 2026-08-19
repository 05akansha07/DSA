/**
 * ============================================================================
 * Problem: LeetCode 42 - Trapping Rain Water
 * Link: https://leetcode.com/problems/trapping-rain-water/
 * Difficulty: Hard
 * Topic: Monotonic Stack / Arrays
 * ============================================================================
 * 
 * Problem Statement:
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * Approach (Monotonic Decreasing Stack):
 * - Maintain a stack storing indices of bars in non-increasing height order.
 * - When current bar arr[i] is taller than arr[st.top()], a dip/valley is found.
 * - Pop the stack top as the 'bottom' of the valley.
 * - The new stack top becomes the left boundary, and arr[i] is the right boundary.
 * - Calculate water horizontally in layers:
 *     bounded_height = min(arr[i], arr[st.top()]) - bottom
 *     width = i - st.top() - 1
 *     water += bounded_height * width
 * 
 * Complexity:
 * - Time Complexity:  O(N) -> Each index is pushed and popped at most once.
 * - Space Complexity: O(N) -> Auxiliary space for the stack in worst case.
 * ============================================================================
 */
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int trapRainWater(int arr[],int n){
    stack<int>st;
    int water=0;
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[i]>arr[st.top()]){
            int bottom=arr[st.top()];
            st.pop();
            if(st.empty())
                break;
            int width=i-st.top()-1;
            int height=min(arr[i],arr[st.top()])-bottom;
            water+=height*width;
        }
        st.push(i);
    }
    return water;
}
int main(){
    int arr[]={1,2,4,2,3,5,7,4,9,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Traped water: "<<trapRainWater(arr,n)<<endl;
    return 0;
}
