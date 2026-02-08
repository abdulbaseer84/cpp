// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:
// Input: nums = [1,0,1,2]
// Output: 3
// Constraints:
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
    int n; //n=6
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[100,4,200,1,3,2]
    }
    unordered_set<int> num_set(nums.begin(), nums.end());// num_set={100,4,200,1,3,2}
    int longest_streak = 0;

    for (int num : num_set) { // num=100; num=4; num=200; num=1; num=3; num=2
        if (!num_set.count(num - 1)) { // if(!num_set.count(99)) true; if(!num_set.count(3)) false; if(!num_set.count(199)) true; if(!num_set.count(0)) true; if(!num_set.count(2)) false; if(!num_set.count(1)) false
            int current_num = num;// current_num=100
            int current_streak = 1;// current_streak=1

            while (num_set.count(current_num + 1)) { // while(num_set.count(101)) false
                current_num++;// current_num=101
                current_streak++;// current_streak=2
            }

            longest_streak = max(longest_streak, current_streak);// longest_streak=max(0,1)=1
        }
    }

    cout << longest_streak << endl;// output: 4

    return 0;
}

//n=6
//nums=[100,4,200,1,3,2]
//num_set={100,4,200,1,3,2}
//num=100
//current_num=100
//current_streak=1
//while(num_set.count(101)) false
//longest_streak=max(0,1)=1
//num=4
//current_num=4
//current_streak=1
//while(num_set.count(5)) false
//longest_streak=max(1,1)=1
//num=200
//current_num=200
//current_streak=1
//while(num_set.count(201)) false
//longest_streak=max(1,1)=1
//num=1
//current_num=1
//current_streak=1

