/* Given a random integer array A of size N. Find and print the count of pair of elements
in the array which sum up to 0.
Note: Array A can contain duplicate elements as well. */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int pairSumToZero(int* arr, int n){
    
    unordered_map<int, int> mp;
    int count = 0;
    for(int i = 0; i < n; i++){
        
		int complement = -arr[i];
        if(mp.count(complement)){
            count = count + mp[complement];
        }
    	mp[arr[i]]++;
    }
	return count;
}


int main(){
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = pairSumToZero(arr, n);
    cout << ans << endl;
    delete[] arr;
}