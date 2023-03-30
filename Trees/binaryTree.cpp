#include<iostream>
#include<queue>
using namespace std;


class node{
    public:
        int data;
        node* right;
        node* left;

    node(int d){
        this->data = d;
        this->left = NULL;
        this -> right = NULL;
    }

};

node* buildTree(node* root){
    cout << "enter the data " << endl;
    int data;
    cin >> data;

    root = new node(data); 

    if (data == -1) return NULL;

    cout << "enter data for insertin in left of " <<  data << endl;
    root -> left = buildTree(root -> left);
    cout << "enter data for insertin in right of " <<  data << endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
            q.push(temp->left);
            }
            if(temp -> right ){
                q.push(temp->right );
            }
        }
    }
     
}


/*
    L -> Left   |   R -> Right  |   N -> Node Print

    preorder = NLR
    inorder = LNR
    postorder = LRN

*/

void preorder(node* root){
    // base case
    if(root == NULL) return ;

    cout << root -> data << " " ;
    preorder(root->left);
    preorder(root ->right);
}

void inorder(node* root){
    // base case
    if(root == NULL) return ;

    inorder(root->left);
    cout << root -> data << " " ;
    inorder(root ->right);
}

void postorder(node* root){
    // base case
    if(root == NULL) return ;

    postorder(root->left);
    postorder(root ->right);
    cout << root -> data << " " ;
}


void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << " enter data for root : " ;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    node* root = NULL;
    
    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);


    /*
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);


    cout<<"inorder traversal" << endl;
    inorder(root);

    cout<< endl <<"preorder traversal" << endl;
    preorder(root);

    cout<< endl <<"postorder traversal" << endl;
    postorder(root);
    
    */
}