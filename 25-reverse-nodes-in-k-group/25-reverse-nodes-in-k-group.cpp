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
    ListNode*tt=NULL;
    ListNode*th=NULL;
    void helper(ListNode*head)
    {
        if(th==NULL)
        {
            th=head;
            tt=head;
        }
        else
        {
            head->next=th;
            th=head;
        }
    }
    ListNode*reverse(ListNode*head)
    {
        ListNode*trail=NULL;
        while(head)
        {
            ListNode*temp=head->next;
            head->next=trail;
            trail=head;
            head=temp;
        }
        return trail;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || k==1)
            return head;
        ListNode*temp=new ListNode(-1);
        ListNode*t=temp;
        while(head)
        {
            int i=0;
            for(i=0;i<k && head;i++)
            {
                ListNode*a=head->next;
                head->next=NULL;
                helper(head);
                head=a;
            }
            if(i==k)
            {
                t->next=th;
                t=tt;
                th=NULL;
                tt=NULL;
            }
            else
                t->next=reverse(th);
        }
        return temp->next;
    }
};