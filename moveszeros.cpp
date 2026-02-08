// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
 

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0; // Position to place the next non-zero element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) { // If the current element is non-zero, place it at the last non-zero position
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        // Fill remaining positions with zeros
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {    // 
            nums[i] = 0;
        }
    }
};
int main() {
    Solution sol;
    vector<int> nums;
    int n, input;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }
    sol.moveZeroes(nums);
    cout << "Array after moving zeros: ";
    cout<<"[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}