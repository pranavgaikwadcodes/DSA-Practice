#include<iostream>
using namespace std;

bool binarySearch(int arr[], int n, int start, int end, int k){
    
    //base case
    if(start > end) // element not foud
        return false;

    int mid = start + (end - start)/2;

    if(arr[mid] == k){ // element found
        return true;
    }
    else if (arr[mid] > k) {
        return binarySearch( arr, n, start, mid - 1, k);
    }
    else {
        return binarySearch( arr, n, mid + 1, end, k);
    }
    
}

int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    int key = 5;

    bool ans = binarySearch(arr,size,0,size-1,key);

    if(ans){
        cout << "Key found" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}