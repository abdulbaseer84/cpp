//. Longest Substring Without Repeating Characters with best time complexity and space complexity
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(const string s) {
    unordered_set<char> charSet;
    int left = 0, right = 0, maxLength = 0;

    while (right < s.length()) {
        if (charSet.find(s[right]) == charSet.end()) {
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            charSet.erase(s[left]);
            left++;
        }
    }

    return maxLength;
}   
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}   
