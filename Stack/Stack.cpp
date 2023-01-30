#include<iostream>
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

int main(){

}