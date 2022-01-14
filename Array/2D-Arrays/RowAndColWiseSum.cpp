#include<iostream>
using namespace std;

void printSumRow(int arr[][3], int row, int col){

    cout << "Printing Row Wise Sum ->" << endl;
    for(int i = 0; i < row; i++){

        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += arr[i][j]; // row = i , col = j
        }

        cout << sum << endl;
    }

}

void printSumCol(int arr[][3], int row, int col){

    cout << "Printing Column Wise Sum ->" << endl;
    for(int i = 0; i < col; i++){

        int sum = 0;
        for(int j = 0; j < row; j++){
            sum += arr[j][i]; // row = j , col = i
        }

        cout << sum << " ";
    }

}

int main() {

    int arr[3][3];

    cout << "Enter array elements : " << endl;
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            cin >> arr[row][col];
        }
    }

    //print 2D array
     for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    printSumRow(arr,3,3);
    printSumCol(arr,3,3);


    return 0;
}