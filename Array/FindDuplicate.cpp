/*
Problem Statement (https://bit.ly/3dm6bdZ)
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.
*/


#include<iostream>
using namespace std;

int findDuplicate(int arr[],int size){

    int ans = 0;
    
    // XOR all elements
    for(int i = 0; i < size; i++){
        ans = ans ^ arr[i];
    }
	// XOR [1, n-1 ] elements
    for(int i = 1; i < size; i++){
        ans = ans^i;
    }
    cout<<ans;
    return ans;
}

int main() {
    
    int size;
    cout<<"Size of array : "<<endl;
    cin>>size;

    int a[10];

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++){
        cin>>a[i];
    }

    findDuplicate(a,size);

}