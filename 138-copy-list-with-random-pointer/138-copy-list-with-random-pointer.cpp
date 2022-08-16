/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return head;
        Node*store=head;
        while(head)
        {
            Node*temp=head->next;
            head->next=new Node(head->val);
            head->next->next=temp;
            head=head->next->next;
        }
        head=store;
        while(head)
        {
            Node*r=head->random;
            if(r)
                head->next->random=r->next;
            head=head->next->next;
        }
        head=store;
        Node*newHead=new Node(-1);
        Node*link=newHead;
        while(head)
        {
            link->next=head->next;
            link=link->next;
            head->next=link->next;
            head=head->next;
        }
        return newHead->next;
    }
};