//Write a Java program to compute the Sum of Diagonal Elements (Main Diagonal) in a square matrix 
//without using extra space.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int sum =0 ,antiSum=0;
    for(int i=0;i<3;i++){
        sum+=arr[i][i];
        antiSum+=arr[i][3-1-i];
    }
    cout<<"Main Diagonal Sum: "<<sum<<endl;
    cout<<"Anti-Diagonal / Secondary Diagonal Sum: "<<antiSum<<endl;
}