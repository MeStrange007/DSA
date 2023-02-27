// Given an array A of N elements representing the monsters and an array B of Q elements representing the heros
// The ith type of monster is represented by A[i][0]. A[i][1] and A[i][2] which means a monster of the I-th type is present at each integer co-ordinate from Alil[0] to A(1) and having a strength of A[i][2]
// The ith type of hero is represented by B[i][0] and B[i][1] which means a hero of strength B[i][1] will appear at the integer point 8[i][0] after seconds. When the i-th her appears it will destroy each and every monster present at B[i][0] and having a strength less than B[i][1]
// For each i you have to determine the number of monsters left after the i-th hero has completed their task.

#include<iostream>
using namespace std;

long* countMonster(int A[][3],int B[][2],int N,int Q){
    long* output = new long[Q+1];
    int board[unsigned long long(1e9)+1];
    for(int i=0;i<N;i++){
        output[0]+=(A[i][1]-A[i][0]+1);
    }
    for(int i=0;i<Q;i++){
        output[i+1]=output[i];
        for(int j=0;j<N;j++){
            if(A[j][0]<=B[i][0] && B[i][0]<=A[j][1]){
                if(board[B[i][0]]<B[i][1]){
                    if(board[B[i][0]]<A[j][2] && A[j][2]<=B[i][1]){
                        output[i+1]-=1;
                    }
                    board[B[i][0]]=B[i][1];
                }
            }
        }
    }
    return output+1;
}

int main(){

}