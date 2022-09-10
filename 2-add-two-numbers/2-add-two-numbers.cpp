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
        ListNode* res = NULL, *dummy = NULL;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL)
        {
            int sum = (l1 == NULL ? 0 : l1->val)
                    + (l2 == NULL ? 0 : l2->val)
                    + carry;
                        
            carry = sum / 10;
            sum = sum % 10;
                
            if (res == NULL)
            {
                res = new ListNode(sum);
                dummy = res;
            }
            else
            {
                res->next = new ListNode(sum);
                res = res->next;
            }
            
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }
        
        if (carry != 0)
            res->next = new ListNode(carry);
        
        return dummy;
    }
};
























