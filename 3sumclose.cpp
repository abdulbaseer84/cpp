// Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; //n=4
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[-1,2,1,-4]
    }
    int target;
    cin >> target;// target=1
    sort(nums.begin(), nums.end());// nums=[-4,-1,1,2]
    int closest_sum = nums[0] + nums[1] + nums[2];// closest_sum=-4+(-1)+1=-4

    for (int i = 0; i < n - 2; i++) {// for(i=0; i<2; i++)
        int left = i + 1;// left=1
        int right = n - 1;// right=3

        while (left < right) {// while(1<3)
            int current_sum = nums[i] + nums[left] + nums[right];// current_sum=-4+(-1)+2=-3; current_sum=-4+1+2=-1
            if (abs(current_sum - target) < abs(closest_sum - target)) {// if(abs(-3-1)<abs(-4-1)) true; if(abs(-1-1)<abs(-4-1)) true
                closest_sum = current_sum;// closest_sum=-3; closest_sum=-1
            }

            if (current_sum < target) {// if(-3<1) true; if(-1<1) true
                left++;// left=2; left=3
            } else {
                right--;// right=2
            }
        }
    }

    cout << closest_sum << endl;// closest_sum=-1

    return 0;
}