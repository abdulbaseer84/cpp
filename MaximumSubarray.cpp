// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; //n=9
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[-2,1,-3,4,-1,2,1,-5,4]
    }
    int max_sum = nums[0]; // max_sum=-2
    int current_sum = nums[0]; // current_sum=-2

    for (int i = 1; i < n; i++) { // for(i=1; i<9; i++)
        current_sum = max(nums[i], current_sum + nums[i]);// current_sum=max(1,-2+1)=1; current_sum=max(-3,1-3)=-2; current_sum=max(4,-2+4)=4; current_sum=max(-1,4-1)=4; current_sum=max(2,4+2)=6; current_sum=max(1,6+1)=7; current_sum=max(-5,7-5)=7; current_sum=max(4,7+4)=11
        max_sum = max(max_sum, current_sum);// max_sum=max(-2,1)=1; max_sum=max(1,-2)=1; max_sum=max(1,4)=4; max_sum=max(4,4)=4; max_sum=max(4,6)=6; max_sum=max(6,7)=7; max_sum=max(7,7)=7; max_sum=max(7,11)=11
    }

    cout << max_sum << endl;// output: 11

    return 0;
}