#include <iostream>
#include <cstring>
using namespace std;

void removeX(char s[])
{

    if (s[0] == '\0')
    {
        return;
    }

    if (s[0] != 'x')
    {
        removeX(s + 1);
    }
    else
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        removeX(s);
    }

    
}

int stringLength(char s[])
{
    if (s[0] == '\0')
    {
        return 0;
    }

    int smallLength = stringLength(s + 1);
    return smallLength + 1;
}

int main()
{
    char str[100];
    cin >> str;

    int l = stringLength(str);
    cout << l << endl;

    removeX(str);
    cout << str << endl;
    l = stringLength(str);
    cout  << l << endl;
}