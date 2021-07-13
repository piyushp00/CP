/*
Remove duplicates from integer array
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<int> removeDuplicates(int* a, int size){
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i = 0; i < size; i++){
        if(seen.count(a[i]) > 0){
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main(){
    int size = 0;
    cin >> size;
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    vector<int> v = removeDuplicates(arr, size);
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}