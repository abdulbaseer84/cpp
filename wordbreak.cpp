// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
    string s;
    cin >> s; // s="leetcode"
    int n = s.size();
    int m; // m=2
    cin >> m;
    unordered_set<string> wordDict;
    for (int i = 0; i < m; i++) {
        string word;
        cin >> word; // word="leet"; word="code"
        wordDict.insert(word); // wordDict={"leet","code"}
    }
    vector<bool> dp(n + 1, false); // dp=[false,false,false,false,false,false,false,false,false]
    dp[0] = true; 

    for (int i = 1; i <= n; i++) { // for(i=1; i<=8; i++)
        for (int j = 0; j < i; j++) { // for(j=0; j<1; j++)
            if (dp[j] && wordDict.count(s.substr(j, i - j))) { 
                dp[i] = true;
                break;
            }
        }
    }

    cout << (dp[n] ? "true" : "false") << endl;// output: true

    return 0;
}
// s="leetcode"
// n=8
// m=2
// wordDict={"leet","code"}
// dp=[true,false,false,false,false,false,false,false,false]
// i=1
// j=0
// dp[0] && wordDict.count(s.substr(0, 1)) false
// i=2
// j=0
// dp[0] && wordDict.count(s.substr(0, 2)) false
