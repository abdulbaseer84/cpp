// In a string s of lowercase letters, these letters form consecutive groups of the same character.

// For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

// A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

// A group is considered large if it has 3 or more characters.

// Return the intervals of every large group sorted in increasing order by start index.

 

// Example 1:

// Input: s = "abbxxxxzzy"
// Output: [[3,6]]
// Explanation: "xxxx" is the only large group with start index 3 and end index 6.
// Example 2:

// Input: s = "abc"
// Output: []
// Explanation: We have groups "a", "b", and "c", none of which are large groups.
// Example 3:

// Input: s = "abcdddeeeeaabbbcd"
// Output: [[3,5],[6,9],[12,14]]
// Explanation: The large groups are "ddd", "eeee", and "bbb".
 

// Constraints:

// 1 <= s.length <= 1000
// s contains lowercase English letters only.

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<vector<int>> result;
    int n = s.length();
    int i = 0;
    while (i < n) {
        int start = i;
        while (i < n && s[i] == s[start]) {
            i++;
        }
        int end = i - 1;
        if (end - start + 1 >= 3) {
            result.push_back({start, end});
        }
    }
    for (const auto& group : result) {
        cout << "[" << group[0] << "," << group[1] << "] ";
    }
    cout << endl;
    return 0;
}
