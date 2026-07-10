#include<stdio.h>
int main(){
int n;
printf("Enter the number of elements: ");
scanf("%d",&n);

printf("Enter the Elements of array: ");
int arr[n];
for (int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int smallest=arr[0];
for (int i=0;i<n;i++){
    if(arr[i]<smallest)
        smallest=arr[i];
    
}
printf("smallest number in array is %d",smallest);
}