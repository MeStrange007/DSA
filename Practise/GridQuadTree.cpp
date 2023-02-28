#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node* gridRecur(int x,int y,int size,vector<vector<int>>& grid){
    if(size==1){
        return new Node(grid[y][x],true);
    }
    Node* topLeft = gridRecur(x,y,size/2,grid);
    Node* topRight = gridRecur(x+(size/2),y,size/2,grid);
    Node* bottomLeft = gridRecur(x,y+(size/2),size/2,grid);
    Node* bottomRight = gridRecur(x+(size/2),y+(size/2),size/2,grid);
    if(topLeft->isLeaf&&topRight->isLeaf&&bottomLeft->isLeaf&&bottomRight->isLeaf){
        if((topLeft->val==topRight->val)&&(bottomLeft->val==bottomRight->val)&&(topLeft->val==bottomLeft->val)){
            cout<<"\nx:"<<x<<" y:"<<y<<" size:"<<size<<" val:"<<topLeft->val<<" isLeaf:true";
            return new Node(topLeft->val,true);
        }else{
            cout<<"\nx:"<<x<<" y:"<<y<<" size:"<<size<<" val:"<<topLeft->val<<" isLeaf:false";
            return new Node(topLeft->val,false,topLeft,topRight,bottomLeft,bottomRight);
        }
    }else{
        cout<<"\nx:"<<x<<" y:"<<y<<" size:"<<size<<" val:"<<topLeft->val<<" isLeaf:false";
        return new Node(topLeft->val,false,topLeft,topRight,bottomLeft,bottomRight);
    }
}

int main(){
    vector<vector<int>> grid={{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    Node* sol1 = gridRecur(0,0,grid.size(),grid);
}