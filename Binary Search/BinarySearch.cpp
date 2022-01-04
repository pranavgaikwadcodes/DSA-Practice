#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size,int key){

    int start = 0;
    int end = size - 1;
    // int mid = (start + end)/2;
    int mid = start + ((end-start)/2);

    while(start <= end){

        if(arr[mid]==key){ // key found condition
            
            return mid;

        } else if(key > arr[mid]){ //going right
           
            start = mid + 1;

        } else { // going left
            
            end = mid - 1;

        }
        
        mid = start + ((end-start)/2);

    }
    return -1;

}

int main(){

    int even[6] = {2,4,6,8,10,12};
    int odd[5] = {3,5,7,9,10};

    int evenArr = BinarySearch(even,6,10);
    cout<<"Index of 10 : "<<evenArr<<endl;

    int oddArr = BinarySearch(odd,5,2);
    cout<<"Index of 10 : "<<oddArr<<endl;

    return 0;
}


// Search in a rotated & Sorted array:  https://bit.ly/3rEVSK7