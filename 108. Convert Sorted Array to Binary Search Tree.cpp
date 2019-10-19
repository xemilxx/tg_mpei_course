//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    
    TreeNode* CreateBST(vector<int> nums, int begin, int end) {
        
        if (begin > end) {
            return NULL;
        } else if (begin == end) {
            TreeNode* tree = new TreeNode(nums[begin]);
            return tree;
        } else {
            int mid = (begin + end) / 2; 
            TreeNode* tree = new TreeNode(nums[mid]);
            tree->right = CreateBST(nums, mid + 1, end);
            tree->left = CreateBST(nums, begin, mid - 1);
            return tree;
        }
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    
        TreeNode* BST = CreateBST(nums, 0, nums.size() - 1); 
        
        return BST;
        
    }
    
};
