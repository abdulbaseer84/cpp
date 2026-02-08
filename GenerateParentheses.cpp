// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

//without complex code i want 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void backtrack(vector<string>& result, string current, int open, int close, int max) {// backtrack(result, "", 0, 0, 3)
    if (current.length() == max * 2) {// if(current.length()==6)
        result.push_back(current);// result=["((()))"]
        return;
    }

    if (open < max) {
        backtrack(result, current + "(", open + 1, close, max);
    }
    if (close < open) {
        backtrack(result, current + ")", open, close + 1, max);
    }
}
int main() {
    int n;
    cin >> n; // n=3
    vector<string> result;
    backtrack(result, "", 0, 0, n);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}