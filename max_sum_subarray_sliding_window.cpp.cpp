//Write a complete C++ program to find the maximum sum of a contiguous 
//subarray of size k = 3 in an array arr = {2, 1, 5, 1, 3, 2}
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={1,3,2,6,4,8,4,9,0,3,2,5,8,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    if(n<k){
        cout<<"Invalid size";
        return 0;
    }
    int WindowSum=0;
    for(int i=0;i<k;i++){
        WindowSum+=arr[i];
    }
    int MaxSum=WindowSum;
    for(int i=k;i<n;i++){
        WindowSum+= arr[i]-arr[i-k];
        MaxSum=max(WindowSum,MaxSum);
    }
    cout << "Maximum sum of subarray of size " << k << " is: " << MaxSum << endl;
    return 0;
} 