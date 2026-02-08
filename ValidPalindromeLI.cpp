// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {// if the characters at left and right are not equal, we can either delete the character at left or the character at right
            string s1 = s.substr(left, right - left);// delete the character at right
            string s2 = s.substr(left + 1, right - left);// delete the character at left
            cout << (s1 == string(s1.rbegin(), s1.rend()) || s2 == string(s2.rbegin(), s2.rend())) << endl;
            return 0;
        }
        left++;
        right--;
    }
    cout << "true" << endl;
    return 0;
}