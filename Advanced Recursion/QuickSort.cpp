#include <iostream>
using namespace std;

int partition(int a[], int si, int ei)
{
    int size = ei - si + 1;
    int smallerCount = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[si] > a[si + i])
        {
            smallerCount++;
        }
    }

    int m = si + smallerCount;
    int temp;
    temp = a[si];
    a[si] = a[m];
    a[m] = temp;

    int i = si;
    int j = ei;

    while (i < m || j >= m)
    {
        if (a[i] < a[m])
        {
            i++;
        }
        else if (a[j] >= a[m])
        {
            j--;
        }
        else
        {
            int tem;
            tem = a[i];
            a[i] = a[j];
            a[j] = tem;

            i++;
            j--;
        }
    }
    return m;
}

//Alternate partition function(minor changes)
/*
int partition(int a[], int si, int ei)
{
    int pivot = a[si]
    int smallerCount = 0;
    for (int i = si+1; i <= ei; i++)
    {
        if (pivot >= a[i])
        {
            smallerCount++;
        }
    }
    
    int pivotIndex = si + smallerCount;
    
    
    a[si] = a[pivotIndex];
    a[pivotIndex] = pivot;

    int i = si;
    int j = ei;

    while (i < pivotIndex || j > pivotIndex)
    {
        if (a[i] < a[pivotIndex])
        {
            i++;
        }
        else if (a[j] > a[pivotIndex])
        {
            j--;
        }
        else
        {
            
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }
    return pivotIndex;
    
}
*/


void quickSort(int a[], int si, int ei)
{

    //Base Case
    if (si >= ei)
    {
        return;
    }

    int pos = partition(a, si, ei);

    quickSort(a, si, pos - 1);
    quickSort(a, pos + 1, ei);
}

int main()
{
    int n, si, ei;
    int a[1000];

    cin >> n >> si >> ei;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(a, si, ei);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}