//https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> v;
        
        if (root == NULL) {
            return v;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            
            int size = q.size();
            
            while (size) {
                
                size--;
                
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                
                if (size == 0) {
                    v.push_back(q.front()->val);
                }
                
                q.pop();
            
            }
            
        }
        
        return v;
        
    }
};
