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

    TreeNode* build(int &px, int l, int r, vector<int>& preorder, vector<int>& inorder){
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(preorder[px++]);
        int g = -1;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == root->val) {
                g = i; break;
            }
        }
        root->left = build(px, l, g-1, preorder, inorder);
        root->right = build(px, g + 1, r, preorder, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(idx, 0, inorder.size()-1, preorder, inorder);
    }
};
