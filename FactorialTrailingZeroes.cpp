// Given an integer n, return the number of trailing zeroes in n!.

// Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

// Example 1:

// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Example 3:

// Input: n = 0
// Output: 0
 

// Constraints:

// 0 <= n <= 104
 

// Follow up: Could you write a solution that works in logarithmic time complexity?

//give open code
#include <iostream>
using namespace std;
int main() {
    int n; //n=5
    cin >> n;
    int count = 0;

    for (int i = 5; n / i >= 1; i *= 5) { // for(i=5; 5/5>=1; i*=5) true; for(i=25; 5/25>=1; i*=5) false //why i*=5 because we need to count the number of multiples of 5, 25, 125, etc. in n!
        count += n / i;// count=1
    }

    cout << count << endl;// output: 1

    return 0;
}