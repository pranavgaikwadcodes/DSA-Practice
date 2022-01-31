#include<iostream>
using namespace std;

int partition(int arr[] , int start, int end){

    int pivot = arr[start];
    int count = 0;

    for(int i = start + 1; i <= end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    // place pivot at right position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // handle left and right part
    int i = start, j = end;

    while ( i < pivotIndex && j > pivotIndex ) {
        
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if( i < pivotIndex && j > pivotIndex ) {
            swap(arr[i++],arr[j--]);
        }

    }
    
    return pivotIndex;
}

void quickSort(int arr[], int start, int end){

    //base case
    if(start >= end) {
        return;
    }

    //do partition
    int p = partition(arr,start,end);

    //left 
    quickSort( arr , start , p - 1 );

    //right
    quickSort( arr , p + 1 , end );
}

void printArray(int *arr, int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[10] = {5,8,6,4,3,2,1,0,9,7};
    int size = 10;
    quickSort(arr,0,size-1);

    printArray(arr,size);

    return 0;
}