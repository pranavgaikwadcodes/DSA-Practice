#include<iostream>
using namespace std;

long long int SquareInteger(int n){

    int start = 0;
    int end = n;
    long long int mid = start + ( (end - start)/2 );

    long long int ans = -1;
    while(start <= end){
        
        long long square = mid * mid;

        if(square == n){
            return mid;
        }

        if(square < n){
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + ( (end - start)/2 );
    }
    return ans;

}

double morePrecision(int n, int precision, int temprorySolution){

    double ans = temprorySolution;
    double factor = 1;

    for( int i = 0; i < precision; i++ ){

        factor = factor / 10; // this will give me value in decimal points (1/10 = 0.1)

        for(double j = ans; j*j < n; j = j + factor){
            ans = j;
        }

    }

    return ans;

}

int main() {

    int n;
    cout << "Enter the number : " << endl;
    cin >> n;

    int tempSol = SquareInteger(n);
    cout << " Answer : " << tempSol << endl;
    cout << " Correct Answer : " << morePrecision(n,3,tempSol) << endl;

    return 0;
}