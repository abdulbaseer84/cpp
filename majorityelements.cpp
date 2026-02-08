// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count; // Hash map to store the count of each element 
        for (int num : nums) {
            count[num]++;
            if (count[num] > nums.size() / 2) { // Check if the current element is the majority element
                return num;
            }
        }
        return -1; // This line will never be reached since the majority element always exists
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority element in nums1: " << solution.majorityElement(nums1) << endl; // Output: 3
    cout << "Majority element in nums2: " << solution.majorityElement(nums2) << endl; // Output: 2

    return 0;
}
