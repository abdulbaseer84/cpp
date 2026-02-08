// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
 

// Constraints:

// 0 <= n <= 5 * 106

//without complex code i want with best time complexity and space complexity without vector
#include <iostream>
using namespace std;
int main() {
    int n; //n=10
    cin >> n;
    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;
    bool is_prime;

    for (int i = 2; i < n; i++) { // for(i=2; i<10; i++)
        is_prime = true;

        for (int j = 2; j * j <= i; j++) { // for(j=2; j*j<=i; j++)
            if (i % j == 0) { // if(i%j==0) true for i=4,6,8,9
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            count++;// count=1 for i=2; count=2 for i=3; count=3 for i=5; count=4 for i=7
        }
    }

    cout << count << endl;// output: 4

    return 0;
}

