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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        stack<ListNode*> s;
        ListNode* retval = head;
        ListNode* nextNode;
        
        while (head != NULL)
        {
            s.push(head);
            head = head->next;
        }
        
        
        while (!s.empty() && n > 0)
        {      
            nextNode = s.top();
            
            s.pop();
            n--;
        }
        
        if (s.empty())
        {
            ListNode* temp = retval->next;
            delete retval;
            
            return temp;
        }
        
        s.top()->next = nextNode->next;
        
        if (nextNode != NULL) delete nextNode;
        
        return retval;
    }
};