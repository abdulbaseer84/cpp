// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         string result;
        
//         while (columnNumber > 0) {
//             columnNumber--; // Decrement to make it 0-indexed
//             char currentChar = 'A' + (columnNumber % 26); // Get the current character
//             result = currentChar + result; // Prepend the character to the result
//             columnNumber /= 26; // Move to the next character
//         }
        
//         return result;
//     }
// };

// int main() {
//     Solution solution;
//     int columnNumber1 = 1;
//     int columnNumber2 = 28;
//     int columnNumber3 = 701;
    
//     cout << "Column title for " << columnNumber1 << ": " << solution.convertToTitle(columnNumber1) << endl; // Output: "A"
//     cout << "Column title for " << columnNumber2 << ": " << solution.convertToTitle(columnNumber2) << endl; // Output: "AB"
//     cout << "Column title for " << columnNumber3 << ": " << solution.convertToTitle(columnNumber3) << endl; // Output: "ZY"
    
//     return 0;
// }
    

int main() {

    int columnNumber;
    cin >> columnNumber;

    string result = "";

    while (columnNumber > 0) {
        columnNumber--;                          // convert to 0-index
        char currentChar = 'A' + (columnNumber % 26);
        result = currentChar + result;           // add in front
        columnNumber /= 26;
    }

    cout << result;      // PRINT, not return

    return 0;
}