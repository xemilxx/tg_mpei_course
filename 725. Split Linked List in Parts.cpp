//https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        vector<ListNode*> result(k, NULL);
        ListNode* tmp = root;
        
        int c = 0;
        while (tmp != NULL) {
            c++;
            tmp = tmp->next;
        }
        
        int z = c / k;
        int ost = c % k;
        
        tmp = root;
        for (int i = 0; i < k; i++) {
            ListNode* head = new ListNode(0);
            ListNode* ans = head;
            for (int j = 0; j < z + (i < ost ? 1 : 0); j++) {
                ans = ans->next = new ListNode(tmp->val);
                if (tmp != NULL) {
                    tmp = tmp->next;         
                }
            }
            result[i] = head->next;       
        }
        return result;    
    }
};
