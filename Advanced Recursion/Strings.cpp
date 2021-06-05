#include <iostream>
// #include <cstring>
using namespace std;

int main(){
    //Dynamically
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;
    cout << *sp << endl;

    string s ="abc";
    //cin terminates taking input if it detects
    getline(cin, s);
    cout << s << endl;

    s = "defdef";
    cout << s[0] << endl;
    s[0] = 'a';
    string s1;
    s1 = "def";

    


    string s1;
    s1 = "def";
    cout << s1 << endl;
    cout << s << endl;

}