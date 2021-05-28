#include <iostream>
using namespace std;

//Alternate Method
/*bool is_sorted2(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    bool isSmallerOutput = is_sorted2(a + 1, size - 1);
    if (!isSmallerOutput)
    {
        return false;
    }

    if (a[0] > a[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}*/

bool is_sorted(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (a[0] > a[1])
    {
        return false;
    }

    bool isSmallerSorted = is_sorted(a + 1, size - 1);
    return isSmallerSorted;

    //or
    /*if (isSmallerSorted)
    {
        return true;
    }
    else
    {
        return false;
    }*/
}

int main()
{
    int a[] = {1, 2, 3, 4};
    bool c = is_sorted(a, 4);
    cout << c << endl;

}
