//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    
    int travel(TreeNode* root, int min_node_val, int max_node_val) {
        if (root == NULL) {
            return (max_node_val - min_node_val);
        } 
        min_node_val = min(min_node_val, root->val);
        max_node_val = max(max_node_val, root->val);
        return max(travel(root->left, min_node_val, max_node_val), travel(root->right, min_node_val, max_node_val));
    }
    
    int maxAncestorDiff(TreeNode* root) {
     
        return travel(root, root->val, root->val);
    
    }
    
};
