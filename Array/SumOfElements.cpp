#include<iostream>
using namespace std;

void sumOfElements(int arr[],int arrSize){

    int ans = 0;
    for(int i = 0; i < arrSize; i++){
        ans = ans + arr[i];
    }
    cout<<ans;
}

int main() {

    int size;
    cout<<"Size of array : "<<endl;
    cin>>size;

    int num[10];

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++){
        cin>>num[i];
    }
    
    sumOfElements(num,size);

}