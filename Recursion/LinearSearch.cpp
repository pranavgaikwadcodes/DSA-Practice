#include<iostream>
using namespace std;
bool linearSearch(int arr[], int n, int k){
    
    //base case
    if(n == 0)
        return false;
    
    if(arr[0] == k){
        return true;
    } else {
        return linearSearch(arr+1,n-1,k);
    }

}
int main() {
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 5;

    bool ans = linearSearch(arr,size,key);

    if(ans){
        cout << " Key found." << endl;
    } else {
        cout << " Key not found." << endl;
    }

    return 0;
}