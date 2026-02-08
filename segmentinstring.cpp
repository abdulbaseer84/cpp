// Given a string s, return the number of segments in the string.

// A segment is defined to be a contiguous sequence of non-space characters.

 

// Example 1:

// Input: s = "Hello, my name is John"
// Output: 5
// Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
// Example 2:

// Input: s = "Hello"
// Output: 1
 

// Constraints:

// 0 <= s.length <= 300
// s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
// The only space character in s is ' '.
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool inSegment = false;
        for (char c : s) {
            if (c != ' ') {// If the character is not a space
                if (!inSegment) {// Start of a new segment
                    count++;// Increment segment count
                    inSegment = true;   
                }
            } else {
                inSegment = false;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);// Use getline to read the entire line including spaces
    int segmentCount = sol.countSegments(s);
    cout << "Number of segments: " << segmentCount << endl;
    return 0;
}