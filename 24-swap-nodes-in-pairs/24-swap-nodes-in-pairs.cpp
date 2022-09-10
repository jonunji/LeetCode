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
    
    ListNode* swap(ListNode* n1, ListNode* n2)
    {
        n1->next = n2->next;
        n2->next = n1;
        return n2;
    }
    
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* prev = NULL, *ret;
        
        while (head != NULL && head->next != NULL)
        {
            if (prev != NULL)
                prev->next = swap(head, head->next);
            else
            {
                ret = swap(head, head->next);
                prev = head;
            }
            
            prev = head;
            head = head->next;
        }
    
        return ret;
    }
};