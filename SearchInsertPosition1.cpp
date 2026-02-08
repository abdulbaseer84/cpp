// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left; // left is the insertion point
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int index = solution.searchInsert(nums, target);
    
    cout << "Index of target " << target << ": " << index << endl; // Output: 2
    
    target = 2;
    index = solution.searchInsert(nums, target);
    cout << "Index to insert target " << target << ": " << index << endl; // Output: 1
    
    target = 7;
    index = solution.searchInsert(nums, target);
    cout << "Index to insert target " << target << ": " << index << endl; // Output: 4
    
    target = 0;
    index = solution.searchInsert(nums, target);
    cout << "Index to insert target " << target << ": " << index << endl; // Output: 0
    
    return 0;
}