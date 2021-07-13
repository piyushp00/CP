/* You have been given two integer arrays/list(ARR1 and ARR2)of size N and M, respectively.
You need to print their intersection; An intersection for this problem can be defined 
when both the arrays/lists contain a particular value or to put it in other words, when
there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.
The intersection elements printed would be in the 
order they appear in the first sorted array/list(ARR1). */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

#include<unordered_map>
#include <algorithm>
void intersection(int arr1[], int arr2[], int size1, int size2) {
    unordered_map<int,int> checkMap;
    vector<int> v;

    for (int i = 0; i < size1; i++){
        checkMap[arr1[i]]++;
    }

    for (int i = 0; i < size2; i++){
        if (checkMap.count(arr2[i])){
            if (checkMap[arr2[i]] > 0){
                v.push_back(arr2[i]);
                checkMap[arr2[i]]--;
                
            }
        }
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
}