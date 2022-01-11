#include<iostream>
#include<vector>

using namespace std;

/*
vector<int>& arr  ->  Pass by reference
vector<int> arr   ->  Pass by value
*/

void rotateArray(vector<int>& arr, int k){

    vector<int> temp(arr.size());

    for(int i = 0; i < arr.size(); i++){
        
        temp[(i+k)%arr.size()] = arr[i];

    }

    arr = temp;

}

void printarray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main() {

    vector<int> v;

    v.push_back(11);
    v.push_back(1);
    v.push_back(13);
    v.push_back(16);
    v.push_back(20);

    int k;
    cout<<"Rotate By : "<<endl;
    cin>>k;

    rotateArray(v,k);
    printarray(v);

    return 0;
}