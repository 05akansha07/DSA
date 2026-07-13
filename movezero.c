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
    int i=-1;
    for(int j=i+1;j<n;j++){
        if(arr[j]!=0){
            i++;
            if(i!=j){
                arr[i]=arr[j];
                arr[j]=0;
            }
        }
    }
    for (int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}