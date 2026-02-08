// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit and add one
        for (int i = n - 1; i >= 0; --i) { // Traverse backwards
            if (digits[i] < 9) {            // No carry needed
                digits[i]++; // No carry needed
                return digits;
            }
            digits[i] = 0; // Set to 0 and carry over
        }
        
        // If all digits were 9, we need an extra digit at the front
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};

int main() {
    Solution solution;
    
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = solution.plusOne(digits1);
    cout << "Result after plus one: ";
    for (int digit : result1) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 2 4

    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = solution.plusOne(digits2);
    cout << "Result after plus one: ";
    for (int digit : result2) {
        cout << digit << " ";
    }
    cout << endl; // Output: 4 3 2 2

    vector<int> digits3 = {9, 9, 9};
    vector<int> result3 = solution.plusOne(digits3);
    cout << "Result after plus one: ";
    for (int digit : result3) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 0 0 0

    return 0;
}