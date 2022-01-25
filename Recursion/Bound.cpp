#include<iostream>
using namespace std;

int firstOcc(int* arr, int start, int end, int k){
    
    int mid = start + (end - start)/2;

    // base case
    if(start >= end){
        return start;
    }

    if(arr[mid] == k){
        return firstOcc(arr,start,mid,k);
    } else if(arr[mid] > k){
        return firstOcc(arr,start,mid-1,k);
    } else{
        return firstOcc(arr,mid + 1,end,k);
    }

}

int lastOcc(int* arr, int start, int end, int k){
    
    int mid = start + (end - start)/2;
    // base case
    if(start >= end){
        return mid;
    }

    if(arr[mid] == k){
        return lastOcc(arr,mid + 1,end,k);
    }
    else if(arr[mid] < k){
        return lastOcc(arr,mid + 1,end,k);
    }
    else{
        return lastOcc(arr,start,mid-1,k);
    }

}

int main() {

    int arr[10] = {1,1,1,2,2,2,2,8,9,9};
    int size = 10;
    int key = 2;

    int first = firstOcc(arr, 0, size-1, key);
    int last = lastOcc(arr, 0, size-1, key);

    cout << "First occurrence of element 2 is at index : " << first <<endl;
    cout << "Last occurrence of element 2 is at index : " << last <<endl;
    cout << "Total number of Occurrence is : " << last - first + 1 << endl;
    
    return 0;
}