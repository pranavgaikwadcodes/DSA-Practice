#include<iostream>
using namespace std;

// using 2 pointer approach
// void reverse(string& str, int i, int j){
//       //cout<< str << endl;
//     //base case
//     if(i > j){
//         return;
//     }

//     // process
//     swap( str[i] , str[j] );
//     i++;
//     j--;

//     // recursive call
//     reverse(str,i,j);
// }


// using 1 pointer approach
void reverse(string& str, int i){

    // cout<< str << endl;

    //base case
    if(i >= (str.length() / 2)){
        return;
    }

    // process
    /*
        str[(length - 1) - i] , eg: length of string is 3, therefore,
        str[ 3-1 - 0] , => str[2], i.e index 2 
        use this formula when using 1 pointer approach    
    */
    swap( str[i] , str[str.length() - i - 1] );
    i++;

    // recursive call
    reverse(str,i);
}

int main() {

    string str;
    cout << "Enter the string : " << endl;
    cin >> str;
    int len = str.length();

    // reverse(str , 0 , len - 1); // function call for 2 pointer approach
    reverse(str , 0); // function call for 1 pointer approach

    cout << "reversed string -> " << str << endl;

    return 0;
}