/*
Question:
Given an array of integers, find the Next Greater Element (NGE)
for each element. The Next Greater Element of an element is the
first element to its right that is greater than it.

If no greater element exists, print -1.

Example:
Input:  [2, 4, 2, 3, 6]
Output: 4 6 3 6 -1

Approach:
Traverse the array from right to left and use a stack to find
the Next Greater Element efficiently.

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={2,4,2,3,6,8,6,4,8,9,9};
    stack<int>st;
    int ans;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans = -1;
        }
        else{
            ans = st.top();
        }
        cout<<arr[i]<<" -> "<<ans<<endl;
        st.push(arr[i]);
    }
    return 0;
}