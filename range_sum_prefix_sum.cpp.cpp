// Problem: Range Sum Query using Prefix Sum Array
// Time Complexity: O(N) preprocessing, O(1) per query
// Space Complexity: O(N)
#include<iostream>
using namespace std;
int main(){
    int arr[]={2,4,2,6,7,2,7,9,9,5,4,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    int prefix[n];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }

    int l=2,r=7;
    int rangeSum =(l==0)?prefix[r]:prefix[r]-prefix[l-1];

    cout << "Sum from index " << l << " to " << r << " is: " << rangeSum << endl;
    
    return 0;
}