// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; //n=6
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[-1,0,1,2,-1,-4]
    }
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());// nums=[-4,-1,-1,0,1,2]

    for (int i = 0; i < n - 2; i++) {// for(i=0; i<4; i++)
        if (i > 0 && nums[i] == nums[i - 1]) continue;// if(i>0 && nums[i]==nums[i-1]) continue;

        int left = i + 1;// left=1
        int right = n - 1;// right=5

        while (left < right) {// while(1<5)
            int sum = nums[i] + nums[left] + nums[right];// sum=-4+(-1)+2=-3; sum=-4+(-1)+2=-3; sum=-4+0+2=-2; sum=-4+1+2=-1; sum=-4+2+2=0
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});// result=[[-4,-1,2]]
                while (left < right && nums[left] == nums[left + 1]) left++;// while(1<5 && nums[1]==nums[2]) left++; while(2<5 && nums[2]==nums[3]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;// while(2<5 && nums[5]==nums[4]) right--;
                left++;// left=3
                right--;// right=4
            } else if (sum < 0) {
                left++;// left=3
            } else {
                right--;// right=4
            }
        }
    }

    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }

    return 0;
}