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

void print( Node* tail ){
    Node* temp = tail;

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


    return 0;
}