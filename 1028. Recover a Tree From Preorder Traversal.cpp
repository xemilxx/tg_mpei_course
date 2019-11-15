//https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
    
    TreeNode* f(string& s, int& i, int n) {
        int j = 0;
        
        while (s[i+j] == '-') ++j;
        
        if (j != n) return NULL;
        
        i += j;
        int k = 0;
        
        while (isdigit(s[i])) { //isdigit проверяет, является ли аргумент десятичной цифрой
            k = k * 10 + s[i] - '0';
            ++i;
        }
        
        TreeNode* r = new TreeNode(k);
        r->left = f(s, i, n + 1);
        r->right = f(s, i, n + 1);
        
        return r;
    }
    
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        return f(S, i, 0);
    }
    
};
