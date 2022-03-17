/*
https://leetcode.com/problems/middle-of-the-linked-list/
https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250/
https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1#
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
    public:
    int getMiddle(Node *head)
    {
        if( head == NULL || head -> next == NULL ) return head -> data;
            
        if( head -> next -> next == NULL ) return head -> next -> data;
        
        Node* fast = head -> next;
        Node* slow = head;
        
        while( fast != NULL ) {
            fast = fast -> next;
            if( fast != NULL ) fast = fast -> next;
            
            slow = slow -> next;
        }
        return slow -> data;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}