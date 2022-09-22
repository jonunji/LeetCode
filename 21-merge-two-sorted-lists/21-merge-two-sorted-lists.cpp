/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* start = new ListNode();
        ListNode* curr = start;
        
        while (l1 || l2)
        {
            int l1Val = l1 ? l1->val : INT_MAX;
            int l2Val = l2 ? l2->val : INT_MAX;
            
            curr->next = l1Val < l2Val ? l1 : l2;
            curr = curr->next;
            
            if (l1Val < l2Val) l1 = l1->next;
            else               l2 = l2->next;
        }
        
        return start->next;
    }
};