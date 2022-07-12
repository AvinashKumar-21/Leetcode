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
    int ans=0;
    int i=0;
    ListNode* fun(ListNode*head)
    {
        if(!head)
            return head;
        fun(head->next);
        if(head->val==1)
        ans=ans+pow(2,i);
        i++;
        return head;
    }
    int getDecimalValue(ListNode* head) 
    {
        fun(head);
        return ans;
    }
};