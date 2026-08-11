//Write a program in C to remove duplicate elements from a sorted integer array in-place 
//using the two-pointer technique and print the resulting unique elements.
#include<stdio.h>
int main(){
    int arr[]={4,4,4,6,6,8,9,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    for( int j=i+1;j<n;j++){
            if(arr[j]!=arr[i]){
                i++;
                arr[i]=arr[j];
                // count++;
            }
    }
    for(int k=0;k<=i;k++){
        printf("%d ",arr[k]);
    }
}

