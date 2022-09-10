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
        if (slow == NULL)
            return false;
        
        ListNode *fast = slow;
        
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                return true;
        }
        
        return false;
    }
};