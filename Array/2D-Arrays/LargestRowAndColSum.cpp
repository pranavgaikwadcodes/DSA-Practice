#include<iostream>
using namespace std;

int printLargestSumRow(int arr[][3], int row, int col){
    
    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int i = 0; i < row; i++){
        
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
        }

        if(maxi < sum){
            maxi = sum;
            rowIndex = i;
        }
    }

    cout << " MAX ROW SUM IS : " << maxi;
    return rowIndex;
}

int printLargestSumCol(int arr[][3], int row, int col){

    int maxi = INT_MIN;
    int colIndex = -1;

    for(int i = 0; i < col; i++){

        int sum = 0;
        for(int j = 0; j < row; j++){
            sum += arr[j][i];
        }
        if(maxi < sum){
            maxi = sum;
            colIndex = i;
        }
    }

    cout << " MAX COLUMN SUM IS : " << maxi;
    return colIndex;
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

    int rowSumIndex = printLargestSumRow(arr,3,3);
    cout << " present at Index - > " << rowSumIndex << endl;

    int colSumIndex = printLargestSumCol(arr,3,3);
    cout << " present at Index - > " << colSumIndex << endl;

    return 0;
}