#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n){

    //base case
    if( n == 0 || n == 1 ){
        return;
    }

    for(int i = 0; i < n - 1; i++){
        if( arr[i] > arr[i + 1] ){
            swap(arr[i], arr[i+1]);
        }
    }

    return bubbleSort(arr,n-1);
}

void printArr(int *arr, int n){
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[5] = {5,7,4,2,0};
    int size = 5;

    bubbleSort(arr,size);

    printArr(arr,size);

    return 0;
}