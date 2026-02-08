// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.
 

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

//give in simple way
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    getline(cin, s); // s="  hello world  "
    reverse(s.begin(), s.end()); // s="  dlrow olleh  "
    int start = 0, end = 0, n = s.size();
    string result;

    while (start < n) { // while(0<15)
        while (start < n && s[start] == ' ') 
        start++; // while(0<15 && s[0]==' ') start++; while(1<15 && s[1]==' ') start++;
        if (start >= n) 
        break; // if(2>=15) false
        end = start; // end=2

        while (end < n && s[end] != ' ') end++; // while(2<15 && s[2]!=' ') end++; while(3<15 && s[3]!=' ') end++; while(4<15 && s[4]!=' ') end++; while(5<15 && s[5]!=' ') end++;
        result += s.substr(start, end - start) + " "; // result="dlrow "
        start = end; // start=5
    }

    if (!result.empty()) result.pop_back(); // result="dlrow"
    cout << result << endl; // output: "world hello"

    return 0;
}