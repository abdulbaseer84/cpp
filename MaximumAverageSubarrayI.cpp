// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000
 

// Constraints:

// n == nums.length
// 1 <= k <= n <= 105
// -104 <= nums[i] <= 104

#include <vector>
#include <iostream>

using namespace std;

int main() {

    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    double max_avg = -1e5; // Initialize to a very small number
    double current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }
    max_avg = current_sum / k;
    for (int i = k; i < n; i++) {
        current_sum += nums[i] - nums[i - k]; // Slide the window
        max_avg = max(max_avg, current_sum / k);// Update max average if current average is greater
    }
    cout << "Maximum average subarray of length " << k << " is: " << max_avg << endl;
    return 0;
}
