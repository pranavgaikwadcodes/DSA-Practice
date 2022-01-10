#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[100];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 1; i < n; i++){

        for(int j = 0; j < n - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }

    }

    // descending order
    // for(int i = 1; i < n; i++){

    //     for(int j = 0; j < n - i; j++){
    //         if(arr[j] < arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }

    // }

    cout<<"==========Sorted Array=========="<<endl;
    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}