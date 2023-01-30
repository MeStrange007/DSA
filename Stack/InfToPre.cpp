#include<iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T> class StackNew{
    private:
        T* arr;
        int size;
        int top=-1;
    public:
        StackNew(int size){
            size=size;
            arr=new T[size];
        }
        bool is_empty(){
            if(top==-1){
                return true;
            }
            return false;
        }
        bool is_full(){
            if(top==size-1){
                return true;
            }
            return false;
        }
        T Top(){
            if(!is_empty()) return arr[top];
            // else cout<<endl<<"Stack is Empty"<<endl;
        }
        void push(T num){
            if(!is_full()){
                arr[++top]=num;
            }else cout<<endl<<"Stack overflow "<<num<<endl;
        }
        void pop(){
            if(!is_empty()) top--;
            else cout<<endl<<"Stack underfloe"<<endl;
        }
};

int precedance(char ptr){
    if(ptr=='+'||ptr=='-'){
        return 1;
    }else if(ptr=='*'|| ptr=='/'){
        return 2;
    }
    else if(ptr=='^'){
        return 3;
    }else return -1;
}

string InfToPre(string exp){
    StackNew<char> st(exp.length());
    string output;
    for(int i=exp.length()-1;i>=0;i--){
        char ptr = exp[i];
        if((ptr>='a' && ptr<='z')||(ptr>='A' && ptr<='Z')||(ptr>='0' && ptr<='9')){
            output+=ptr;
        }else if(ptr==')'){
            st.push(ptr);
        }else if(ptr=='('){
            while(st.Top()!=')'){
                output+=st.Top();
                st.pop();
            }
            st.pop();
        }else if(st.is_empty()){
            // cout<<ptr;
            st.push(ptr);
        }else if(precedance(ptr)>precedance(st.Top()) || (precedance(ptr)==precedance(st.Top()) && ptr!='^') ){
            // cout<<ptr;
            st.push(ptr);
        }else{
            while(precedance(st.Top())>precedance(ptr) && (!st.is_empty())){
                // cout<<endl<<"Top = "<<st.Top()<<"Char = "<<ptr;
                output+=st.Top();
                st.pop();
            }
            
            st.push(ptr);
        }
    }
    while(!st.is_empty()){
        output+=st.Top();
        st.pop();
    }
    
    reverse(output.begin(),output.end());
    return output;
}

int main(){
    string exp;
    cout<<"Enter Infix expression : ";cin>>exp;
    cout<<endl<<"Prefix Expression for the given expression : "<<InfToPre(exp);
}