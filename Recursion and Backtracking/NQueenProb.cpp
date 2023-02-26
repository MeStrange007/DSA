#include<iostream>
#include<vector>
#define N 4
using namespace std;


void calSafe(int size,int curr[N][N]){

}

void safePos(int currSafe[N][N],int Q_i,int Q_j,int size){
    for(int i=0;i<N;i++){
        currSafe[Q_i][i]=-1;
        currSafe[i][Q_j]=-1;
    }
}

vector<pair<int,int>> backtrack(){

}

int main(){

}