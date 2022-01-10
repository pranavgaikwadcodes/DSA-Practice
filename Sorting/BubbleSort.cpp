#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[100];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int count = 0;
    for(int i = 1; i < n; i++){

        bool swaped = false; // to save time and make this more optimized 

        for(int j = 0; j < n - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                count++;
                swaped = true;
            }
        }

        if(swaped == false) // if the array is already sorted then swaped will be false and no further process will be executed 
            break;

    }

    // descending order
    // for(int i = 1; i < n; i++){
    //     bool swaped = false;
    //     for(int j = 0; j < n - i; j++){
    //         if(arr[j] < arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //             count++;
    //             swaped = true;
    //         }
    //     }

    // }

    cout<<"==========Sorted Array=========="<<endl;
    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    cout<< endl << "num of sort required : " << count << endl;

    return 0;
}