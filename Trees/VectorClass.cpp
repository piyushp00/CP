#include <iostream>
#include <vector>
using namespace std;

int main(){
    //vector<int> *vp = new vector<int>(); //Dynamic
    vector<int> v; //Static

    for(int i = 0; i < 100; i++){
        cout << "Capacity: " << v.capacity() << endl;
        cout << "Size: " << v.size() << endl;
        v.push_back(i+1); 
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100; //we can use '[]' for getting element and updating and not for insertion
    
    //Don't use this for inserting elements
    //v[3] = 1002; //wrong practice
    //v[4] = 10025
    v.push_back(40);
    v.push_back(50);

    //For deleting
    v.pop_back();


    //printing with the loop
    /*for(int i = 0; i< v.size(); i++){
        cout << v[i] << endl;
        //or
        //cout << v.at(i) << endl;
    }*/

    /* cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;

    //size
    cout << "Size: " << v.size() << endl;

    //Alternative of '[]'
    cout << v.at(1) << endl;
    cout << v.at(5) << endl; //safer to use..will give error if we will access out of range elements */
}