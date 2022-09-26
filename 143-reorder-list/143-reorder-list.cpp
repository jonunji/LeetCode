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
    void reorderList(ListNode* head) 
    {
        ListNode* temp = head;
        stack<ListNode*> s;
        int size = 0;
        
        while (head) 
        {
            size++;
            
            s.push(head);
            head = head->next;
        }
        
        head = temp;
        for (int i = 0; i < size / 2; i++)
        { 
            temp = head->next;
            head->next = s.top();
            
            s.top()->next = temp;
            s.pop();
            
            head = head->next->next;
        }
        
        head->next = NULL;
    }
};