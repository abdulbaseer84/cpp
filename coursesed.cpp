// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

//without complex code i want with best time complexity and space complexity 
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack, int node) {
    if (recStack[node]) return true; // If the node is in the recursion stack, we have a cycle
    if (visited[node]) return false; // If the node has already been visited, skip it

    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (dfs(graph, visited, recStack, neighbor)) {
            return true; // If a cycle is detected in the DFS, return true
        }
    }

    recStack[node] = false; // Remove the node from the recursion stack
    return false; // No cycle detected
}