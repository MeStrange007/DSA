#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){

    vector<vector<int>> output; 

    int minnumsVal=INT32_MAX,maxnumsVal=INT32_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>maxnumsVal){
            maxnumsVal=nums[i];
        }
        if(nums[i]<minnumsVal){
            minnumsVal=nums[i];
        }
    }
    minnumsVal = -1*(minnumsVal);
    int* hash = new int[minnumsVal+maxnumsVal]{-1};
    for(int i=0;i<nums.size();i++){
        if(hash[nums[i]+minnumsVal]!=-1){
            continue;
        }
        hash[nums[i]+minnumsVal] = i;
    }
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(hash[-(nums[i]+nums[j])+minnumsVal]!=-1){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[hash[-(nums[i]+nums[j])+minnumsVal]]);
                output.push_back(temp);
            }
        }
    }
    return output;
}

int main(){

}