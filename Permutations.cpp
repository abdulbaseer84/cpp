// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.
#include <iostream>
#include <vector>
using namespace std;
void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& nums, vector<bool>& used) {//
    if (current.size() == nums.size()) {// if(current.size()==3)
        result.push_back(current);// result=[[1,2,3]]
        return;
    }

    for (int i = 0; i < nums.size(); i++) {// for(i=0; i<3; i++)
        if (used[i]) continue;//

        used[i] = true;
        current.push_back(nums[i]);//
        backtrack(result, current, nums, used);// backtrack(result, [1], nums, [true,false,false])
        current.pop_back();// current=[1,2]
        used[i] = false;// used=[true,true,false] 
    }
}  
int main() {
    int n; //n=3
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];// nums=[1,2,3]
    }
    vector<vector<int>> result;// result=[[]]
    vector<int> current;// current=[]
    vector<bool> used(n, false);// used=[false,false,false]
    backtrack(result, current, nums, used);

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
    cout << "]" << endl;

    return 0;
}
//n=3
//nums=[1,2,3]
//result=[[]]
//current=[]
//used=[false,false,false]
//backtrack(result, current, nums, used)
//backtrack(result, [1], nums, [true,false,false])
//backtrack(result, [1,2], nums, [true,true,false])
//backtrack(result, [1,2,3], nums, [true,true,true])
//result=[[1,2,3]]
//backtrack(result, [1,3], nums, [true,false,true])
//backtrack(result, [1,3,2], nums, [true,true,true])
//result=[[1,2,3],[1,3,2]]
//backtrack(result, [2], nums, [false,true,false])
//backtrack(result, [2,1], nums, [true,true,false])
//backtrack(result, [2,1,3], nums, [true,true,true])    
//result=[[1,2,3],[1,3,2],[2,1,3]]