#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left=NULL;
        Node* right=NULL;
        Node(int data){
            this->data=data;
        }
};

class BST{
    private:
        Node* root=NULL;
    public:
        BST(Node* root){
            this->root=root;
        }
        Node* insert(Node* newNode,Node* root){
            if(root->data>newNode->data){
                if(root->left==NULL){
                    root->left=newNode;
                    return root;
                }else {
                    root->left=insert(newNode,root->left);
                    return root;
                }
            }else{
                if(root->right==NULL){
                    root->right=newNode;
                    return root;
                }else {
                    root->right=insert(newNode,root->right);
                    return root;
                }
            }
        }
        void Traverse(Node* root,string direct){
            if(root){
                if(direct=="root"){
                    
                }
                Traverse(root->left,"left");
                // cout<<root->data<<"\t";
                Traverse(root->right,"right");
            }
        }
};

int main(){
    Node* root = new Node(50);
    BST* tree1 = new BST(root);
    tree1->insert(new Node(45),root);
    tree1->insert(new Node(48),root);
    tree1->insert(new Node(55),root);
    tree1->insert(new Node(62),root);
    tree1->insert(new Node(25),root);
    tree1->insert(new Node(53),root);
    tree1->insert(new Node(57),root);
    tree1->insert(new Node(47),root);
    tree1->insert(new Node(98),root);
    tree1->Traverse(root);
}