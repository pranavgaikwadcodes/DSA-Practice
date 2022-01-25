// this solution is not working properly 


// #include<iostream>
// using namespace std;

// long long int squareRoot(int n, int start, int end){
    
//     //base case
//     if(n == 0 || n == 1)
//         return n;

//     if(start >= end){
//         return end;
//     }

//     int mid = start + (end - start)/2;
//     long long int sq = mid * mid;

//     cout <<mid<<endl;
    
//     if(sq == n) {
//         return mid;
//     }

//     if(sq < n) {
//         return squareRoot(n,mid+1,end);
//     }
//     else {
//         return squareRoot(n,start,mid-1);
//     }

// }

// int main() {

//     int n;
//     cin >> n;

//     int start = 0, end = n;
//     long long int ans = squareRoot(n,start,end);
//     cout << endl << ans << endl;
//     return 0;
// }