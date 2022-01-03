/*
(https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1#)
Given an array of length N consisting of only 0s and 1s in random order. Modify the array to segregate 0s on left side and 1s on the right side of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        int left = 0;
        int right = n-1;
        
        while(left < right){
            
            while(arr[left] == 0){
                left++;
            }
            
            while(arr[right] == 1){
                right++;
            }
            
            if(left<right){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }
            
        }
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}