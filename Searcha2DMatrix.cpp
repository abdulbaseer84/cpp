//     You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n; // m=3, n=4
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j]; // matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
        }
    }
    int target;
    cin >> target; // target=3
    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / n][mid % n]; // mid_value=matrix[1][0]=10

        if (mid_value == target) {
            cout << "true" << endl;
            return 0;
        } else if (mid_value < target) {
            left = mid + 1; // left=2
        } else {
            right = mid - 1; // right=-1
        }
    }

    cout << "false" << endl; // output: true

    return 0;
}