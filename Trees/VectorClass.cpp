#include <iostream>
#include <vector>
using namespace std;

int main(){
    //vector<int> *vp = new vector<int>(); //Dynamic
    vector<int> v; //Static
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;
    v[3] = 1002;

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;

}