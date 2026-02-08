// valid parentheses with best time complexity and space complexity
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(const string& s) {
    stack<char> stk;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') { // opening brackets
            stk.push(ch);// push to stack
        } else {
            if (stk.empty()) return false;
            char top = stk.top(); // get the top element
            stk.pop();          // check for matching pairs
            if ((ch == ')' && top != '(') ||    // closing brackets
                (ch == '}' && top != '{') ||    // mismatched pairs
                (ch == ']' && top != '[')) {    // return false if not matching
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    if (isValid(input)) {
        cout << "The parentheses are valid." << endl;
    } else {
        cout << "The parentheses are not valid." << endl;
    }

    return 0;
}