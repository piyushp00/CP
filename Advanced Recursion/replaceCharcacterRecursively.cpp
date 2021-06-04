#include <iostream>
using namespace std;

void replaceCharacter(char s[], char c1, char c2)
{

    //Base Case
    if (s[0] == '\0')
    {
        return;
    }

    if (s[0] != c1)
    {
        replaceCharacter(s + 1, c1, c2);
    }
    else
    {

        s[0] = c2;
        replaceCharacter(s, c1, c2);
    }
}

int main()
{
    char str[100];
    cin >> str;

    char c1, c2;
    cin >> c1 >> c2;

    replaceCharacter(str, c1, c2);
    cout << str << endl;
}