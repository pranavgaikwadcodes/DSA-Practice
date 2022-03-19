#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
        int data;
        Node* next;

    // constructor
    Node(int data){
        this -> data = data;
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

// Insertion of Nodes in Singly Linked List

void insertAtHead( Node* &head , Node* &tail , int data ) {
    if( head == NULL ) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        // create new node
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }

}

void insertAtTail( Node* &head , Node* &tail , int data ) {
    if( tail == NULL ) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        // create new node
        Node* temp = new Node(data);
        tail -> next = temp;
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
    temp -> next = nodeToInsert;

}

// Deletion of nodes in Singly Linked List

void deleteNodeByPosition( Node* &head , Node* &tail , int position ) {

    if( position == 1 ){ // deleting starting node
        Node* temp = head;
        head = head -> next;
        
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

        previous -> next = current -> next;

        // memory free
        current -> next = NULL;
        delete current;
    }

}

void deleteNodeByData( Node* &head , Node* &tail , int dataToDelete ) {

    Node* current = head;
    Node* previous = NULL;

    while( current != NULL ){

        if(current -> data == dataToDelete) break;

        previous = current;
        current = current -> next;
    }

    if( previous == NULL ){
        Node* temp = head;
        head = head -> next;
        
        // memory free
        temp -> next = NULL;
        delete temp;
    }
    else{
        // update tail if deleting last node
        if( current -> next == NULL ) tail = previous;

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

// Approach 1 Detect cycle
bool detectLoop(Node* head){

    if( head == NULL ) return false;

    map<Node*,bool> visited;
    Node* temp = head;

    while( temp != NULL ){

        if( visited[temp] == true ) return true;

        visited[temp] = true;
        temp = temp ->  next;
    }
    return false;
}

// Approach 2 Floyd Cycle Detection
Node* floydDetectLoop(Node* head){
    if( head == NULL ) return NULL;

    Node* slow = head;
    Node* fast = head;

    while( fast != NULL && slow != NULL ) {
        fast = fast -> next;
        if( fast != NULL ) fast = fast -> next;

        slow = slow -> next;

        if( slow == fast ){
            cout << " Present at element " << fast -> data << endl;
            return slow;
        }
    }
    return NULL;
}

void print(Node* &head){

    if( head == NULL ) {
        cout << " List is Empty! " << endl;
        return;
    }
    
    Node* temp = head;
    cout << endl;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl << endl;
}

int main() {

    // create new node (In Heap)
    Node* node1 = new Node(10);
    // cout<< node1 -> data << endl;
    // cout<< node1 -> next << endl;

    // head and tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

    insertAtHead( head , tail , 1 );

    insertAtTail( head , tail , 20 );

    insertAtPosition( head , tail , 3 , 15 );

    // try to insert at start
    insertAtPosition( head , tail , 1 , 0 );

    // try to insert at last
    insertAtPosition( head , tail , 6 , 100 );

    print(head);

    deleteNodeByData( head , tail , 100 );

    print(head);

    // verify head and tail
    cout << "Head -> " << head -> data << endl;
    cout << "Tail -> " << tail -> data << endl << endl;

    if( isCircular(head) ) {
        cout << "This Linked List is Circular. " << endl;
    }else{
        cout << "This Linked List is Not-Circular. " << endl;
    }

    if( floydDetectLoop(head) != NULL ){
        cout << "Has Loop" << endl;
    }else{
        cout << "No Loop Present" << endl;
    }

    return 0;
}