// Without using Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int printFibonacci(int n){
    if(n==1||n==0){
        return n;
    }else{
        return printFibonacci(n-1)+printFibonacci(n-2);
    }
}

int main(){
    int size;
    cout<<"Enter Fibonacci Series length to be printed : ";cin>>size;
    int i=0;
    while(i<size){
        cout<<printFibonacci(i)<<" ";
        i++;
    }
}