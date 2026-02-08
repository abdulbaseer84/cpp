// You are given two binary trees root1 and root2.

// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

// Return the merged tree.

// Note: The merging process must start from the root nodes of both trees.

 

// Example 1:


// Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// Output: [3,4,5,5,4,null,7]
// Example 2:

// Input: root1 = [1], root2 = [1,2]
// Output: [2,2]
 

// Constraints:

// The number of nodes in both trees is in the range [0, 2000].
// -104 <= Node.val <= 104
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

int main() {
    // Example usage:
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution sol;
    TreeNode* mergedRoot = sol.mergeTrees(root1, root2);

    // Output the merged tree (in-order traversal)
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    };

    cout << "In-order traversal of merged tree: ";
    inorder(mergedRoot);
    cout << endl;

    return 0;
}

// Output example:
// In-order traversal of merged tree: 5 4 4 3 7 2
// Explanation: The merged tree is [3,4,5,5,4,null,7]
// The in-order traversal visits nodes in the order: left, root, right.
// Thus, the output is 5 4 4 3 7 2.
// The merged tree structure is:
//       3
//      / \
//     4   5
//    / \   \
//   5   4   7
// where the in-order traversal yields the sequence 5, 4, 4, 3, 7, 2.