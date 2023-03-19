#include<iostream>
using namespace std;

const int mat[3][3] = {{0,1,0},{0,0,0},{1,1,0}}; 

bool ask(int a,int b){
    if(mat[a][b]!=0){
        return true;
    }else{
        return false;
    }
}

void findCeleb(int n){
    for(int i=0;i<n;i++){
        bool NotBreak = true;
        for(int j=0;j<n;j++){
            if(ask(i,j)){
                NotBreak=false;
                break;
            }
        }
        if(NotBreak){
            cout<<i;
            return;
        }
    }
    cout<<-1;
}

int main(){

}