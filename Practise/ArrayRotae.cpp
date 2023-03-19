#include<iostream>
using namespace std;

void rotate(int arr[],int n){
    for(int i=0;i<n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}

// void rotate(vector<int>& nums, int k) {
//         if(k<nums.size()/2){
//             for(int i=nums.size()-k;i<nums.size();i++){
//                 int temp = nums[i];
//                 nums[i]=nums[i-1];
//                 nums[i-1]=nums[i-(nums.size()-k)];
//                 nums[i-(nums.size()-k)]=temp;
//             }
//         }else if(k==nums.size()/2){
//             for(int i=0;i<k;i++){
//                 int temp = nums[i];
//                 nums[i]=nums[i+k];
//                 nums[i+k]=temp;
//             }
//         }else{
//             for(int i=0;i<k;i++){
                
//             }
//         }
//     }

int main(){
    int temp[6]={1,2,3,4,5,6};
    rotate(
        temp,6
    );
    for(int i=0;i<6;i++){
        cout<<temp[i]<<"\t";
    }
}