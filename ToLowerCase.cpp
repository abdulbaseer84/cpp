// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
// Constraints:

// 1 <= s.length <= 100
// s consists of printable ASCII characters.

#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    cout << s << endl;
    return 0;
}
