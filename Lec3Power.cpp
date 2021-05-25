#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }

    int smallOutput = power(x, n - 1);
    int output = x * smallOutput;
    return output;
}

int main()
{
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;
}
