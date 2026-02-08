// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    string word1, word2;
    cin >> word1 >> word2; // word1="horse", word2="ros"
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // dp[0][0]=0; dp[1][0]=1; dp[2][0]=2; dp[3][0]=3; dp[4][0]=4; dp[5][0]=5
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // dp[0][0]=0; dp[0][1]=1; dp[0][2]=2; dp[0][3]=3
    }

    for (int i = 1; i <= m; i++) { // for(i=1; i<=5; i++)
        for (int j = 1; j <= n; j++) { // for(j=1; j<=3; j++)
            if (word1[i - 1] == word2[j - 1]) { // if(word1[0]==word2[0]) true; if(word1[1]==word2[1]) true; if(word1[2]==word2[2]) false; if(word1[3]==word2[3]) false; if(word1[4]==word2[4]) false
                dp[i][j] = dp[i - 1][j - 1]; // dp[1][1]=dp[0][0]=0
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1, // delete
                                min(dp[i][j - 1] + 1, // insert
                                    dp[i - 1][j - 1] + 1)}); // replace
            }
        }
    }

    cout << dp[m][n] << endl;// output: 3

    return 0;
}