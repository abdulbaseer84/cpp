// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 1 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string digits;
    cin >> digits; //digits="23"
    if (digits.empty()) {
        cout << "[]" << endl;
        return 0;
    }

    vector<string> digitToLetters = {
        "",     "",     "abc",  "def",  // 0, 1, 2, 3
        "ghi",  "jkl",  "mno",  "pqrs", // 4, 5, 6, 7
        "tuv",  "wxyz"              // 8, 9
    };

    vector<string> result = {""};

    for (char digit : digits) {// digit='2'; digit='3'
        string letters = digitToLetters[digit - '0'];// letters="abc"; letters="def"
        vector<string> temp;

        for (const string& combination : result) {// combination=""
            for (char letter : letters) {// letter='a'; letter='b'; letter='c'
                temp.push_back(combination + letter);// temp=["a"]; temp=["a","b"]; temp=["a","b","c"]
            }
        }

        result = temp;// result=["a","b","c"]; result=["ad","ae","af","bd","be","bf","cd","ce","cf"]
    }

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}