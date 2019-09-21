//https://leetcode.com/problems/add-two-numbers/

/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* l3 = new ListNode(0);
        ListNode* t3 = l3;
        int c = 0; //правило суммирования в столбик: если сумма двух цифр больше 10, то сумма / 10 прибавляется к сумме следующих 2 цифр
        
        while(l1 != NULL || l2 != NULL){            
            
            int a;
            int b;
            
            if (l1 != NULL) a = l1->val; else a = 0;
            if (l2 != NULL) b = l2->val; else b = 0;
            
            int s = a + b + c;
            c = s / 10;
            int ost = s % 10;
            ListNode* node = new ListNode(ost);
            t3->next = node;
            t3 = t3->next;
            
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        
        if (c) {
            ListNode* node = new ListNode(c);
            t3->next = node;
        } 
        
        return l3->next;
        
    }
};
