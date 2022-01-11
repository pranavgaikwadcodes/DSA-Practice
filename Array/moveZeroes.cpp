// https://leetcode.com/problems/move-zeroes/submissions/


#include<iostream>

using namespace std;

void MoveZeroes(int arr[] , int n){

// we will shift all non zero val to left
    int nonZeroIndex = 0;

    for( int i = 0; i < n; i++ ) {

        if( arr[i] != 0 ) {
            swap(arr[i],arr[nonZeroIndex]);
            nonZeroIndex++;
        }

    }

}


void printArray(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i];
    }
}


int main(){

    int size;
    cout<<"Size of array : "<<endl;
    cin>>size;

    int a[10];

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++){
        cin>>a[i];
    }

    MoveZeroes(a,size);
    printArray(a,size);

    return 0;
}