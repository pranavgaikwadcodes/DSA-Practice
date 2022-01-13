// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include<iostream>
using namespace std;


string removeOccurrences(string s, string part) {
    while( s.length() != 0 && s.find(part) < s.length() ){
        s.erase(s.find(part) , part.length());
    }
    return s;
}

int main() {

    string s, part;

    cout<< endl << " Main String : " ;
    cin>>s;
    
    cout<< endl << "Substring : ";
    cin>>part;

    cout << endl <<"Result - > " << removeOccurrences(s,part);

    return 0;
}