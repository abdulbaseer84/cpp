// Largest Palindrome Product
// Hard
// Topics
// premium lock icon
// Companies
// Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.

 

// Example 1:

// Input: n = 2
// Output: 987
// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
// Example 2:

// Input: n = 1
// Output: 9
 

// Constraints:

// 1 <= n <= 8

#include <bits/stdc++.h>
using namespace std;

long long createPalindrome(long long left){
    string s = to_string(left);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return stoll(s + rev);
}

int main(){

    int n;
    cout<<"Enter n: ";
    cin>>n;

    if(n==1){
        cout<<"Answer: 9";
        return 0;
    }

    long long upper = pow(10,n) - 1;
    long long lower = pow(10,n-1);

    for(long long left = upper; left >= lower; left--){

        long long pal = createPalindrome(left);

        for(long long d = upper; d*d >= pal; d--){
            if(pal % d == 0){
                long long other = pal/d;

                if(other >= lower && other <= upper){
                    cout<<"Answer: "<< pal % 1337;
                    return 0;
                }
            }
        }
    }

    return 0;
}
