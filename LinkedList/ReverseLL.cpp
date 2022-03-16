/*
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1#
https://leetcode.com/problems/reverse-linked-list/
https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897
*/
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    // method 2 recursion
    Node* reverseMethod2(Node* head){
        //base case
        if( head == NULL || head -> next == NULL ){
            return head;
        }

        Node* newHead = reverseMethod2(head -> next);

        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }
    
    //method 1 recursion
    void reverse(Node* &head , Node* current , Node* previous) {
    
        if( current == NULL ){
            head = previous;
            return;
        }

        reverse( head , current -> next , current );
        current -> next = previous;
    }
    
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        //recursion method 2
        return reverseMethod2( head );
        
        /*
        //recursion method 1
        Node* current = head;
        Node* previous = NULL;
        reverse( head , current , previous );
        return head;
        */
        
        
        /*
        if( head == NULL || head -> next == NULL ) return head;
        
        Node* previous = NULL;
        Node* current = head;
        Node* forward = NULL;
        
        while( current != NULL ) {
            
            forward = current -> next;
            current -> next = previous;
            
            previous = current;
            current = forward;
            
        }
        return previous;
        */
    }
    
};
    


// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}