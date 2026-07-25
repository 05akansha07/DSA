//Longest Subarray with Equal Number of 0s and 1s
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,0,1,0,0,0,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low,sum=0,length,maxlength=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        if(arr[i]==0)arr[i]=-1;
        sum+=arr[i];
        if(sum==0){
            maxlength=max(maxlength,i+1);
        }
        if(mp.find(sum)!=mp.end()){
                length= i-mp[sum];
                maxlength=max(maxlength,length);
        }
        else{
            mp[sum]=i;
        }
    }
    cout<<maxlength;
}