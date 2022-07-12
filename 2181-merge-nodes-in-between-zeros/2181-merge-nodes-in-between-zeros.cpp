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
    ListNode* mergeNodes(ListNode* head) 
    {
        if(!head)
            return head;
        int val=0;
        ListNode*temp=new ListNode(-1);
        ListNode*link=temp;
        while(head)
        {
            if(head->val==0)
            {
                if(val)
                {
                    link->next=new ListNode(val);
                    val=0;
                    link=link->next;
                }
                
            }
            else
            {
                val=val+head->val;
            }
            head=head->next;
        }
        return temp->next;
    }
};