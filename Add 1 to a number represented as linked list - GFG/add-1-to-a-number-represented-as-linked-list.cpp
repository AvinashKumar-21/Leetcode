// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    int c=0;
    Node*help(Node*head)
    {
        if(!head->next)
        {
            head->data=head->data+1;
            c=head->data/10;
            head->data=head->data%10;
            return head;
        }
        help(head->next);
        head->data=head->data+c;
        c=head->data/10;
        head->data=head->data%10;
        return head;
    }
    Node* addOne(Node *head) 
    {
        if(!head)
        return head;
        // if(!head->next)
        // {
        //     head->data+=1;
        //     return head;
        // }
        head=help(head);
        if(c!=0)
        {
            Node*newHead=new Node(c);
            newHead->next=head;
            return newHead;
        }
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends