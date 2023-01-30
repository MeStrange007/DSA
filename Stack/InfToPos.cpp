#include<iostream>
using namespace std;

// Postfix means operater will come after operands

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

string InfToPos(string exp){
    string output;
    StackNew<char> st(exp.length());
    for(int i=0;i<exp.length();i++){
        char ptr=exp[i];
        if(('a'<=ptr && ptr<='z') || ('A'<=ptr && ptr <= 'Z') || ('0'<=ptr && ptr<='9')){
            output+=ptr;
        }else{
            if(ptr=='('){
                st.push(ptr);
            }else if(ptr==')' && !st.is_empty()){
                while(st.Top()!='('){
                    output+=st.Top();
                    st.pop();
                }
                st.pop();
            }else if(st.is_empty()){
                st.push(ptr);
            } else if(precedance(ptr)>precedance(st.Top()) || ptr=='^'){
                st.push(ptr);
            }else {
                while(precedance(st.Top())>=precedance(ptr)){
                    output+=st.Top();
                    st.pop();
                }
                st.push(ptr);
            }
        }
    }
    while(!st.is_empty()){
        output+=st.Top();
        st.pop();
    }
    return output;
}

int main(){
    string exp;
    cout<<"Enter Infix Expression : ";cin>>exp;
    cout<<endl<<"Postfix of given Exp : "<<InfToPos(exp);
}