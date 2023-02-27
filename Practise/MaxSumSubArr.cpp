// You are given an array A of N integers. You will have to pick 3 subarrays from the array la, l, and ly. The subarray l, must be a prefix and l, must be a suffux. The minimum length of each of these subarrays must be 1. An element of the array cannot be present in more than 1 of these subarrays.
// Find the maximum sum of all the elements in each of these three subarrays. Since the sum can be large, return the positive remainder after dividing the sum with 10+7.

#include<iostream>
using namespace std;

long sum(int i,int j,int* arr){
    long sum=0;
    for(int k=i;k<=j;k++){
        sum = (sum+arr[k])%long(1e10+7);
    }
    return sum;
}

long MaxSumSubArr(int i,int j,int *arr,int n){
    if(i<0 || j>=n){return INT_MIN;}
    return(max(max(sum(0,i,arr),sum(i+1,j-1,arr),sum(j,n-1,arr)),MaxSumSubArr(i-1,j,arr,n),MaxSumSubArr(i,j+1,arr,n)));
}

int main(){

}