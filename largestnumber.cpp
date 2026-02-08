// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

//without complex code i want with best time complexity and space complexity
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n; //n=5
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=["3","30","34","5","9"]
    }

    sort(nums.begin(), nums.end(), [](const string& a, const string& b) { 
        return a + b > b + a;
    });

    if (nums[0] == "0") {
        cout << "0" << endl;
        return 0;
    }

    string result;
    for (const string& num : nums) {
        result += num;// result="9534330"
    }

    cout << result << endl;// output: 9534330

    return 0;
}

//n=5
//nums=["3","30","34","5","9"]
//sort(nums.begin(), nums.end(), [](const string& a, const string& b) { return a + b > b + a; }) nums=["9","5","34","3","30"]
//result=
