#include <iostream>
using namespace std;

int factorial(int n) {
    if(n == 0){     
        return 1; 
    }
    int smallOutput = factorial(n-1);  
    return n * smallOutput;  //Assume it to be true for (n-1)  
}

int main() {
    int n;
    cout << "Enter the no.";
    cin >> n;
    int output = factorial(n);
    cout << output << endl;
}