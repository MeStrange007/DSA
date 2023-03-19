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
    StackNew<int>* st1 = new StackNew<int>(3);
    int number = 365;
    int i=1;
    while(number/i!=0){
        i*=10;
    }
    i/=10;
    int j = i;
    while(i!=0){
        // cout<<((number/i)%10);
        st1->push((number/i)%10);
        // number/=10;
        i/=10;
    }
    int output = 0;
    while(!st1->is_empty()){
        output+=(j*st1->Top());
        st1->pop();
        j/=10;
    }
    cout<<output;
}