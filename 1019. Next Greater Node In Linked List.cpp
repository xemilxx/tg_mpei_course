//https://leetcode.com/problems/next-greater-node-in-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> v;
    
        ListNode* check = head;
        
        while (check != NULL) {
            
            ListNode* l = check->next;
        
            while (l != NULL) {
            
                if (check->val < l->val) {
                    v.push_back(l->val); break;
                } else if (l->next == NULL) {
                 v.push_back(0);
                }
            
             l = l->next;    
        
            } 
            
            check = check->next;
        }
        
        v.push_back(0);
        return v;
    }
};
