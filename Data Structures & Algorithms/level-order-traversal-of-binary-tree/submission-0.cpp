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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();
            while (size) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
                temp.push_back(front->val);
                size--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
