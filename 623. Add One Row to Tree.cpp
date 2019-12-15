// https://leetcode.com/problems/add-one-row-to-tree/

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
    
    void dfs(TreeNode* root, int dep, int v, int d) {
        if (dep + 1 == d) {
            TreeNode* last_left = root->left; 
            TreeNode* last_right = root->right;
            TreeNode* new_left = new TreeNode(v);
            TreeNode* new_right = new TreeNode(v);
            root->left = new_left; 
            root->right = new_right;
            new_left->left = last_left; 
            new_right->right = last_right;
            return;
        }
        if (root->left)
            dfs(root->left, dep + 1, v, d);
        if (root->right)
            dfs(root->right, dep + 1, v, d);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode dummy(-1);
        dummy.left = root;
        dfs(&dummy, 0, v, d);
        return dummy.left;
    }
};
