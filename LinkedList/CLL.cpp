#include<iostream>
#include<map>
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
            cout << "Loop Present at element " << fast -> data << endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNodeInLoop(Node* head){
    if( head == NULL ) return NULL;

    Node* intersection = floydDetectLoop(head);

    Node* slow = head;
    Node* fast = intersection;

    while( slow != fast ){
        slow = slow -> next;
        fast = fast -> next;
    }
    
    return slow;
}

void removeLoop( Node* head ){

    if( head == NULL ) return;

    Node* startingNode = getStartingNodeInLoop(head);
    Node* temp = startingNode;

    while( temp -> next != startingNode ){
        temp = temp -> next;
    }

    temp -> next = NULL;
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

    if( floydDetectLoop(tail) != NULL ){
        cout << "Has Loop" << endl;
    }else{
        cout << "No Loop Present" << endl;
    }


    if( getStartingNodeInLoop(tail) != NULL ){
        Node* startingNode = getStartingNodeInLoop(tail);
        cout << " Loop Starting Node =  " << startingNode -> data << endl;
    }
    
    removeLoop(tail);

    return 0;
}