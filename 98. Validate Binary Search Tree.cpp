//https://leetcode.com/problems/validate-binary-search-tree/

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

    bool helper(TreeNode* node, TreeNode* low, TreeNode* up) {
        if (node == NULL) return true;
        int val = node->val;
        if ((low != NULL && val <= low->val) || (up != NULL && val >= up->val)) 
            return false;
        return helper(node->right, node, up) && helper(node->left, low, node);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root->right, root, NULL) && helper(root->left, NULL, root);
    }

};
