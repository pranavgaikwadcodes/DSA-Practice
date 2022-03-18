#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* previous;
        Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> previous = NULL;
        this -> next = NULL;
    }

    // destructor
    ~Node() {
        int value = this -> data;

        // memory free
        if( this -> next != NULL ){
            delete next;
            this -> next = NULL;
        }

        cout << "Memory is free for node with data : " << value << endl;
    }
};

void insertAtHead( Node* &head , Node* &tail , int data ) {

    if( head == NULL ) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> previous = temp;
        head = temp;
    }
    
}

void insertAtTail( Node* &head , Node* &tail , int data ){
    
    if( tail == NULL ) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> previous = tail;
        tail = temp;
    }

}


void insertAtPosition( Node* &head , Node* &tail , int position , int data ){

    // Case 1 -> inserting at start position
    if( position == 1 ) {
        insertAtHead( head , tail , data );
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    // Case 2 -> inserting at last position
    if( temp -> next == NULL ) {
        insertAtTail( head , tail , data );
        return;
    }

    // creating node to insert
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> previous = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> previous = temp;

}


// Deletion of nodes in Singly Linked List

void deleteNodeByPosition( Node* &head , Node* &tail , int position ) {

    if( position == 1 ){ // deleting starting node
        Node* temp = head;

        temp -> next -> previous = NULL;
        head = temp -> next;
        
        // memory free
        temp -> next = NULL;
        delete temp;
    }
    else { // deleting any middle or last node
        Node* current = head;
        Node* previous = NULL;

        int count = 1;

        while( count < position ) {
            previous = current;
            current = current -> next;
            count++;
        }

        // update tail if deleting last node
        if( current -> next == NULL ) tail = previous;

        current -> previous = NULL;
        previous -> next = current -> next;

        // memory free
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

// traversing
void print( Node* &head ){
    Node* temp = head;

    cout << endl << "NULL";
    
    while ( temp != NULL ) {
        cout << " <- " << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL" << endl;
    
}

// gives length of linked list
int getLength( Node* &head ) {

    int length = 0;

    Node* temp = head;

    while ( temp != NULL ){
        length++;
        temp = temp -> next;
    }

    return length;
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtHead( head , tail , 9 );
    insertAtHead( head , tail , 8 );
    insertAtTail( head , tail , 11 );
    insertAtPosition( head , tail , 2 , 100 );
    insertAtPosition( head , tail , 1 , 101 );
    insertAtPosition( head , tail , 7 , 102 );

    print(head);
    cout << "Head position at data : " << head -> data << endl;
    cout << "Tail position at data : " << tail -> data << endl;
    cout << "Length of LinkedList : " << getLength(head) << endl;


    //deletion
    cout << endl;
    deleteNodeByPosition(head,tail,7);
    deleteNodeByPosition(head,tail,1);
    deleteNodeByPosition(head,tail,4);

    print(head);

    cout << "Head position at data : " << head -> data << endl;
    cout << "Tail position at data : " << tail -> data << endl;
    cout << "Length of LinkedList : " << getLength(head) << endl;

    if( isCircular(tail) ) {
        cout << "This Linked List is Circular. " << endl;
    }else{
        cout << "This Linked List is Not-Circular. " << endl;
    }
    
    return 0;
}