// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; //n=6
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[5,7,7,8,8,10]
    }
    int target;
    cin >> target;// target=8

    int left = 0;// left=0
    int right = n - 1;// right=5
    int first_occurrence = -1;

    while (left <= right) {// while(0<=5)
        int mid = left + (right - left) / 2;// 0+ (5-0)/2=2; 3+(5-3)/2=4
        if (nums[mid] == target) {// if(nums[2]==8) false
            first_occurrence = mid;// first_occurrence=2
            right = mid - 1;// right=1
        } else if (nums[mid] < target) {// else if(nums[2]<8) true
            left = mid + 1;// left=3
        } else {
            right = mid - 1;// right=1
        }
    }

    if (first_occurrence == -1) {
        cout << "[-1,-1]" << endl;
        return 0;
    }

    left = 0;// left=0
    right = n - 1;// right=5
    int last_occurrence = -1;

    while (left <= right) {// while(0<=5)
        int mid = left + (right - left) / 2;// mid=2
        if (nums[mid] == target) {// if(nums[2]==8) false; if(nums[3]==8) true
            last_occurrence = mid;// last_occurrence=3
            left = mid + 1;// left=4
        } else if (nums[mid] < target) {// else if(nums[2]<8) true; else if(nums[3]<8) false
            left = mid + 1;// left=3; left=4
        } else {
            right = mid - 1;// right=1; right=2
        }
    }

    cout << "[" << first_occurrence << "," << last_occurrence << "]" << endl;// output: [3,4]

    return 0;
}