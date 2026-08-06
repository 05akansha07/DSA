#include<iostream>
using namespace std;
int main(){
    int arr[]={1,  7,  3,  6,  5,  6};
    int totalsum=0;
    bool flag=false;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }
    int leftsum=0;
    for(int i=0;i<n;i++){
        int rightsum= totalsum-leftsum-arr[i];
        if(rightsum==leftsum){
            cout << "Equilibrium Index is: " << i << endl;
            flag=true;
            //break;if you want to stops searching once the first equilibrium index is found
        }
        leftsum+=arr[i];
    }
    if(!flag)
        cout << "No Equilibrium Index found." << endl;
    return 0;
}