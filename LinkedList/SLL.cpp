#include<iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void insertAtHead( Node* &head , int data ) {

    //create new node
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

}

void insertAtTail( Node* &tail , int data ) {

    //create new node
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;

}

void insertAtPosition( Node* &head , Node* &tail , int position , int data ){

    //Case 1 -> inserting at start position
    if( position == 1 ) {
        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    //Case 2 -> inserting at last position
    if( temp -> next == NULL ) {
        insertAtTail(tail,data);
        return;
    }

    //creating node to insert
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void print(Node* &head){
    Node* temp = head;
    cout << endl;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl << endl;
}

int main() {

    //create new node
    Node* node1 = new Node(10);
    // cout<< node1 -> data << endl;
    // cout<< node1 -> next << endl;

    //head and tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head,1);

    insertAtTail(tail,20);

    insertAtPosition(head,tail,3,15);

    //try to insert at start
    insertAtPosition(head,tail,1,0);

    //try to insert at last
    insertAtPosition(head,tail,6,100);

    print(head);

    //verify head and tail
    cout << "Head -> " << head -> data << endl;
    cout << "Tail -> " << tail -> data << endl << endl;

    return 0;
}