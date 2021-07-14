/* You are given an array of integers that contain numbers in random order.
Write a program to find and return the number which occurs the maximum 
times in the given input.
If two or more elements contend for the maximum frequency, return the 
element which occurs in the array first. */

#include <iostream>
#include <unordered_map>

#include <string>
using namespace std;

int highestFrequency(int *arr, int n){	 
	unordered_map<int,int> freq;
    int maxCount = -1;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
        maxCount = max(maxCount, freq[arr[i]]);
    }

    int maxFreqElement;
    
    for(int i = 0; i < n; i++){
        if(freq[arr[i]] == maxCount){
            maxFreqElement = arr[i];
            break;
        }
    }
    return maxFreqElement;
}

int main(){
    int n;
    cin >> n;
    
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}


