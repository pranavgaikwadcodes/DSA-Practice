#include<iostream>
using namespace std;

void swapAlternate(int arr[],int arrSize){

    for(int i = 0; i < arrSize; i+=2 ){

        if(arr[i]<arrSize){
            swap(arr[i],arr[i+1]);

            //without using inbuilt swap function
            // int temp = arr[i];
            // arr[i] = arr[i+1];
            // arr[i+1] = temp;
        }

    }

}

void printArray(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {

    int size;
    cout<<"Size of array : "<<endl;
    cin>>size;

    int data[20];

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++){
        cin>>data[i];
    }

    swapAlternate(data,size);
    printArray(data,size);

    return 0;
}