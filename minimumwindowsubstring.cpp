// Minimum Window Substring
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    vector<int> need(128,0);

    for(char c : t)
        need[c]++;

    int left = 0;
    int required = t.length();

    int minLen = INT_MAX;
    int start = 0;

    for(int right=0; right<s.length(); right++){

        // include character
        if(need[s[right]] > 0)
            required--;

        need[s[right]]--;

        // valid window found
        while(required == 0){

            // update answer
            if(right-left+1 < minLen){
                minLen = right-left+1;
                start = left;
            }

            // remove left character
            need[s[left]]++;

            if(need[s[left]] > 0)
                required++;

            left++;
        }
    }

    if(minLen == INT_MAX)
        cout << "No window found";
    else
        cout << "Minimum window substring: " 
             << s.substr(start, minLen);

    return 0;
}
