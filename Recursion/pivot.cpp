#include<iostream>
using namespace std;

int pivot(int arr[], int n, int start, int end){

    // base case
    if(start >= end){
        return start;
    }

    int mid = start + ( (end - start) / 2 );

    if( arr[0] <= arr[mid] ){
        return pivot(arr, n, mid + 1, end);
    }
    else{
        return pivot(arr, n, start, mid);
    }
}

int main() {

    int p[5] = { 3 , 8 , 10 , 17 , 1 };
    int size = 5;
    cout<< "Pivot element is at Index : "
        << pivot(p,size,0,size-1)
        << endl;

    return 0;
}