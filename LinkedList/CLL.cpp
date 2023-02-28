#include<iostream>
using namespace std;

template <class T> class Node {
    public:
    T data;
    Node* next = NULL;
    // Node* prev = NULL;
    int pos;
    Node(){

    }
    Node(T data){
        this->data=data;
    }
};

template<class T> class CLinkedList{
    private:
    Node<T>* head; 
    int NumNodes = 0;
    
    public:
    CLinkedList(){
        head = new Node<T>();
        head->pos=0;
        // NumNodes++;
    }
    CLinkedList(T *data){
        NumNodes++;
        this->head = new Node<T>(data);
        this->head->pos=NumNodes;
        this->head->next=head;
    }

    void insertNode(T data,int pos=0){
        NumNodes++;
        if(head->pos==0){
            head->data=data;
            head->pos=NumNodes;
            head->next=head;
        }else{
            Node<T>* temp = head;
            while(temp->next!=head && temp->pos!=pos){
                temp=temp->next;
            }
            if(temp->next==head){
                temp->next=new Node<T>(data);
                temp->next->next=head;
                temp->next->pos=NumNodes;
            }else{
                Node<T>* temp2 = new Node<T>(data);
                temp2->pos=NumNodes;
                temp2->next=temp->next;
                temp->next=temp2;
            }
        }
    }

    void traverse(int pos=1){
        Node<T>* temp=head;
        while(temp->pos!=pos && temp->next!=head){
            temp=temp->next;
        }
        while(temp->next!=head){
            cout<<"["<<temp->pos<<"]={"<<temp->data;
            cout<<" nxt:";
            if(temp->next!=NULL){
                cout<<temp->next->pos;
            }
            cout<<"}\t";
            temp=temp->next;
        }
        cout<<"["<<temp->pos<<"]={"<<temp->data;
        cout<<" nxt:";
        if(temp->next!=NULL){
            cout<<temp->next->pos;
        }
        cout<<"}\t";
        cout<<endl;
    }

    Node<T>* deleteNode(int pos=0){
            Node<T>* temp = head;
            if(pos==1){
                head=temp->next;
                return temp;
            }else{
                while(temp->next->next!=head && temp->next->pos!=pos){
                    temp=temp->next;
                }
                if(temp->next->next==head){
                    Node<T>* temp2 = temp->next;
                    temp->next=head;
                    return temp2;
                }else{
                    Node<T>* temp2 = temp->next;
                    temp->next=temp->next->next;
                    return temp2;
                }               
            }
    }

    void updateNode(T data,int pos){
        Node<T>* temp=head;
        while(temp->pos!=pos){
            temp=temp->next;
        }
        temp->data=data;
    }

    void deleteLinkedList(){
        Node<T>* temp = head;
        while(temp){
            temp=head->next;
            free(head);
            head=temp;
        }
        head=new Node<T>();
        head->pos=0;
        NumNodes=0;
    }

};

int main(){
    CLinkedList<int>* SLL1 = new CLinkedList<int>();
    for(int i=0;i<6;i++){
        SLL1->insertNode(i);
    }
    SLL1->traverse();
    SLL1->deleteNode(5);
    SLL1->traverse(4);
    // SLL1->deleteLinkedList();
    // for(int i=0;i<5;i++){
    //     SLL1->insertNode(i);
    // }
    // SLL1->traverse();
}