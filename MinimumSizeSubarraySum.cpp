// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

//without complex code i want with best time complexity and space complexity
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int target; //target=7
    cin >> target;
    int n; //n=6
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[2,3,1,2,4,3]
    }
    int left = 0;// left=0
    int sum = 0;// sum=0
    int min_length = n + 1;// min_length=7

    for (int right = 0; right < n; right++) { // for(right=0; right<6; right++)
        sum += nums[right];// sum=2; sum=5; sum=6; sum=8; sum=12; sum=15

        while (sum >= target) { // while(sum>=7) true for right=3,4,5
            min_length = min(min_length, right - left + 1);// min_length=min(7,3-0+1)=4; 
            sum -= nums[left];// sum=8-2=6; sum=12-3=9; sum=15-1=14
            left++;// left=1; left=2; left=3
        }
    }

    cout << (min_length == n + 1 ? 0 : min_length) << endl;// output: 2

    return 0;
}

//target=7
//n=6
//nums=[2,3,1,2,4,3]
//left=0
//sum=0
//min_length=7
//right=0 sum=2
//right=1 sum=5
//right=2 sum=6
//right=3 sum=8 while(sum>=7) true min_length=min(7,3-0+1)=4 sum=8-2=6 left=1
//right=4 sum=12 while(sum>=7) true min_length=min(4,4-1+1)=4 sum=12-3=9 left=2
//right=5 sum=15 while(sum>=7) true min_length=min(4,5-2+1)=4 sum=15-1=14 left=3
// while(sum>=7) true min_length=min(4,5-3+1)=2 sum=14-2=12 left=4
// while(sum>=7) true min_length=min(2,5-4+1)=2 sum=12-4=8 left=5
// while(sum>=7) true min_length=min(2,5-5+1)=1 sum=8-3=5 left=6
// output: 2
