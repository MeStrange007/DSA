#include<iostream>
using namespace std;

template <class T> class Node {
    public:
    T data;
    Node* ptrdff = NULL^NULL;

    int pos;
    Node(){

    }
    Node(T data){
        this->data=data;
    }
};

template<class T> class DLinkedList{
    private:
    Node<T>* head; 
    int NumNodes = 0;
    
    public:
    DLinkedList(){
        head = new Node<T>();
        head->pos=0;
        // NumNodes++;
    }
    DLinkedList(T *data){
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
            Node<T>* prev = NULL;
            while( (temp->ptrdff)^prev !=NULL && temp->pos!=pos){
                Node<T>* temp2 = prev;
                prev=temp;
                temp=(temp->ptrdff)^temp2;
            }
            if((temp->ptrdff)^prev==NULL){
                temp->ptrdff= prev ^ (new Node<T>(data));
                (temp->ptrdff ^ prev)->ptrdff = (temp^NULL);
                (temp->ptrdff ^ prev)->pos = NumNodes;
            }else{
                Node<T>* temp2 = new Node<T>(data);
                temp2->pos=NumNodes;
                temp2->ptrdff=(temp)^(prev^(temp->ptrdff));
                (prev^(temp->ptrdff))->ptrdff=(temp^(prev^(temp->ptrdff)))^temp2;
                temp->ptrdff=prev^temp2;
            }
        }
    }

    void traverse(int pos=1){  
        Node<T>* temp=head;
        Node<T>* prev=NULL;
        while(temp->pos!=pos && (prev^(temp->ptrdff))!=NULL){
            Node<T>* temp2 = prev;
            prev=temp;
            temp=(temp->ptrdff)^temp2;
        }
        while(temp!=NULL){
            cout<<"["<<temp->pos<<"]={"<<temp->data<<" prev:";
            if(prev!=NULL){
                cout<<prev->pos;
            }else{
                cout<<"NULL";
            } 
            cout<<" nxt:";
            if((prev^(temp->ptrdff))!=NULL){
                cout<<(prev^(temp->ptrdff))->pos;
            }else{
                cout<<"NULL";
            } 
            cout<<"}\t";
            Node<T>* temp2 = prev;
            prev=temp;
            temp=(temp->ptrdff)^temp2;
        }
        cout<<endl;
    }

    Node<T>* deleteNode(int pos=0){
            Node<T>* temp = head;
            if(pos==1){
                head=temp->next;
                head->prev=NULL;
                return temp;
            }else{
                while(temp->next->next!=NULL && temp->next->pos!=pos){
                    temp=temp->next;
                }
                if(temp->next->next==NULL){
                    Node<T>* temp2 = temp->next;
                    temp->next=NULL;
                    return temp2;
                }else{
                    Node<T>* temp2 = temp->next;
                    temp->next->next->prev=temp;
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
    DLinkedList<int>* SLL1 = new DLinkedList<int>();
    for(int i=0;i<6;i++){
        SLL1->insertNode(i);
    }
    SLL1->traverse();
    // SLL1->deleteNode(5);
    // SLL1->traverse(4);
    // SLL1->deleteLinkedList();
    // for(int i=0;i<5;i++){
    //     SLL1->insertNode(i);
    // }
    // SLL1->traverse();
}