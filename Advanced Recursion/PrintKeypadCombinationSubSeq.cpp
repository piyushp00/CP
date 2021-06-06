#include <iostream>
#include <string>
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

void printKeypadSubSequence(int n, string output){
    if(n == 0 || n == 1){
        cout << output << endl;
        return;
    }


    int lastDigit = n % 10;
    int smallNo = n / 10;
    string options = getString(lastDigit);
    for(int i = 0; i < options.length(); i++){
        printKeypadSubSequence(smallNo, options[i] + output);
    }
} 

int main(){
    int n;
    cin >> n;

    string output = "";
    printKeypadSubSequence(n, output);
}