// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;
int main() {
    int m, n;
    cin >> m >> n; // m=3, n=4
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; // board=[['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
        }
    }
    string word;
    cin >> word; // word="ABCCED"
    vector<vector<bool>> visited(m, vector<bool>(n, false)); // visited=[[false,false,false,false],[false,false,false,false],[false,false,false,false]]

    function<bool(int, int, int)> backtrack = [&](int row, int col, int index) { // backtrack(0, 0, 0)
        if (index == word.size()) return true; // if(0==6) false

        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true; // visited=[[true,false,false,false],[false,false,false,false],[false,false,false,false]]
        bool found = backtrack(row + 1, col, index + 1) || // backtrack(1, 0, 1)
                     backtrack(row - 1, col, index + 1) || // backtrack(-1, 0, 1)
                     backtrack(row, col + 1, index + 1) || // backtrack(0, 1, 1)
                     backtrack(row, col - 1, index + 1);   // backtrack(0, -1, 1)
        visited[row][col] = false; // visited=[[false,false,false,false],[false,false,false,false],[false,false,false,false]]
        return found;
    };

    bool result = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (backtrack(i, j, 0)) { // backtrack(0, 0, 0)
                result = true;
                break;
            }
        }
        if (result) break;
    }
    cout << (result ? "true" : "false") << endl; // output: true
    return 0;
}
