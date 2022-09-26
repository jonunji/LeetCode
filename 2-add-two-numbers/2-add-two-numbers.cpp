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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {        
        int carry = 0;
        ListNode* result = new ListNode();
        ListNode* retval = result;
        
        while (l1 || l2)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;
            
            result->next = new ListNode(sum);
            result = result->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        if (carry != 0) result->next = new ListNode(carry);
        
        return retval->next;
    }
};