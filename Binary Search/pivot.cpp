#include<iostream>
using namespace std;

int pivot(int arr[], int n){

    int start = 0;
    int end = n - 1;
    int mid = start + ( (end - start) / 2 );

    while( start < end ){

        if( arr[mid] >= arr[0] ){
            start = mid + 1;
        } else {
            end = mid;
        }
        
        mid = start + ( (end - start) / 2 );

    }
    return start;
    // return end;
    /*
    in this case both start and end will be at same element at the end so we can return either start or end which will return the same value.
    */

}

int main() {

    int p[5] = { 3 , 8 , 10 , 17 , 1 };

    cout << "Pivot element is at Index : " << pivot(p,5) << endl;

    return 0;
}