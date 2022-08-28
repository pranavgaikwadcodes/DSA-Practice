#include<iostream>
#include<stack>

using namespace std;

int main(){

    //stack creation
    stack<int> s;

    // Push
    s.push(2);
    s.push(3);
    
    // Pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "stack is empty";
    }else{
        cout << "stack is not empty";
    }

    return 0;
}