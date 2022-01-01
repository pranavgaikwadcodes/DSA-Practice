#include<iostream>
using namespace std;

bool search(int arr[], int arrSize, int Key){

    for(int i = 0; i < arrSize; i++){
        if(Key == arr[i]){
            return 1; // true
        }
    }
    return 0; //false
}

int main() {

    int size;
    cout<<"Size of array : "<<endl;
    cin>>size;

    int nums[10];

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++){
        cin>>nums[i];
    }
    int key;
    cout<<"Enter KEY to search : "<<endl;
    cin>>key;

    if(search(nums,size,key)){
        cout<< "Key Found in given array" ;
    }else{
        cout<< "Key Not-Found in given array" ;
    }
}