// Find the Index of the First Occurrence in a String

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        if (needle.empty()) {
            return 0; // Edge case: empty needle
        }

        int haystackLength = haystack.size();
        int needleLength = needle.size();

        for (int i = 0; i <= haystackLength - needleLength; ++i) {
            int j = 0;
            while (j < needleLength && haystack[i + j] == needle[j]) { // Check for match
                j++;
            }
            if (j == needleLength) {
                return i; // Found the first occurrence
            }
        }
        return -1; // Needle not found
    }
};
int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    int index = solution.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl; // Output: 2

    haystack = "aaaaa";
    needle = "bba";
    index = solution.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl; // Output: -1

    haystack = "";
    needle = "";
    index = solution.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl; // Output: 0

    return 0;
}