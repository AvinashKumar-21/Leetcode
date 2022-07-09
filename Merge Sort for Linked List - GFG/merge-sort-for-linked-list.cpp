// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node*l1,Node*l2)
    {
        if(!l1)
        return l2;
        if(!l2)
        return l1;
        Node*temp=new Node(-1);
        Node*trail=temp;
        while(l1 && l2)
        {
            if(l1->data>l2->data)
            {
                trail->next=l2;
                l2=l2->next;
            }
            else
            {
                trail->next=l1;
                l1=l1->next;
            }
            trail=trail->next;
        }
        if(l1)
        trail->next=l1;
        if(l2)
        trail->next=l2;
        return temp->next;
    }
    
    Node*mid(Node*head)
    {
        Node*slow=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        return fast;
    }
    Node* mergeSort(Node* head) 
    {
        if(!head || !head->next)
        return head;
        Node*m=mid(head);
        return merge(mergeSort(head),mergeSort(m));
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends