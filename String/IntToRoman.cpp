#include<iostream>
using namespace std;

const int number[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
const string val[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

string intToRoman(int num) {
    if(num<=0){
        return "";
    }
    for(int i=0;i<13;i++){
        if(num>=number[i]){
            return val[i]+intToRoman(num-number[i]);
        }
    }
}

int main(){
    cout<<intToRoman(58);
}