#include<iostream>
#include<vector>

using namespace std;

const char digitsMap[8] = {'2','3','4','5','6','7','8','9'};
const string map[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

void recur(string digit,string out,vector<string>& temp){
    if(digit==""){
        temp.push_back(out);
        return;
    }
    for(int j=0;j<8;j++){
        if(digit[0]==digitsMap[j]){
            for(int i=0;i<map[j].size();i++){
                recur(digit.substr(1,digit.size()-1),out+map[j][i],temp);
            }
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> out;
    if (digits=="") return out; 
    recur(digits,"",out);
    return out;
}

int main(){
    vector<string> temp = letterCombinations("23");
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<"\t";
    }
}