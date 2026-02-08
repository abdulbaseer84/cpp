// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.
#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s; // s="aab"
    int n = s.size();
    vector<vector<string>> result;
    vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp=[[false,false,false],[false,false,false],[false,false,false]]

    for (int i = 0; i < n; i++) { // for(i=0; i<3; i++)
        for (int j = 0; j <= i; j++) { // for(j=0; j<=0; j++)
            if (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1])) { // if(s[0]==s[0] && (0-0<2 || dp[1][-1])) true
                dp[j][i] = true;// dp=[[true,false,false],[false,false,false],[false,false,false]]
            }
        }
    }

    function<void(int, vector<string>&)> backtrack = [&](int start, vector<string>& path) { // backtrack(0, [])
        if (start == n) { // if(0==3) false
            result.push_back(path); // result=[[]]
            return;
        }

        for (int end = start; end < n; end++) { // for(end=0; end<3; end++)
            if (dp[start][end]) { // if(dp[0][0]) true
                path.push_back(s.substr(start, end - start + 1)); // path=["a"]
                backtrack(end + 1, path); // backtrack(1, ["a"])
                path.pop_back(); // path=[]
            }
        }
    };

    vector<string> path;
    backtrack(0, path);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;// output: [["a","a","b"],["aa","b"]]
    return 0;
}