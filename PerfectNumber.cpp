// A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

// Given an integer n, return true if n is a perfect number, otherwise return false.

 

// Example 1:

// Input: num = 28
// Output: true
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, and 14 are all divisors of 28.
// Example 2:

// Input: num = 7
// Output: false
 

// Constraints:

// 1 <= num <= 10^8

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1) {
        cout << "False" << endl;
        return 0;
    }

    int sum = 1; // Start with 1, which is a divisor of every number
    for (int i = 2; i <= num / 2; ++i) { // Check for divisors from 2 to num/2
        if (num % i == 0) { // If i is a divisor of num 
            sum += i; // Add the divisor to the sum
        }
    }

    if (sum == num) {
        cout << "True" << endl; // It's a perfect number
    } else {
        cout << "False" << endl; // Not a perfect number
    }

    return 0;
}

//process:
//1. Take input from the user for the number to check.
//2. Check if the number is less than or equal to 1. If it is
//   return false, as perfect numbers are positive integers greater than 1.
//3. Initialize a variable sum to 1, since 1 is a divisor of every
//   number.
//4. Loop through potential divisors from 2 to num/2. For each divisor
//   that divides num evenly, add it to the sum.
//5. After the loop, compare the sum of the divisors to num. If they
//   are equal, print "True" indicating that num is a perfect number.
//   Otherwise, print "False".
//6. Return 0 to indicate that the program ended successfully.

//n=28
//sum=1+2+4+7+14=28
//n=7
//sum=1
//n=52
//sum=1+2+4+13+26=46
//n=496
//sum=1+2+4+8+16+31+62+124+248=496