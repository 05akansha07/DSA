#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"Enter number of rows:";
    cin>>row;
    cout<<"Enter number of column:";
    cin>>column;
    cout<<"Enter the elements: ";
    int arr[row][column];
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>arr[i][j];
        }
    }
    int trans[column][row];
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            trans[i][j]=arr[j][i];
        }
    }
    cout<<"Transpose matrix:"<<endl;
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
