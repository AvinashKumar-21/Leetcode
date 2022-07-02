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
            return NULL;
        ListNode*fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
                break;
        }
        if(!fast->next || !fast->next->next)
            return NULL;
        slow=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};