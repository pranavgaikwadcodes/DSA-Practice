#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[100];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 1; i < n; i++){  //assume 0th element sorted so start from i = 1;

        int temp = arr[i];
        int j = i-1;
        for(; j >= 0; j--){

            if(arr[j] > temp){
                arr[j+1] = arr[j]; //shift
            }else{
                break;
            }

        }
        arr[j+1] = temp;

    }

    cout<<"==========Sorted Array=========="<<endl;
    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}