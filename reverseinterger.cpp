// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x; //x=154 
    long reversed = 0;
    int sign = x < 0 ? -1 : 1;// x=154<0? -1:1 =>1
    x = abs(x);//  x=154

    while (x != 0) {
        int digit = x % 10; // digit=4
        reversed = reversed * 10 + digit;// reversed=0*10+4=4; reversed=4*10+5=45; reversed=45*10+1=451
        x /= 10;// x=15; x=1; x=0
    }

    reversed *= sign;// reversed=451*1=451

    if (reversed < INT32_MIN || reversed > INT32_MAX) {// if(451< -2147483648 || 451>2147483647) false
        cout << 0 << endl;
    } else {
        cout << reversed << endl;//451
    }

    return 0;
}

