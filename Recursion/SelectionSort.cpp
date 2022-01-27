#include<iostream>
using namespace std;

void  selectionSort(int* arr, int n){

    //base case
    if( n == 0 || n == 1 ){
        return;
    }

    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if( arr[minIndex] > arr[j] ){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

    return selectionSort( arr + 1 , n - 1 );
}


void printArr(int *arr, int n){
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {

    int arr[5] = {6,2,2,8,9};
    int size = 5;

    selectionSort(arr,size);
    printArr(arr,size);

    return 0;
}