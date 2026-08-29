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
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> tq;
        tq.push(root);
        while(!tq.empty()) {
            vector<int> temp;
            int levelSize = tq.size();
            for(int i = 0; i < levelSize; i++) {
                TreeNode* tp = tq.front();
                temp.push_back(tp->val);
                if(tp->left) tq.push(tp->left);
                if(tp->right) tq.push(tp->right);
                tq.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
