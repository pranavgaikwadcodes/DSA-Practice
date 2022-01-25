#include<iostream>
using namespace std;

int powerOf2(int n){

    //base case
    if( n == 0 ) return 1;

    //Recursive call
    return 2 * powerOf2(n-1);
}

int main() {
    
    int n;
    cout << "2 to the power -> ";
    cin >> n;

    int ans = powerOf2(n);
    cout << ans << endl;

    return 0;
}