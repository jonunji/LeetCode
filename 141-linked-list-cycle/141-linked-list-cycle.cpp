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
    bool hasCycle(ListNode *slow) 
    {
        ListNode* fast = slow;
        
        while (slow && fast)
        {
            fast = fast->next;
            
            if (slow == fast)
                return true;
            
            slow = slow->next;
            if (fast) fast = fast->next;
        }
        
        return false;
    }
};