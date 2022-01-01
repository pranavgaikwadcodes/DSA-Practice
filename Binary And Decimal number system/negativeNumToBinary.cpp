#include<iostream>
#include<math.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    n=(~n) | 1;
    // cout<<n<<endl;
    int ans = 0,i = 0;
    int bit;
    while(n!=0){
        bit = n & 1;
        ans += (bit * pow(10,i));
        i++;
        n = n >> 1;
    }
    // cout<<ans<<endl;
    int twoCompOfBits = (~ans) | 1;
    int finalans = (~twoCompOfBits) | 1;
    cout<<twoCompOfBits;
    
}