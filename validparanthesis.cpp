// Longest Valid Parentheses
// Hard
// Topics
// premium lock icon
// Companies
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    stack<int> st;
    st.push(-1); // base boundary

    int maxLen = 0;

    for(int i = 0; i < s.length(); i++){

        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();

            if(st.empty()){
                st.push(i); // new boundary
            }
            else{
                int len = i - st.top();
                maxLen = max(maxLen, len);
            }
        }
    }

    cout << "Longest valid parentheses length: " << maxLen;
    return 0;
}
