#include<iostream>
using namespace std;

int arrSum(int arr[], int n){

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {

    int n;
    cin >> n;

    //creating variable size array
    // new keyword will allocate memory in heap and not in stack
    int* arr = new int[n];

    //taking input
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << arrSum(arr,n) << endl;

    return 0;
}