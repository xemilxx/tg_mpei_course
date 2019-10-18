//https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    
    void InfixTravel(TreeNode* root, vector<int>& v) {
        if (root != NULL) {
            if (root->left != NULL) {
                InfixTravel(root->left, v);
            } 
            v.push_back(root->val);
            if (root->right != NULL) {
                InfixTravel(root->right, v);
            }
            
        }
    } 
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        InfixTravel(root, v);
        return v;
    }
    
};
