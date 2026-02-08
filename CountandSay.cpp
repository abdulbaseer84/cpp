// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

// Given a positive integer n, return the nth element of the count-and-say sequence.

 

// Example 1:

// Input: n = 4

// Output: "1211"

// Explanation:

// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"
// Example 2:

// Input: n = 1

// Output: "1"

// Explanation:

// This is the base case.

 

// Constraints:

// 1 <= n <= 30
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n; //n=6
    string result = "1"; // countAndSay(1) = "1"

    for (int i = 2; i <= n; i++) { // for(i=2; i<=6; i++)
        string current = "";
        int count = 1;

        for (int j = 1; j < result.size(); j++) { // for(j=1; j<1; j++)
            if (result[j] == result[j - 1]) { // if(result[1]==result[0]) false
                count++; // count=2
            } else {
                current += to_string(count) + result[j - 1]; // current="11"
                count = 1; // count=1
            }
        }

        current += to_string(count) + result.back(); // current="11" + "1" => current="111"
        result = current; // result="111"
    }

    cout << result << endl; // output: "1211"

    return 0;
}

// n=12
// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"
// countAndSay(5) = RLE of "1211" = "111221
// countAndSay(6) = RLE of "111221" = "312211"
// countAndSay(7) = RLE of "312211" = "13112221"
// countAndSay(8) = RLE of "13112221" = "1113213211"
// countAndSay(9) = RLE of "1113213211" = "31131211131221"
// countAndSay(10) = RLE of "31131211131221" = "13211311123113112211"
// countAndSay(11) = RLE of "13211311123113112211" = "11131221133112132113212221"
// countAndSay(12) = RLE of "11131221133112132113212221" = "3113112221232112111312211312113211"