#include<iostream>
using namespace std;

int main() {

    int rows,cols;

    cout << " Enter number of Rows : " << endl;
    cin >> rows;

    cout << " Enter number of Columns : " << endl;
    cin >> cols;

    // creating 2D array
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }

    cout << "Enter array elements" << endl;
    //taking inputs
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
    }

    cout << endl << " Your 2D Array is : " << endl;
    //printing output
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    // when we create Dynamic Array we should always release the memory after using it (it is not released automatically , we have to do it manualy)

    //releasing memory
    for(int i = 0; i < rows; i++){
        delete [] arr[i];
    }

    delete [] arr;

    return 0;
}