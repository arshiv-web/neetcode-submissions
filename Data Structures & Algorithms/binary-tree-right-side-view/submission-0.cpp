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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> tq;
        if(!root) return ans;
        tq.push(root);
        while(!tq.empty()) {
            int ls = tq.size();
            int temp;
            for(int i = 0; i < ls; i++) {
                TreeNode* cand = tq.front();
                tq.pop();
                temp = cand->val;
                if(cand->left) tq.push(cand->left);
                if(cand->right) tq.push(cand->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
