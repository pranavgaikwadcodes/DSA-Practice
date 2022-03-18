#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node( int data ){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data : " << value << endl;
    }
};

void insertNode( Node* &tail , int position , int data ) {

    // Linked List is empty
    if( tail == NULL ){
        Node* temp = new Node(data);
        tail = temp;
        temp -> next = temp;
    }
    else { // List is not empty
        Node* current = tail;

        while(current-> data != position){
            current = current -> next;
        }

        Node* temp = new Node(data);
        temp -> next = current -> next;
        current -> next = temp;

    }

}

void deleteNode( Node* &tail , int data ) {

    // if list is empty
    if( tail == NULL ){
        cout << " This List Is Empty, Please Check Again. " << endl;
        return;
    }
    else {
        Node* previous = tail;
        Node* current = previous -> next;

        while( current -> data != data ){
            previous = current;
            current = current -> next;
        }

        previous -> next =  current -> next;

        // only one node in Linked List
        if( current == previous )   tail = NULL;

        // Linked List >= 2 Nodes
        if( tail == current )   tail = previous;

        current -> next = NULL;
        delete current;

    }
}

bool isCircular(Node* head){

    if( head == NULL || head -> next == NULL ) return false;
    
    if( head -> next == head ) return true;
    
    Node* temp = head -> next;
    
    while( temp != NULL && temp != head ){
        temp = temp -> next;
    }
    
    if( temp == head ) return true;

    return false;
}

void print( Node* tail ){
    Node* temp = tail;

    if(tail == NULL){
        cout << " LIST IS EMPTY! " << endl;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    }
    while( tail != temp );
    
    cout << endl;
}

int main() {

    Node* tail = NULL;

    insertNode(tail,1,3);    
    insertNode(tail,3,5);
    insertNode(tail,3,4);
    insertNode(tail,5,6);

    print(tail);

    deleteNode(tail,3);
    print(tail);

    if( isCircular(tail) ) {
        cout << "This Linked List is Circular. " << endl;
    }else{
        cout << "This Linked List is Not-Circular. " << endl;
    }

    return 0;
}