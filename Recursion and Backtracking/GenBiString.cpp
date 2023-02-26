#include<iostream>
using namespace std;

void generateString(string str,int n){
    if(n<1){
        cout<<str<<endl;
        return;
    }
    if(str[n-1]=='?'){
        str[n-1]='0';
        generateString(str,n-1);
        str[n-1]='1';
        generateString(str,n-1);
    }
    else{
        generateString(str,n-1); 
    }
}

int main(){
    string str = "1?00?101";
    generateString(str,str.length());
}