#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

class Solution
{
    public:
    void insertAtTail(Node* &tail, Node* curr){
        tail -> next = curr;
        tail = curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        /*
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        Node* temp = head;
        while( temp != NULL ){
            if( temp -> data == 0 )
                zeroCount++;
            else if( temp -> data == 1 )
                oneCount++;
            else if( temp -> data == 2 )
                twoCount++;
            
            temp = temp -> next;
        }
        
        temp = head;
        while( temp != NULL ){
            if( zeroCount != 0 ){
                temp -> data = 0;
                zeroCount--;
            }
            else if( oneCount != 0 ){
                temp -> data = 1;
                oneCount--;
            }
            else if( twoCount != 0 ){
                temp -> data = 2;
                twoCount--;
            }
            temp = temp -> next;
        }
        
        return head;
        */
        
            // approach 2
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* current = head;
        
        // created seperate list of 0's , 1's & 2's
        while( current != NULL ){
            
            int val = current -> data;
            if( val == 0 ){
                insertAtTail(zeroTail, current);
            }
            else if( val == 1 ){
                insertAtTail(oneTail, current);
            }
            else if( val == 2 ){
                insertAtTail(twoTail, current);
            }
            current = current -> next;
        }
        
        // merge all sublists
        if( oneHead -> next != NULL ){
            zeroTail -> next = oneHead -> next;
        }
        else{ // 1's list is empty
            zeroTail -> next = twoHead -> next;
        }
        
        oneTail -> next = twoHead -> next;
        twoTail -> next = NULL;
        
        head = zeroHead -> next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};


// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}


void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}