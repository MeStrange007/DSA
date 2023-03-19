#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.size()==1){
        return nums[0];
    }
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        temp.push_back(temp[i-1]+nums[i]);
    }
    int maxIndex=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]>temp[maxIndex]){
            maxIndex=i;
        }
    }
    if(temp[maxIndex]<0){
        
    }
    int minIndex=0;
    for(int i=0;i<maxIndex;i++){
        if(temp[i]<temp[minIndex]){
            minIndex=i;
        }
    }
    if(temp[minIndex]<0){
        minIndex++;
    }
    int sum=0;
    for(int i=minIndex;i<=maxIndex;i++){
        sum+=nums[i];
    }
    return sum;
}

int main(){
    vector<int> temp ={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(temp);
}