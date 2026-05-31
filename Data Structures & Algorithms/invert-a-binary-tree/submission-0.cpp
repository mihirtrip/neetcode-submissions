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
    void traverse(TreeNode* &temp){
        if(temp==nullptr){
            return;
        }

        TreeNode* tempo = temp->left;
        temp->left = temp->right;
        temp->right = tempo;

        traverse(temp->left);
        traverse(temp->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp = root;
        traverse(temp);
        return root;
    }
};
