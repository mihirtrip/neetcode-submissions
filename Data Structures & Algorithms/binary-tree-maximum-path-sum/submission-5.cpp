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
    int ans = INT_MIN;
    int traverse(TreeNode* root){
        if(!root) return 0;

        int left_sum =max(0, traverse(root->left));
        int right_sum =max(0, traverse(root->right));

        ans = max(ans, left_sum + right_sum + root->val);

        return root->val + max(left_sum, right_sum);

    }
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;

    }
};
