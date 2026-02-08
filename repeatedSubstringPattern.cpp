// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

// Example 1:

// Input: s = "abab"
// Output: true
// Explanation: It is the substring "ab" twice.
// Example 2:

// Input: s = "aba"
// Output: false
// Example 3:

// Input: s = "abcabcabcabc"
// Output: true
// Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;   

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool ans = false;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            string sub = s.substr(0, i);
            string temp = "";
            for (int j = 0; j < n / i; j++) {
                temp += sub;
            }
            if (temp == s) {
                ans = true;
                break;
            }
        }
    }
    cout << (ans ? "true" : "false") << endl;
}

