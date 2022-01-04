/*
First/Last Occurrence of an Element in array: https://bit.ly/3Ioexjh 
*/

#include<iostream>
using namespace std;

int firstOccurrence(int arr[], int size, int key){

    int start = 0;
    int end = size - 1;
    int mid = start + ((end-start)/2);
    int ans = -1;

    while(start <= end){

        if(arr[mid] == key){

            ans = mid;
            end = mid - 1;

        } else if(arr[mid] < key){

            start = mid + 1;

        } else if(arr[mid] > key){

            end = mid - 1;

        }
        
        mid = start + ((end - start)/2);

    }

    return ans;

}

int lastOccurrence(int arr[], int size, int key){

    int start = 0;
    int end = size - 1;
    int mid = start + ((end-start)/2);
    int ans = -1;

    while(start <= end){

        if(arr[mid] == key){

            ans = mid;
            start = mid + 1;

        } else if(arr[mid] < key){

            start = mid + 1;

        } else if(arr[mid] > key){

            end = mid - 1;

        }
        
        mid = start + ((end - start)/2);

    }

    return ans;

}

int main() {

    int arr[5] = {1,2,2,2,3};

    cout<<"First occurrence of element 2 is at index : "<<firstOccurrence(arr,5,2)<<endl;
    cout<<"Last occurrence of element 2 is at index : "<<lastOccurrence(arr,5,2)<<endl;

    return 0;
}