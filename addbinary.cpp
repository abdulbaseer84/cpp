// Given two binary strings a and b, return their sum as a binary string.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(const string& a, const string& b) {
        string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        // Loop until both strings are processed or there is a carry
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Start with the carry

            if (i >= 0) {
                sum += a[i] - '0'; // Add bit from a
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Add bit from b
                j--;
            }

            result.push_back((sum % 2) + '0'); // Append the binary digit
            carry = sum / 2; // Update carry
        }

        reverse(result.begin(), result.end()); // Reverse the result to get the correct order
        return result;
    }
};

int main() {
    Solution solution;
    string a = "11";
    string b = "1";
    string sum = solution.addBinary(a, b);
    cout << "Sum of " << a << " and " << b << " is: " << sum << endl; // Output: 100

    a = "1010";
    b = "1011";
    sum = solution.addBinary(a, b);
    cout << "Sum of " << a << " and " << b << " is: " << sum << endl; // Output: 10101

    return 0;
}