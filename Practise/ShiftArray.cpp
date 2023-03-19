#include<iostream>
using namespace std;

void shiftArray(int arr[],int size,int rot){
    for(int i=rot;i<size;i++){
        int temp=arr[i-rot];
        arr[i-rot]=arr[i];
        arr[i]=arr[i-rot+1];
        arr[i-rot+1]=temp;
    }
}

int main(){
    int n=9;
    // int *temp = new int[n];
    int temp[9]={1,2,3,4,5,6,7,8,9};
    shiftArray(temp,n,4);
    for(int i=0;i<n;i++){
        cout<<temp[i]<<"\t";
    }
}