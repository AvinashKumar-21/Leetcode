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
    int a=1;
    int c=0;
    Node*fun(Node*head)
    {
        if(!head)
        return head;
        fun(head->next);
        head->data=head->data+a+c;
        c=head->data/10;
        head->data=head->data%10;
        a=0;
        return head;
    }
    Node* addOne(Node *head) 
    {
        head=fun(head);
        if(c!=0)
        {
            Node*temp=new Node(c);
            temp->next=head;
            return temp;
        }
        return head;
        // Your Code here
        // return head of list after adding one
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