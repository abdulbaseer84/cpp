// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each element in nums appears exactly three times except for one element which appears once.
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; //n=7
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[0,1,0,1,0,1,99]
    }
    int result = 0;

    for (int i = 0; i < 32; i++) { // for(i=0; i<32; i++) why 32 taken can be n?
        int bit_count = 0;// bit_count=0
        for (int num : nums) { // num=0; num=1; num=0; num=1; num=0; num=1; num=99
            if ((num >> i) & 1) { // if((0>>0)&1) false; if((1>>0)&1) true; if((0>>0)&1) false; if((1>>0)&1) true; if((0>>0)&1) false; if((1>>0)&1) true; if((99>>0)&1) true;
                bit_count++;// bit_count=3
            }
        }
        if (bit_count % 3 != 0) { // if(3%3!=0) false;
            result |= (1 << i); // result=result|(1<<i)
        }
    }

    cout << result << endl;// output: 99

    return 0;
}