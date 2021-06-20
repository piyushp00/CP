/* For a given a string expression containing only round brackets or parentheses, 
check if they are balanced or not. Brackets are said to be balanced if the 
bracket which opens last, closes first. */

#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

//#solution 1
bool isBalanced(string s){
    stack<char> bracket;

    for(int i = 0; i < s.length(); i++){
        int a = s[i];
        if(a == 40){
            bracket.push(a);
        } else if(a == 41){
            if(bracket.empty())
            {
                return false;
            }
            
            char b = bracket.top();
            bracket.pop();
            
            if(a == 41 & b == 40){ 
                continue;
            } else {
                return false;
            }
        }
    }	
}

//#solution 2(cn)
bool isBalanced(string s){
    stack<char> stk;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            stk.push(s[i]);
        } else if(s[i] == ')'){

            if(stk.empty()){
                return false;
            }

            char topChar = stk.top();
            stk.pop();

            if(s[i] == ')' && topChar == '('){
                continue;
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main(){
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}