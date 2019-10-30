//https://leetcode.com/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool check(TreeNode *node, int s, int sum) {
        if (node == NULL) return 0;
        s += node->val;
        if (node->left == NULL && node->right == NULL) {
            if (s == sum) return 1;
            return 0;
        }
        return check(node->left, s, sum) || check(node->right, s, sum);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        int s = 0;
        return check(root, s, sum);
    }
};
