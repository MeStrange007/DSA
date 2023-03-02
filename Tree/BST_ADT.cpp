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
        BST(){

        }
        BST(Node* root){
            this->root=root;
        }
        Node* insertUtil(Node* newNode,Node* root){
            if(root->data>newNode->data){
                if(root->left==NULL){
                    root->left=newNode;
                    return root;
                }else {
                    root->left=insertUtil(newNode,root->left);
                    return root;
                }
            }else{
                if(root->right==NULL){
                    root->right=newNode;
                    return root;
                }else {
                    root->right=insertUtil(newNode,root->right);
                    return root;
                }
            }
        }

        Node* insert(Node* newNode){
            if(root==NULL){
                root=newNode;
                return newNode;
            }
            return insertUtil(newNode,root);
        }

        // void printTree(Node* root,string direct){
        //     if(root){
        //         if(direct=="root"){
                    
        //         }
        //         printTree(root->left,"left");
        //         // cout<<root->data<<"\t";
        //         printTree(root->right,"right");
        //     }
        // }

        void inOrderTravers(Node* root){
            if(root!=NULL){
                inOrderTravers(root->left);
                cout<<"\t"<<root->data;
                inOrderTravers(root->right);
            }
        }
};

int main(){
    Node* root = new Node(50);
    BST* tree1 = new BST(root);
    tree1->insert(new Node(45));
    tree1->insert(new Node(48));
    tree1->insert(new Node(55));
    tree1->insert(new Node(62));
    tree1->insert(new Node(25));
    tree1->insert(new Node(53));
    tree1->insert(new Node(57));
    tree1->insert(new Node(47));
    tree1->insert(new Node(98));
    cout<<endl;
    tree1->inOrderTravers(root);
}