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
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head)
            return head;
        ListNode*fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        if(!fast->next || !fast->next->next)
            return NULL;
        if(head==fast)
            return head;
        slow=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};