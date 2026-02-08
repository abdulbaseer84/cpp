// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; //n=3
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[1,2,3]
    }
    vector<vector<int>> result = {{}};

    for (int num : nums) { // num=1; num=2; num=3
        int size = result.size(); // size=1; size=2; size=4
        for (int i = 0; i < size; i++) {// for(i=0; i<1; i++);
            vector<int> subset = result[i]; // subset=[]
            subset.push_back(num); // subset=[1];
            result.push_back(subset); // result=[[],[1]]
        }
    }

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;// output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    return 0;
}

//n=3
//nums=[1,2,3]
//result=[[]]
//num=1
//size=1
//i=0
//subset=[]
//subset=[1]
//result=[[],[1]]
//num=2
//size=2
//i=0
//subset=[]
//subset=[2]
//result=[[],[1],[2]]
