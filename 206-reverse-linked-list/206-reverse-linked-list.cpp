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
    ListNode*trail=NULL;
    ListNode* reverseList(ListNode* head) 
    {
        if(!head)
            return head;
        ListNode*temp=head->next;
        head->next=trail;
        trail=head;
        reverseList(temp);
        return trail;
    }
};