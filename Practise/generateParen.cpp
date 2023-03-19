#include<iostream>
#include<vector>

using namespace std;

void recur(int n,int m,vector<string> &out,string s){
    if(n==0 && m==0){
        out.push_back(s);
        return;
    }
    if(n>0){
        string temp=s;
        temp+="(";
        recur(n-1,m+1,out,temp);
    }
    if(m>0){
        string temp = s;
        temp+=")";
        recur(n,m-1,out,temp);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> temp;
    recur(n,0,temp,"");
    return temp;
}

int main(){
    generateParenthesis(3);
}