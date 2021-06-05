#include <iostream>
using namespace std;

int subSequences(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;

    }

    string smallString = input.substr(1);
    int smallOutputSize = subSequences(smallString, output);

    for(int i = 0; i < smallOutputSize; i++){
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main(){
    string input;
    cin >> input;
    string* output = new string[1000];
    int count = subSequences(input, output);
    cout << count << endl;
    for(int i = 0; i < count; i++){
        cout << output[i] << endl;
    }
}