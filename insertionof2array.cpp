// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end()); // Create a set from the first array for O(1) lookups
        unordered_set<int> resultSet; // Set to store unique intersection elements
        for (int num : nums2) {
            if (set.count(num)) { // If the number is in the first set, add it to the result set
                resultSet.insert(num);
            }
        }
        return vector<int>(resultSet.begin(), resultSet.end()); // Convert the result set back to a vector
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;
    int n1, n2, input;
    cout << "Enter the number of elements in the first array: ";
    cin >> n1;
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> input;
        nums1.push_back(input);
    }   
    cout << "Enter the number of elements in the second array: ";
    cin >> n2;
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> input;
        nums2.push_back(input);
    }
    vector<int> result = sol.intersection(nums1, nums2);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}