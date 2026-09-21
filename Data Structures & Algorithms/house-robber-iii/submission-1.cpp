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
    int rob(TreeNode* root, int state,vector<unordered_map<TreeNode*, int>> &mp){
        if(root == NULL) return 0;
        int op1 = 0;
        int op2 = 0;
        if(mp[state].count(root)) return mp[state][root];
        if(state == 0){
            op1 = root->val + rob(root->left, 1, mp) + rob(root->right, 1, mp);
        }
        op2 = rob(root->left, 0, mp) + rob(root->right, 0, mp);
        return mp[state][root] = max(op1, op2);
    }

    int rob(TreeNode* root) {
        vector<unordered_map<TreeNode*, int>> mp(2);
        return rob(root, 0, mp);
    }
};