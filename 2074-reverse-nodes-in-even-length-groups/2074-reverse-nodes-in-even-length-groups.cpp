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
    ListNode*temp;
    ListNode*link;
    ListNode*th;
    ListNode*tt;
    Solution()
    {
        temp=new ListNode(-1);
        link=temp;
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
    void add(ListNode*ele)
    {
        if(th==NULL)
        {
            th=ele;
            tt=ele;
        }
        else
        {
            ele->next=th;
            th=ele;
        }
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        if(!head )
            return head;
        int c=1;
        while(head)
        {
            int count=0;
            for(int i=0;head && i<c;i++)
            {
                ListNode*p=head->next;
                head->next=NULL;
                add(head);
                head=p;
                count++;
            }
            if(count%2==0)
            {
                link->next=th;
                link=tt;
            }
            else
            {
                link->next=reverse(th);
                while(link->next)
                    link=link->next;
            }
            th=tt=NULL;
            c++;
        }
        return temp->next;
    }
};