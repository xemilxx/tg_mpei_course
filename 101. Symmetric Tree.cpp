//https://leetcode.com/problems/symmetric-tree/

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
private:
    
    bool check(TreeNode* node1, TreeNode* node2) { 
        if (node1 == NULL && node2 == NULL) return true; 
        if (node1 != NULL && node2 != NULL) { 
            return ((node1->val == node2->val) && check(node1->left, node2->right) && check(node2->left, node1->right)); 
        }
        return false; 
    }
    
public:
    
    bool isSymmetric(TreeNode* root) {
        
        return root == NULL || check(root->left, root->right);
    
    }
    
};
