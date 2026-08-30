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
    int find(TreeNode* root, TreeNode* p) {
        if(root == NULL) return 0;
        return root == p || find(root->left, p) || find(root->right, p);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        int checkPLeft = find(root->left, p);
        int checkQLeft = find(root->left, q);
        int checkPRight = find(root->right, p);
        int checkQRight = find(root->right, q);

        if(checkPLeft && checkQRight) return root;
        if(checkPRight && checkQLeft) return root;

        if(checkPLeft && checkQLeft) return lowestCommonAncestor(root->left, p, q);
        if(checkPRight && checkQRight) return lowestCommonAncestor(root->right, p, q);
    }
};
