// https://leetcode.com/problems/delete-nodes-and-return-forest/

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
	vector<TreeNode*> res;
	TreeNode* dfs(TreeNode* root,set<int>& table){
		if(not root) return root;
		root->left=dfs(root->left,table);
		root->right=dfs(root->right,table);
		if(table.find(root->val)!=table.end()){
			if(root->left){
				res.push_back(root->left);
			}
			if(root->right){
				res.push_back(root->right);
			}
			return NULL;
		}
		else return root;
	}
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		set<int> table(to_delete.begin(),to_delete.end());
		dfs(root,table);
		if(table.find(root->val)==table.end()){
			res.push_back(root);
		}
		return res;
	}
};
