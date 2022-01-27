#include<iostream>
using namespace std;

bool checkPalindrome(string s, int i){

    //base case
    if( i > (s.length() / 2) ){
        return true;
    }

    /*
        s[(length - 1) - i] , eg: length of string is 3, therefore,
        s[ 3-1 - 0] , => s[2], i.e index 2 
        use this formula when using 1 pointer approach    
    */
    if( s[i] != s[s.length() - i - 1 ] ){ 
        
        return false;
    }
    else{
        i++;
        return checkPalindrome(s,i);
    }
}


// bool checkPalindrome(string s, int i, int j){

//     //base case
//     if(i > j){
//         return true;
//     }

//     if( s[i] != s[j] ){
//         return false;
//     }
//     else{
//         i++;
//         j--;
//         return checkPalindrome(s,i,j);
//     }
//    // return true;
// }


int main() {

    string s;
    cin >> s;

    // bool check = checkPalindrome(s,0,s.length()-1);
    bool check = checkPalindrome(s,0);

    if(check){
        cout << "it is palindrome." << endl;
    }else{
        cout << "it is not palindrome." << endl;
    }

    return 0;
}