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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) 
    {
        ListNode *p1 = A, *p2 = B;
        
        while (p1 != p2)
        {
            p1 = !p1 ? B : p1->next;
            p2 = !p2 ? A : p2->next; 
        }
        
        return p1;
    }
};