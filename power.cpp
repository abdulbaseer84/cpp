// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104

#include <iostream>
using namespace std;

int main() {
    double x;
    int n;
    cin >> x >> n; // x=2.00000, n=10
    double result = 1.0;
    long long abs_n = abs(n); // abs_n=10

    while (abs_n > 0) {
        if (abs_n % 2 == 1) { // if(10%2==1) false; if(5%2==1) true; if(2%2==1) false; if(1%2==1) true
            result *= x; // result=1.0*2.0=2.0; result=8.0*2.0=16.0
        }
        x *= x; // x=4.0; x=16.0; x=256.0; x=65536.0
        abs_n /= 2; // abs_n=5; abs_n=2; abs_n=1; abs_n=0
    }

    if (n < 0) { // if(10<0) false
        result = 1.0 / result;
    }

    cout << result << endl; // output: 1024.00000

    return 0;
}