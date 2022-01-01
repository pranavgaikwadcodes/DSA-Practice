#include<iostream>
using namespace std;

void reverse(int arr[], int size){

    int start = 0;
    int end = size - 1;

    while(start<=end){

        swap(arr[start],arr[end]);
        start++;
        end--;

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

    reverse(a,size);
    printArray(a,size);

    return 0;
}