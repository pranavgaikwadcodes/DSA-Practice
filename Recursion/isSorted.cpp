#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){

    // base case
    if( n == 0 || n == 1 )
        return true;

    if( arr[0] > arr[1] )
        return false;
    else{
        bool remainingPart = isSorted( arr + 1 , n - 1 );
        return remainingPart;
    }

}

int main() {

    int arr[5] = {5,3,7,9,1};
    int size = 5;
    bool ans = isSorted(arr,size);

    if(ans){
        cout << "Array is sorted." << endl;
    }else{
        cout << "Array is not sorted." << endl;
    }

    return 0;
}