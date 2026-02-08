// Regular Expression Matching
// Hard
// Topics
// premium lock icon
// Companies
// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
 

// Constraints:

// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s, p;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter pattern p: ";
    cin >> p;

    int n = s.length();
    int m = p.length();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;

    // patterns like a*, a*b*, a*b*c*
    for(int j=2; j<=m; j++){
        if(p[j-1]=='*')
            dp[0][j] = dp[0][j-2];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            // normal or '.'
            if(p[j-1]==s[i-1] || p[j-1]=='.'){
                dp[i][j] = dp[i-1][j-1];
            }

            // star case
            else if(p[j-1]=='*'){
                // zero occurrence
                dp[i][j] = dp[i][j-2];

                // one or more occurrence
                if(p[j-2]==s[i-1] || p[j-2]=='.'){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
    }

    if(dp[n][m])
        cout<<"True (Match)";
    else
        cout<<"False (No Match)";

    return 0;
}
