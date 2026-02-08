// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.
 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"

// Output: true

// Explanation:

// The bijection can be established as:

// 'a' maps to "dog".
// 'b' maps to "cat".
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"

// Output: false

// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"

// Output: false

 

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

#include <iostream>
#include <sstream> 
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream iss(s); // Create a string stream to read words from the input string
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        if (pattern.length() != words.size()) { // If the number of pattern characters does not match the number of words, return false
            return false;
        }
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            const string w = words[i];
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};
int main() {
    Solution sol;
    string pattern, s;
    cout << "Enter the pattern: ";
    cin >> pattern;
    cin.ignore(); // To ignore the newline character after the pattern input
    cout << "Enter the string: ";
    getline(cin, s);
    if (sol.wordPattern(pattern, s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
