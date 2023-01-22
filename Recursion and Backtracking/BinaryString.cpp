#include<bits/stdc++.h>
using namespace std;

void printArr(int size,int* arr){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
}

void printBinaryString(int n,int* arr){
    if(n<1){
        printArr(n,arr);
    }else{
        arr[n-1]=0;
        printBinaryString(n-1,arr);
        arr[n-1]=1;
        printBinaryString(n-1,arr);
    }
}

int main(){

    int size;
    cout<<"Enter length of binary string : ";cin>>size;
    cout<<endl;
    int *arr = new int[size];
    printBinaryString(size,arr);
}