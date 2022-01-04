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

    int arr[10] = {0,1,1,2,2,2,2,2,3,3};

    cout<<"First occurrence of element 2 is at index : "<<firstOccurrence(arr,10,2)<<endl;
    cout<<"Last occurrence of element 2 is at index : "<<lastOccurrence(arr,10,2)<<endl;

    // formula to take out the total occurrence of a element
    int TotalOccurrence = ( lastOccurrence(arr,10,2) - firstOccurrence(arr,10,2)) + 1;

    cout<<"Total number of OCCURRENCE OF ELEMENT is : " << TotalOccurrence << endl;

    return 0;
}