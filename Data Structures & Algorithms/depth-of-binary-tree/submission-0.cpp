/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int depth(TreeNode* rt) {
        if (rt == nullptr) return 0;

        int left = depth(rt->left) + 1;
        int right = depth(rt->right) + 1;

        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};
