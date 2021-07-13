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
    }
}

int main(){

}