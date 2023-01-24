#include<bits/stdc++.h>
using namespace std;

void printStack(vector<stack<int>> stks,vector<string> name,int& count){
    count++;
    vector<stack<int>> st = stks;
    int max=st[0].size();
    for(int i=0;i<st.size();i++){
        if(st[i].size()>max){
            max=st[i].size();
        }
    }
    cout<<endl<<count;
    for(int i=max;i>0;i--){
        cout<<endl;
        for(int j=0;j<st.size();j++){
            if(st[j].size()>=i){
                cout<<"|__"<<st[j].top()<<"__|  ";
                st[j].pop();
            }else{
                cout<<"|_____|  ";
            }
        }
    }
    cout<<endl;
    for(int i=0;i<name.size();i++){
        cout<<"  "<<name[i]<<"      ";
    }
}

void solveToH(vector<stack<int>> &stks,vector<string> name,int size,int from,int aux,int to,int &count){
    if(size==1){
        stks[to].push(stks[from].top());
        stks[from].pop();
        printStack(stks,name,count);
        return;
    }
    solveToH(stks,name,size-1,from,to,aux,count);
    stks[to].push(stks[from].top());
    stks[from].pop();
    printStack(stks,name,count);
    solveToH(stks,name,size-1,aux,from,to,count);
}

int main(){
    int size;
    cout<<"Enter number of disk in problem : ";cin>>size;
    vector<stack<int>> stks;
    vector<string> names;
    names.push_back("Frm");
    names.push_back("Aux");
    names.push_back("To");
    stack<int> st1,st2,st3;
    stks.push_back(st1);
    stks.push_back(st2);
    stks.push_back(st3);
    for(int i=1;i<=size;i++){
        stks[0].push(i);
    }
    int count=0;
    printStack(stks,names,count);
    solveToH(stks,names,size,0,1,2,count);
}