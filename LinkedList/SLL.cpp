#include<iostream>
using namespace std;

template <class T> class Node {
    public:
    T data;
    Node* next = NULL;
    int pos;
    Node(){

    }
    Node(T data){
        this->data=data;
    }
};

template<class T> class SLinkedList{
    private:
    Node<T>* head; 
    int NumNodes = 0;
    
    public:
    SLinkedList(){
        head = new Node<T>();
        head->pos=0;
        // NumNodes++;
    }
    SLinkedList(T *data){
        NumNodes++;
        this->head = new Node<T>(data);
        this->head->pos=NumNodes;
    }

    void insertNode(T data,int pos=0){
        NumNodes++;
        if(head->pos==0){
            head->data=data;
            head->pos=NumNodes;
        }else{
            Node<T>* temp = head;
            while(temp->next!=NULL && temp->pos!=pos){
                temp=temp->next;
            }
            Node<T>* temp2 = temp->next;
            temp->next=new Node<T>(data);
            temp->next->next=temp2;
            temp->next->pos=NumNodes;
        }
    }

    void traverse(int pos=1){
        Node<T>* temp=head;
        while(temp->pos!=pos && temp->next!=NULL){
            temp=temp->next;
        }
        while(temp!=NULL){
            cout<<"["<<temp->pos<<"]="<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<endl;
    }

    Node<T>* deleteNode(int pos=0){
            Node<T>* temp = head;
            if(pos==1){
                head=temp->next;
                return temp;
            }else{
                while(temp->next->next!=NULL && temp->next->pos!=pos){
                    temp=temp->next;
                }
                Node<T>* temp2 = temp->next;
                temp->next=temp->next->next;
                return temp2;
            }
    }

    void updateNode(T data,int pos){
        Node<T>* temp=head;
        while(temp->pos!=pos){
            temp=temp->next;
        }
        temp->data=data;
    }

};

int main(){
    SLinkedList<int>* SLL1 = new SLinkedList<int>();
    for(int i=0;i<10;i++){
        SLL1->insertNode(i);
    }
    SLL1->traverse();
    SLL1->deleteNode(5);
    SLL1->traverse(4);
    for(int i=0;i<5;i++){
        SLL1->insertNode(i);
    }
    SLL1->traverse();
}