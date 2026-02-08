// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 6
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:

// Input: nums = [-1,-2,-3]
// Output: -6
 

// Constraints:c

// 3 <= nums.length <= 104
// -1000 <= nums[i] <= 1000
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end()); // Sort the array to easily access the largest and smallest elements
    int maxProduct = max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                         nums[0] * nums[1] * nums[n - 1]);// Compare product of three largest and product of two smallest and the largest

    cout << "Maximum product of three numbers: " << maxProduct << endl;
    return 0;
}