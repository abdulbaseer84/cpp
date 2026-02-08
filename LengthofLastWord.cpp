// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const string& s) {
        int length = 0;
        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution solution;
    string s = "Hello World";
    int length = solution.lengthOfLastWord(s);
    cout << "Length of last word: " << length << endl; // Output: 5

    s = "   fly me   to   the moon  ";
    length = solution.lengthOfLastWord(s);
    cout << "Length of last word: " << length << endl; // Output: 4

    s = "luffy is still joyboy";
    length = solution.lengthOfLastWord(s);
    cout << "Length of last word: " << length << endl; // Output: 6

    s = " ";
    length = solution.lengthOfLastWord(s);
    cout << "Length of last word: " << length << endl; // Output: 0

    return 0;
}