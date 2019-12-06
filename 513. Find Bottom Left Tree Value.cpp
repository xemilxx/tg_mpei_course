//https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<TreeNode*> q;
        int res;
        
        q.push(root);
        int cnt = 1;
        vector<int> tmp;
        
        while (!q.empty()) {
            tmp.push_back(q.front()->val);
            if (q.front()->left != NULL) q.push(q.front()->left);
            if (q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
            cnt--;
            if (!cnt) {
                cnt = q.size();
                res = tmp[0];
                tmp.clear();
            }
        }
        return res;
    }
};
