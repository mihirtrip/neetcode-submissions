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
    int count(TreeNode* root, int maxsofar){
        if (!root) return 0;
        int good = 0;
        if(root->val>=maxsofar){
            good++;
        }
        maxsofar = max(root->val, maxsofar);

        return good+count(root->left, maxsofar)+count(root->right, maxsofar);
    }
    int goodNodes(TreeNode* root) {
        return count(root, root->val);
    }
};
