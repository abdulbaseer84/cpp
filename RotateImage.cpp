// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Example 2:


// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; //n=3
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));//
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];// matrix=[[1,2,3],[4,5,6],[7,8,9]]
        }
    }
    for (int i = 0; i < n / 2; i++) { // for(i=0; i<1; i++)
        for (int j = i; j < n - i - 1; j++) { // for(j=0; j<2; j++)
            int temp = matrix[i][j]; // temp=1
            matrix[i][j] = matrix[n - j - 1][i]; // matrix[0][0]=matrix[2][0]=7
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]; // matrix[2][0]=matrix[2][2]=9
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]; // matrix[2][2]=matrix[0][2]=3
            matrix[j][n - i - 1] = temp; // matrix[0][2]=temp=1
        }
    }
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";// output: 7 4 1 8 5 2 9 6 3
        }
        cout << endl;
    }
    return 0;
}
