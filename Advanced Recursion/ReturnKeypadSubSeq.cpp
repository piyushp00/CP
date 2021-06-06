#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string getString(int d)
{
    if (d == 2)
    {
        return "abc";
    }

    if (d == 3)
    {
        return "def";
    }

    if (d == 4)
    {
        return "ghi";
    }

    if (d == 5)
    {
        return "jkl";
    }

    if (d == 6)
    {
        return "mno";
    }

    if (d == 7)
    {
        return "pqrs";
    }

    if (d == 8)
    {
        return "tuv";
    }

    if (d == 9)
    {
        return "wxyz";
    }

    if(d == 0 || d == 1){
        return " ";
    }
}

int keypadSubSequence(int n, string output[]){

    // Base Case
    if(n == 0 || n == 1){
        output[0] = "";
        return 1;
    }

    int lastDigit = n % 10;
    int smallNum = n / 10;
    int smallOutputsize = keypadSubSequence(smallNum, output);
    string options = getString(lastDigit);
    for(int i = 0; i < options.length() - 1; i++){
        for(int j = 0; j < smallOutputsize; j++){
            output[j + (i + 1) * smallOutputsize]  = output[j];
        }
    }

    

    int k = 0;
    for(int i = 0; i < options.length(); i++){
        for(int j = 0; j < smallOutputsize; j++){
            output[k] = output[k] + options[i];
            k++;
        }
    }

    return smallOutputsize * options.length();
}

int main()
{
    int n;
    cin >> n;

    string *output = new string[10000];
    int count = keypadSubSequence(n, output);
    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}
