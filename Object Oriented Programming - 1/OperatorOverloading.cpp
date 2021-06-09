#include <iostream>
using namespace std;
#include "Fraction1.cpp"

int main()
{
    int i = 5, j = 3;
    (i += j) += j;
    cout<< i << " " << j << endl;
    
    
    fraction f1(10, 2);
    fraction f2(15, 4);

    //post-increment
    fraction f3 = f1++;
    f1.print();
    f3.print();
    
    //pre increment
    /* f1.print();
    fraction f3= ++(++f1);  //if we dont't return by reference final change will only reflect in f3 not in f1
    f1.print();
    f3.print();  */


    
    
    //++f1;
    //f1.print();
    /* fraction f3 = ++f1;
    f1.print();
    f3.print(); */

    /* fraction f3 = f1.add(f2);

    //But we dont't want to use add function,we want '+' operator.
    fraction f4 = f1 + f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();

    fraction f5 = f1 * f2;
    f5.print();

    if (f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    } */

}