#include<iostream>
using namespace std;

int* maxSub(int* arr,int n,int k){

    int* output = new int[n-k+1];
    int max=INT_MIN,ind=0;
    int secMax=INT_MIN,secInd=0;
    for(int i=0;i<k;i++){
        if(arr[i]>=max){
            max=arr[i];
            ind=i;
        }
    }
    output[0]=max;
    for(int i=k;i<n;i++){
        if(arr[i]>max){
            if(ind==i-)
        }
    }

}

int main(){

}