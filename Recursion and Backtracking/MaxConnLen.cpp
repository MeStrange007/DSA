#include<iostream>
using namespace std;

bool ifInvalid(int r, int c,int L, int H){
    if(r<0||r>=L||c<0||c>=H){
        return true;
    }
    return false;
}

void getMaxSize(int **arr,int r,int c,int L,int H,bool **cnt,int size,int &maxsize){
    if(ifInvalid(r,c,L,H)){
        return;
    }
    if(arr[r][c]==1){
        size++;
        cnt[r][c]=true;
        if(size>maxsize){
            maxsize=size;
        }
        int direction[][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
        for(int i=0;i<8;i++){
            if(!ifInvalid(r+direction[i][0],c+direction[i][1],L,H)){
                if(arr[r+direction[i][0]][c+direction[i][1]]==1 && !cnt[r+direction[i][0]][c+direction[i][1]]){
                    cout<<"size = "<<size<<" r = "<<r+direction[i][0]<<" c = "<<c+direction[i][1]<<endl;
                    getMaxSize(arr,r+direction[i][0],c+direction[i][1],L,H,cnt,size,maxsize);
                }
            }
        }
        cnt[r][c]=false;
    }
}
int countMaxIland(int **arr,int L,int H){

    bool **cnt = new bool*[H];
    for(int i =0;i<H;i++){
        cnt[i]=new bool[L];
    }
    for(int i=0;i<L;i++){
        for(int j=0;j<H;j++){
            cnt[i][j]=false;
        }
    }
    int size=0,maxsize=0;
    for(int i=0;i<L;i++){
        for(int j=0;j<H;j++){
            getMaxSize(arr,i,j,L,H,cnt,size,maxsize);
        }
    }
    return maxsize;
}


int main(){
    int L,H;
    cout<<"Enter Length : ";cin>>L;cout<<endl<<"Enter Height : ";cin>>H;cout<<endl;
    int **arr=new int*[H];
    for(int i = 0;i<5;i++){
        arr[i]=new int[L];
    }
    
    for(int i=0;i<L;i++){
        // cout<<"enter "<<i<<"row : ";
        for(int j=0;j<H;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    // 1 1 0 0 0 0 1 1 0 0 0 0 1 0 1 1 0 0 0 1 0 1 0 1 1
    // int arr[5][5]={{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1}};
    cout<<countMaxIland(arr,L,H);
}