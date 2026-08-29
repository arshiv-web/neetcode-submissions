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
    struct Info {
        int minVal;
        int maxVal;
        bool valid;
    };

    Info check(TreeNode* root) {
        if (root == nullptr)
            return {INT_MAX, INT_MIN, true};

        Info left = check(root->left);
        Info right = check(root->right);

        bool valid = left.valid &&
                     right.valid &&
                     left.maxVal < root->val &&
                     root->val < right.minVal;

        int minVal = min(root->val, min(left.minVal, right.minVal));
        int maxVal = max(root->val, max(left.maxVal, right.maxVal));

        return {minVal, maxVal, valid};
    }

    bool isValidBST(TreeNode* root) {
        return check(root).valid;
    }
};
