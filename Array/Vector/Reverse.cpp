#include<iostream>
#include<vector>
// #include<algorithm> 

using namespace std;


vector<int> reverse(vector<int> v){
// two pointer approach
    int start = 0;
    int end = v.size() - 1;

    while(start <= end){

        swap(v[start],v[end]);
        start++;
        end--;

    }
    return v;
}

void printArray(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
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

    // sort(v.begin(),v.end());

    vector<int> ans = reverse(v);

    printArray(ans);

    return 0;
}


// Reverse an Array: https://bit.ly/3EOyAFz 