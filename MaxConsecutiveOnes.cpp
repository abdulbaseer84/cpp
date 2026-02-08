// Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) { // if the current element is 1
                            // increment the count of consecutive 1's
                            // update the maximum count if needed
            count++;        // increment count of consecutive 1's
            maxCount = max(maxCount, count);// update maxCount if current count is greater
                                            // e.g., if maxCount = 2 and count = 3, maxCount becomes 3
                                            // if maxCount = 4 and count = 2, maxCount remains 4
                                            // and so on
        } else {
            count = 0;
        }
    }
    cout << maxCount << endl;
}