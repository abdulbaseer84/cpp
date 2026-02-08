// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.

 

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
// Example 2:

// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

//without complex code i want
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; //n=4
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[3,6,9,1]
    }
    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }

    sort(nums.begin(), nums.end());// nums=[1,3,6,9]
    int max_gap = 0;

    for (int i = 1; i < n; i++) { // for(i=1; i<4; i++)
        max_gap = max(max_gap, nums[i] - nums[i - 1]);
    }

    cout << max_gap << endl;// output: 3

    return 0;
}


//do with n=6  
//nums=[1,10,5,3,8,2]
//sort(nums.begin(), nums.end()) nums=[1,2,3,5,8,10]
//max_gap=0
//i=1 max_gap=max(0,2-1)=1
//i=2 max_gap=max(1,3-2)=1
//i=3 max_gap=max(1,5-3)=2
//i=4 max_gap=max(2,8-5)=3
//i=5 max_gap=max(3,10-8)=3
//output: 3