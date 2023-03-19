#include<iostream>
#include<map>

using namespace std;

class Node{
    public:
        int data;
        Node* next=NULL;
        Node(int data){
            this->data=data;
        }
};


Node* remDup(Node* head){
    map<int,bool> data;
    Node* temp=head;
    if(head==NULL){
        return NULL;
    }
    data.insert({head->data,true});
    while(temp!=NULL && temp->next!=NULL){
        if(data.find(temp->next->data)==data.end()){
            data.insert({temp->next->data,true});
        }else{
            temp->next=temp->next->next;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    Node* head = new Node(12);
    Node* n2 = new Node(13);
    Node* n3 = new Node(12);
    Node* n4 = new Node(15);
    Node* n5 = new Node(16);
    Node* n6 = new Node(15);
    Node* n7 = new Node(15);
    n6->next=n7;
    n5->next=n6;
    n4->next=n5;
    n3->next=n4;
    n2->next=n3;
    head->next=n2;
    head = remDup(head);
    while(head->next!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}