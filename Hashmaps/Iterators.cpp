#include <iostream>
#include <unordered_map>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){

    //? unordered map
    unordered_map<string, int> mp;
    mp["abc"] = 1;
    mp["abc1"] = 2;
    mp["abc2"] = 3;
    mp["abc3"] = 4;
    mp["abc4"] = 5;
    mp["abc5"] = 6;

    unordered_map<string, int>::iterator it = mp.begin();
    while (it != mp.end()){
        cout << "Key: " << it->first << " Value: " << it->second <<endl;
        it++;
    }

    //find in map(it will return iterator)
    unordered_map<string, int>::iterator it2 = mp.find("abc");
    //we can also give erase function iterator
    mp.erase(it2);
    //mp.erase(starting iterator, ending iterator)
    //e.g.
    //mp.erase(it2, it2 + 4); it will delete from it2, it2 + 1, it2 + 3


    //? vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    
    vector<int>::iterator it1 = v.begin();
    
    while(it1 != v.end()){
        cout << *it1 << endl;
        it1++; 
    }


    //alternate way of printing vector using range
    for(auto const i: v){
        cout << i << " ";
    }
    cout << endl;

    //print array using range 
    int arr[] = {5, 3, 2, 5, 6};
    for(auto const j: arr){
        cout << j << " ";
    }
}