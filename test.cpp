#include <iostream>
using namespace std;

void merge(int a[], int si, int ei)
{
    int size = ei - si + 1;
    int mid = (si + ei) / 2;

    int *out = new int[size];
    int i = si;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= ei)
    {
        if (a[i] < a[j])
        {
            out[k] = a[i];
            k++;
            i++;
        }
        else
        {
            out[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        out[k] = a[i];
        k++;
        i++;
    }

    while (j <= ei)
    {
        out[k] = a[j];
        k++;
        j++;
    }

    int m = 0;
    for (int i = 0; i < size; i++)
    {
        a[i] = out[m];
        m++;
    }

    delete[] out;
}

void mergeSort(int a[], int si, int ei)
{

    //Base Case
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;
    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, ei);
    merge(a, si, ei);
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

    mergeSort(a, si, ei);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
