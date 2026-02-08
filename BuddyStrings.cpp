// Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

// For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

// Example 1:

// Input: s = "ab", goal = "ba"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
// Example 2:

// Input: s = "ab", goal = "ab"
// Output: false
// Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
// Example 3:

// Input: s = "aa", goal = "aa"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 

// Constraints:

// 1 <= s.length, goal.length <= 2 * 104
// s and goal consist of lowercase letters.

#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string s, goal;
    cin >> s >> goal;
    if (s.length() != goal.length()) {
        cout << "false" << endl;
        return 0;
    }
    if (s == goal) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
            if (count[c - 'a'] > 1) {
                cout << "true" << endl;
                return 0;
            }
        }
        cout << "false" << endl;
        return 0;
    }
    vector<int> diff_indices;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != goal[i]) {
            diff_indices.push_back(i);
            if (diff_indices.size() > 2) {
                cout << "false" << endl;
                return 0;
            }
        }
    }
    if (diff_indices.size() != 2) {
        cout << "false" << endl;
        return 0;
    }
    int i = diff_indices[0], j = diff_indices[1];
    if (s[i] == goal[j] && s[j] == goal[i]) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}