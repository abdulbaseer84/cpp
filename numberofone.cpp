// Number of Digit One
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0
 

// Constraints:

// 0 <= n <= 109
#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    cout<<"Enter n: ";
    cin>>n;

    long long count=0;

    for(long long factor=1; factor<=n; factor*=10){

        long long low = n % factor;
        long long current = (n / factor) % 10;
        long long high = n / (factor*10);

        if(current==0){
            count += high * factor;
        }
        else if(current==1){
            count += high * factor + (low + 1);
        }
        else{
            count += (high + 1) * factor;
        }
    }

    cout<<"Total number of digit '1': "<<count;
    return 0;
}