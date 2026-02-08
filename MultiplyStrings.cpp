// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
 

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
#include <iostream>
#include <string>
using namespace std;
int main() {   
    string num1, num2;
    cin >> num1 >> num2; // num1="123", num2="456"
    int m = num1.size(), n = num2.size();
    string result(m + n, '0'); // result="000000"

    for (int i = m - 1; i >= 0; i--) { // for(i=2; i>=0; i--)
        for (int j = n - 1; j >= 0; j--) { // for(j=2; j>=0; j--)
            int mul = (num1[i] - '0') * (num2[j] - '0'); // mul=(3-0)*(6-0)=18; mul=(3-0)*(5-0)=15; mul=(3-0)*(4-0)=12; mul=(2-0)*(6-0)=12; mul=(2-0)*(5-0)=10; mul=(2-0)*(4-0)=8; mul=(1-0)*(6-0)=6; mul=(1-0)*(5-0)=5; mul=(1-0)*(4-0)=4
            int sum = (result[i + j + 1] - '0') + mul;// sum=(0)+18=18; sum=(1)+15=16; sum=(2)+12=14; sum=(0)+12=12; sum=(1)+10=11; sum=(2)+8=10; sum=(0)+6=6; sum=(0)+5=5; sum=(0)+4=4
            result[i + j + 1] = (sum % 10) + '0'; 
            result[i + j] += sum / 10; 
        }
    }
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }
    if (start == result.size()) {
        cout << "0" << endl;
    } else {
        cout << result.substr(start) << endl;
    }  
    return 0;
}