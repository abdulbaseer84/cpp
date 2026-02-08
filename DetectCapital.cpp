// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

 

// Example 1:

// Input: word = "USA"
// Output: true
// Example 2:

// Input: word = "FlaG"
// Output: false
 

// Constraints:

// 1 <= word.length <= 100
// word consists of lowercase and uppercase English letters.

#include <string>
#include <iostream>
using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    bool isAllUpper = true;
    bool isAllLower = true;

    for (char c : word) {
        if (isupper(c)) {
            isAllLower = false;
        } else {
            isAllUpper = false;
        }
    }

    if (isAllUpper || isAllLower || (isupper(word[0]) && !isupper(word[1]))) { // Check if all letters are uppercase, all are lowercase, or only the first letter is uppercase
        cout << "True" << endl; // The usage of capitals is right
    } else {
        cout << "False" << endl; // The usage of capitals is wrong
    }

    return 0;
}