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

    return 0;
}