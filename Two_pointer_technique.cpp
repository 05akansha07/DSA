// Given a 1-indexed sorted array of integers numbers, find two numbers such that 
// they add up to a specific target number. Return their indices.Goal: Solve it in
// $O(N)$ time and $O(1)$ extra space using two pointers (left = 0, right = n - 1).
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,3,4,9,10,17,20,22,25};
    int target=18;
    int n= sizeof(arr)/sizeof(arr[0]);
    int left=0,right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            cout<<"Target found! 1-based Indices: [" << left + 1 << ", " << right + 1 << "]" 
                << " (Values: " << arr[left] << " + " << arr[right] << " = " << target << ")" << endl;
            right--;
            left++;
        }
        else if(sum>target){
            right--;
        }
        else{
            left++;
        }
    }
    return 0;
}