#include<iostream>
using namespace std;

int findFact(int num){
    if(num==1||num==0){
        return 1;
    }else{
        return num*findFact(num-1);
    }
}

int main(){
    int num;
    cout<<"Enter number to find factorial of : ";cin>>num;
    cout<<endl<<findFact(num);
}