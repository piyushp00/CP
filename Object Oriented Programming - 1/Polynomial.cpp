#include <algorithm>
#include <iostream>
using namespace std;

class Polynomial
{
    public:
    int *degCoeff;
    int capacity;


    //default constructor
    Polynomial()
    {
        degCoeff = new int[10];
        capacity = 10;
        for (int i = 0; i < 10; i++)
        {
            degCoeff[i] = 0;
        }
    }

    //copy constructor
    Polynomial(Polynomial const &p)
    {
        degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity;
    }

    //copy assignment operator
    void operator=(Polynomial const &p)
    {
        delete[] degCoeff;
        degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity;
    }

    //Set Coefficient Function
    void setCoefficient(int degree, int coeff)
    {
        if (degree >= capacity)
        {
            int size = 2 * capacity;
            while (size <= degree)
            {
                size *= 2;
            }

            int *newDegCoeff = new int[size];
            for (int i = 0; i < size; i++)
            {
                newDegCoeff[i] = 0;
            }

            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            capacity = size;
            delete[] degCoeff;
            degCoeff = newDegCoeff;
        }

        degCoeff[degree] = coeff;
    }

    //Getter
    int getCoefficient(int degree)
    {
        if (degree >= capacity)
        {
            return 0;
        }

        return degCoeff[degree];
    }

    // + operator
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial pNew;
        int i = 0, j = 0;
        while (i < this->capacity && j < p.capacity)
        {
            int deg = i;
            int coeff = this->degCoeff[i] + p.degCoeff[j];
            pNew.setCoefficient(deg, coeff);
            i++;
            j++;
        }

        while (i < capacity)
        {
            pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }

        while (j < p.capacity)
        {
            pNew.setCoefficient(j, p.degCoeff[j]);
            j++;
        }
        return pNew;
    }

    // - operator
    Polynomial operator-(Polynomial const &p)
    {
        Polynomial pNew;
        int i = 0, j = 0;
        while (i < this->capacity && j < p.capacity)
        {
            int deg = i;
            int coeff = this->degCoeff[i] - p.degCoeff[j];
            pNew.setCoefficient(deg, coeff);
            i++;
            j++;
        }

        while (i < capacity)
        {
            pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }

        while (j < p.capacity)
        {
            pNew.setCoefficient(j, (-1 * p.degCoeff[j]));
            j++;
        }
        return pNew;
    }

    // * operator
    Polynomial operator*(Polynomial p)
    {
        Polynomial pNew;

        for (int j = 0; j < p.capacity; j++)
        {
            for (int i = 0; i < capacity; i++)
            {
                int deg = i + j;
                int coeff = pNew.getCoefficient(deg) + (this->degCoeff[i] * p.degCoeff[j]);
                pNew.setCoefficient(deg, coeff);
            }
        }
        return pNew;
    }

    // print function
    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};
