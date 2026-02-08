// Reverse bits of a given 32 bits signed integer.

 

// Example 1:

// Input: n = 43261596

// Output: 964176192

// Explanation:

// Integer	Binary
// 43261596	00000010100101000001111010011100
// 964176192	00111001011110000010100101000000
// Example 2:

// Input: n = 2147483644

// Output: 1073741822

// Explanation:

// Integer	Binary
// 2147483644	01111111111111111111111111111100
// 1073741822	00111111111111111111111111111110
 

// Constraints:

// 0 <= n <= 231 - 2
// n is even.

#include <iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int result = 0; // Initialize result to store the reversed bits
        for (int i = 0; i < 32; i++) { // Loop through all 32 bits
            result <<= 1; // Shift result left by 1 to make room for the next bit
            result |= (n & 1); // Add the least significant bit of n to result
            n >>= 1; // Shift n right by 1 to process the next bit
        }
        return result; // Return the reversed bits as an integer
    }
};

int main() {
    Solution solution;
    int n1 = 43261596;
    int n2 = 2147483644;

    cout << "Reversed bits of " << n1 << ": " << solution.reverseBits(n1) << endl; // Output: 964176192
    cout << "Reversed bits of " << n2 << ": " << solution.reverseBits(n2) << endl; // Output: 1073741822

    return 0;
}