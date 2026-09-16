class Solution {
public:
    int ans = INT_MIN;

    int find(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = max(0, find(root->left));
        int right = max(0, find(root->right));

        // Path can turn at root
        ans = max(ans, root->val + left + right);

        // Path going upward cannot turn
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        find(root);
        return ans;
    }
};