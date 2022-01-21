// Median in a row-wise sorted Matrix
// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1/?page=1&category[]=Binary%20Search&query=page1category[]Binary%20Search


// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

int median(int arr[][3], int row, int col){
    vector<int> v;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            v.push_back(arr[i][j]);
        }
    }

    sort(v.begin(),v.end());

    int midElement = v.size() / 2;

    return v[midElement];
}

int main() {

    int arr[3][3] = {   {1, 3, 5}, 
                        {2, 6, 9}, 
                        {3, 6, 9}   };

    cout << median(arr,3,3);

    return 0;
}