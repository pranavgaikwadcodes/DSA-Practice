#include<iostream>
using namespace std;

int firstOcc(int* arr,int n, int start, int end, int k){
    
    // base case
    if(start >= end){
        return start;
    }

    int mid = start + (end - start)/2;

    if(arr[mid] == k){
        return firstOcc(arr,n,start,mid,k);
    } else if(arr[mid] > k){
        return firstOcc(arr,n,start,mid-1,k);
    } else{
        return firstOcc(arr,n,mid + 1,end,k);
    }

}

int lastOcc(int* arr,int n, int start, int end, int k){
    
    // base case
    if(start >= end){
        return start;
    }

    int mid = start + (end - start)/2;

    if(arr[mid] == k){
        return firstOcc(arr,n,mid + 1,end,k);
    } else if(arr[mid] > k){
        return firstOcc(arr,n,start,mid-1,k);
    } else{
        return firstOcc(arr,n,mid + 1,end,k);
    }

}

int main() {

    int arr[5] = {1,2,2,2,3};
    int size = 5;
    int key = 2;

    int first = firstOcc(arr,size,0,size-1,key);
    int last = lastOcc(arr,size,0,size-1,key);

    cout << "First occurrence of element 2 is at index : " << first <<endl;
    cout << "Last occurrence of element 2 is at index : " << last <<endl;
    
    return 0;
}