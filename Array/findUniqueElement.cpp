/*
Problem Statement (https://bit.ly/3y01Zdu)
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
*/

#include<iostream>
using namespace std;

int findUnique(int arr[], int size) {
    
    int ans = 0;
    for(int i = 0; i < size; i++){
        ans = ans ^ arr[i];
        // XOR with same number is ezual to '0'. So if we XOR all elements  the remaining Unique element will be found out (XOR symbol = ^).
    }
    cout << ans;
    return ans;
}

int main() {
    
    int size;
    cout<<"Size of array : "<<endl;
    cin>>size;

    int a[10];

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++){
        cin>>a[i];
    }

    findUnique(a,size);

    return 0;
}