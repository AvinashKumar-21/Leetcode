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
    ListNode*rev(ListNode*head)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        l1=rev(l1);
        l2=rev(l2);
        int c=0;
        ListNode*newHead=l2;
        ListNode*trail=NULL;
        while(l1 && l2)
        {
            trail=l2;
            l2->val=l1->val+l2->val+c;
            c=l2->val/10;
            l2->val=l2->val%10;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1)
        {
            trail->next=l1;
            while(l1 && c)
            {
                 trail=l1;
                l1->val=l1->val+c;
                c=l1->val/10;
                l1->val=l1->val%10;
                l1=l1->next;
            }
        }
        else
        {
            while(l2 && c)
            {
                 trail=l2;
                l2->val=l2->val+c;
                c=l2->val/10;
                l2->val=l2->val%10;
                l2=l2->next;
            }
        }
        if(c)
            trail->next=new ListNode(c);
        return rev(newHead);
    }
};