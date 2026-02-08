// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

 

// Example 1:


// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:


// Input: root = [4,9,0,5,1]
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int total_sum = 0;
    vector<pair<TreeNode*, int>> stack = {{root, root->val}};

    while (!stack.empty()) {
        pair<TreeNode*, int> current = stack.back();
        stack.pop_back();
        TreeNode* node = current.first;
        int current_sum = current.second;

        if (!node->left && !node->right) {
            total_sum += current_sum;
        }

        if (node->right) {
            stack.push_back({node->right, current_sum * 10 + node->right->val});
        }
        if (node->left) {
            stack.push_back({node->left, current_sum * 10 + node->left->val});
        }
    }

    return total_sum;
}
int main() {

    TreeNode* root ;
    int n; //n=5
    cin >> n;
    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;// val=4; val=9; val=0; val=5; val=1
        nodes[i] = new TreeNode(val);// nodes=[TreeNode(4), TreeNode(9), TreeNode(0), TreeNode(5), TreeNode(1)]
    }
    for (int i = 0; i < n; i++) {
        int left_index, right_index;
        cin >> left_index >> right_index;// left_index=1, right_index=2; left_index=3, right_index=4; left_index=-1, right_index=-1; left_index=-1, right_index=-1; left_index=-1, right_index=-1
        if (left_index != -1) {
            nodes[i]->left = nodes[left_index];// nodes[0]->left=nodes[1]; nodes[1]->left=nodes[3];
        }
        if (right_index != -1) {
            nodes[i]->right = nodes[right_index];// nodes[0]->right=nodes[2]; nodes[1]->right=nodes[4];
        }
    }
    int result = sumNumbers(nodes[0]);
    cout << result << endl;
}

//n=5
//nodes=[TreeNode(4), TreeNode(9), TreeNode(0), TreeNode(5), TreeNode(1)]
//nodes[0]->left=nodes[1]   
//nodes[0]->right=nodes[2]
//nodes[1]->left=nodes[3]
//nodes[1]->right=nodes[4]
//stack=[{TreeNode(4), 4}]
//current={TreeNode(4), 4}
//node=TreeNode(4)
//current_sum=4

