// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

 

// Example 1:

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

// Constraints:

// 1 <= num < 231
 
#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    int mask = 1;
    while (mask <= num) {
        mask = mask << 1;// left shift by 1 to create a mask with all bits 1 just greater than num 
        // e.g., if num = 5 (101 in binary), mask will be 8 (1000 in binary)
        // if num = 1 (1 in binary), mask will be 2 (10 in binary)
        // if num = 10 (1010 in binary), mask will be 16 (10000 in binary)
        // and so on
    }
    mask = mask - 1;// subtract 1 to get all bits 1 just less than or equal to num
    // e.g., if mask = 8 (1000 in binary), mask - 1 = 7 (111 in binary)
    // if mask = 2 (10 in binary), mask - 1 = 1 (1 in binary)
    // if mask = 16 (10000 in binary), mask - 1 = 15 (1111 in binary)
    // and so on
    int complement = num ^ mask; // XOR num with mask to get the complement 
    // e.g., if num = 5 (101 in binary) and mask = 7 (111 in binary), complement = 2 (010 in binary)
    // if num = 1 (1 in binary) and mask = 1 (1 in binary), complement = 0 (0 in binary)
    // if num = 10 (1010 in binary) and mask = 15 (1111 in binary), complement = 5 (0101 in binary)
    // and so on
    cout << complement << endl;
}