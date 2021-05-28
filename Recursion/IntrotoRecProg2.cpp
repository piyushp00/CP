#include <iostream>
using namespace std;

int factorial(int n) {
    if(n == 0){     //Base Case
        return 1; 
    }
    int smallOutput = factorial(n-1);  //Assume it to be true for (n-1)
    int output = n * smallOutput;  // If true for (n-1), then also true for n
    return output;  
}

int main() {
    cout << factorial(5) << endl;
}