// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

// Example 1:

// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Example 2:

// Input: s = "abcd", k = 2
// Output: "bacd"
 

// Constraints:

// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 104

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s;
    int k;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the integer k: ";
    cin >> k;

    for (int i = 0; i < s.length(); i += 2 * k) { // reverse first k characters in every 2k block
        int left = i;
        int right = min(i + k - 1, (int)s.length() - 1);// ensure we don't go out of bounds 
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    cout << "Reversed string: " << s << endl;
    return 0;
}