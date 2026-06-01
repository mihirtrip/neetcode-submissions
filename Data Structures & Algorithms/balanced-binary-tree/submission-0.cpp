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
    bool ans = true;
    int check(TreeNode* root){
        if(!root) return 0;


        int lheight = check(root->left);
        int rheight = check(root->right);

        int diff = abs(lheight - rheight);
        if(diff>1) ans = false;
        return 1 + max(lheight, rheight);
    }
    bool isBalanced(TreeNode* root) {
        check(root);
        return ans;
    }
};
