// You are given a string S consisting of lowercase latin letters, i.e. (a, b, c, ...z). The cost of a string is defined as the total number of distinct characters in it. You want to split S into two non-empty strings A and B, such that concatenation of A and B is equal to S. Let X be the maximum sum of cost of A and B. Find the value of (S) - X. Note: |S| denotes the length of string S Input Format The first line contains a string, S., denoting the given string.

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string S;
    cout << "Enter the string: ";
    cin >> S;

    unordered_set<char> distinctChars(S.begin(), S.end());
    int costS = distinctChars.size();

    int maxSumCost = 0;
    for (size_t i = 1; i < S.length(); ++i) {
        unordered_set<char> distinctA(S.begin(), S.begin() + i);
        unordered_set<char> distinctB(S.begin() + i, S.end());
        int costA = distinctA.size();
        int costB = distinctB.size();
        maxSumCost = max(maxSumCost, costA + costB);
    }

    int result = costS - maxSumCost;
    cout << "Result: " << result << endl;

    return 0;
}


// Example usage:
// Input: S = "abc"
// Output: 0
// Explanation: We can split S into A = "a" and B = "bc".
// The cost of A is 1 (distinct character 'a') and the cost of B is 2 (distinct characters 'b' and 'c').
// The maximum sum of cost of A and B is 1 + 2 = 3
// The cost of S is 3 (distinct characters 'a', 'b', and 'c').
// Therefore, the result is cost(S) - X = 3 - 3 = 0.
// Input: S = "aabb"
// Output: 1
// Explanation: We can split S into A = "aa" and B = "bb".
// The cost of A is 1 (distinct character 'a') and the cost of B
// is 1 (distinct character 'b').
// The maximum sum of cost of A and B is 1 + 1 = 2
// The cost of S is 2 (distinct characters 'a' and 'b').
// Therefore, the result is cost(S) - X = 2 - 2 = 0.
// Input: S = "abcde"
// Output: 0
// Explanation: We can split S into A = "abc" and B = "de".
// The cost of A is 3 (distinct characters 'a', 'b', and 'c') and the cost of B is 2 (distinct characters 'd' and 'e').
// The maximum sum of cost of A and B is 3 + 2 = 5
// The cost of S is 5 (distinct characters 'a', 'b', 'c', 'd', and 'e').
// Therefore, the result is cost(S) - X = 5 - 5 = 0.
// spac