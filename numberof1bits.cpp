// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

 

// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

// Example 2:

// Input: n = 128

// Output: 1

// Explanation:

// The input binary string 10000000 has a total of one set bit.

// Example 3:

// Input: n = 2147483645

// Output: 30

// Explanation:

// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 

// Constraints:

// 1 <= n <= 231 - 1

#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0; // Initialize count of set bits
        while (n) { // Loop until n becomes 0
            count += n & 1; // Increment count if the least significant bit is 1
            n >>= 1; // Right shift n to process the next bit
        }
        return count; // Return the total count of set bits
    }
};

int main() {
    Solution solution;
    int n1 = 11;
    int n2 = 128;
    int n3 = 2147483645;

    cout << "Number of set bits in " << n1 << ": " << solution.hammingWeight(n1) << endl; // Output: 3
    cout << "Number of set bits in " << n2 << ": " << solution.hammingWeight(n2) << endl; // Output: 1
    cout << "Number of set bits in " << n3 << ": " << solution.hammingWeight(n3) << endl; // Output: 30

    return 0;
}
