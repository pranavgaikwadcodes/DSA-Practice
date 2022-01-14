#include<iostream>
using namespace std;

bool isPresent(int arr[][4] , int row , int col, int Key){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){

            if(arr[i][j] == Key)
                return 1;
                
        }
    }
    return 0;
}

int main() {

    // create 2D array ->  arr[rows][columns]
    int arr[3][4];
    /*
    // can be initialized as :
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr[3][4] = { {1,2,3,4} , {5,6,7,8} , {9,10,11,12} };
    */
    
    /*
    // taking inputs -> row wise input
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 4; col++){
            cin >> arr[row][col];
        }
    }
    */

    // taking inputs -> col wise input
    for(int col = 0; col < 4; col++){
        for(int row = 0; row < 3; row++){
            cin >> arr[row][col];
        }
    }


    //print 2D array
     for(int row = 0; row < 3; row++){
        for(int col = 0; col < 4; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }


    cout<< "Enter Key to find : " << endl;
    int key;
    cin >> key;

    if(isPresent(arr,3,4,key)){
        cout << "Key is present." << endl;
    }
    else {
        cout << "Key is not present." << endl;
    }

    return 0;
}