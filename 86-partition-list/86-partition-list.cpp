class Solution {
public:
    ListNode*h=NULL;
    ListNode*t=NULL;
    ListNode*tt=NULL;
    ListNode*ht=NULL;
    void createsmaller(ListNode*ele)
    {
        ele->next=NULL;
        if(h==NULL)
        {
            h=ele;
            t=ele;
        }   
        else
        {
            t->next=ele;
            t=t->next;
        }
    }
    void createlarger(ListNode*ele)
    {
        ele->next=NULL;
        if(ht==NULL)
        {
            ht=ele;
            tt=ele;
        }   
        else
        {
            tt->next=ele;
            tt=tt->next;
        }
    }
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head)
            return head;
        while(head)
        {
            if(head->val<x)
            {
                ListNode*ele=head;
                head=head->next;
                createsmaller(ele);
            }
            else
            {
                ListNode*ele=head;
                head=head->next;
                createlarger(ele);
            }
        }
        if(h)
        {
            t->next=ht;
            return h;
        }
        return ht;
    }
};