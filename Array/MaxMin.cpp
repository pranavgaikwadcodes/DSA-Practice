#include<iostream>
using namespace std;

int getMax(int arr[],int arrSize){

    int maxi = INT_MIN;

    for(int i = 0; i < arrSize; i++){
        // method 1 (using predefined function 'min()')
        maxi = max(maxi,arr[i]);

        // method 2
        // if(arr[i]>maxi){
        //     maxi = arr[i];
        // }

    }
    return maxi; // return max value in array
}

int getMin(int arr[],int arrSize){

    int mini = INT_MAX;

    for(int i = 0; i < arrSize; i++){
        // method 1 (using predefined function 'max()')
        mini = min(mini,arr[i]);

        // method 2
        // if(arr[i] < mini){
        //     mini = arr[i];
        // }

    }
    return mini; // return min value in array
}

int main() {

    int size;
    cout<<"Size of array : "<<endl;
    cin>>size;

    int num[100];

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++){
        cin>>num[i];
    }

    cout<<" Max Value in array is : " << getMax(num,size) << endl;
    cout<<" Min Value in array is : " << getMin(num,size) << endl;

    return 0;
}