#include <iostream>
// #include <cstring>
using namespace std;

int main()
{
    //Dynamically
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;
    cout << *sp << endl;

    string s = "abc";
    //cin terminates taking input if it detects
    //getline(cin, s);
    cout << s << endl;

    s = "defdef";
    cout << s[0] << endl;
    s[0] = 'a';
    string s1;
    s1 = "def";

    string s2 = s + s1;
    cout << s2 << endl;

    s += s1;

    string s3;
    s3 = "def";
    cout << s3 << endl;
    cout << s << endl;

    cout << s.size() << endl;
    cout << s.length() << endl; // Both are same

    //Substring Function - it gives part of the string
    cout << s.substr(3) << endl;
    cout << s.substr(3, 3) << endl; //From third, upto third

    //find function - returns index.
    cout << s.find("def") << endl;
    cout << s.find("ef") << endl;
}