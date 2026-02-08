// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
 

// Constraints:

// 1 <= k <= nums.length <= 1053
// -104 <= nums[i] <= 104

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap

    for (int i = 0; i < n; i++) {
        pq.push(nums[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    cout << "Kth largest element: " << pq.top();
    return 0;
}
