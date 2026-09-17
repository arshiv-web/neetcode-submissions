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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        ans++;

        while(!q.empty()) {
            TreeNode* top = q.front().first;
            int cmax = q.front().second;
            if(top->left) {
                if(top->left->val >= cmax) ans++;
                q.push({top->left, max(top->left->val, cmax)});
            } 
            if(top->right) {
                if(top->right->val >= cmax) ans++;
                q.push({top->right, max(top->right->val, cmax)});
            } 
            q.pop();
        }
        return ans;
    }
};
