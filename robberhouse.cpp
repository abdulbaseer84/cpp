// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Edge cases
    if (n == 1) {
        cout << nums[0];
        return 0;
    }
    if (n == 2) {
        cout << max(nums[0], nums[1]);
        return 0;
    }

    // Case 1: Exclude last house
    int prev2 = 0, prev1 = 0;
    for (int i = 0; i < n - 1; i++) {
        int curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    int case1 = prev1;

    // Case 2: Exclude first house
    prev2 = 0;
    prev1 = 0;
    for (int i = 1; i < n; i++) {
        int curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    int case2 = prev1;

    cout << "Maximum money that can be robbed: " << max(case1, case2);

    return 0;
}
