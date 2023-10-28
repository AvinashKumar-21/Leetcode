//{ Driver Code Starts
import java.io.*;
import java.util.*;
class Node
{
    int data;
    Node next;
    
    Node(int x)
    {
        data = x;
        next = null;
    }
}
class GfG
{
    public static void printList(Node node) 
    { 
        while (node != null)
        { 
            System.out.print(node.data);
            node = node.next; 
        }  
        System.out.println();
    } 
    public static void main(String args[])throws IOException
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String s = sc.next();
                    Node head = new Node( s.charAt(0) - '0' );
                    Node tail = head;
                    for(int i=1; i<s.length(); i++)
                    {
                        tail.next = new Node( s.charAt(i) - '0' );
                        tail = tail.next;
                    }
                    Solution obj = new Solution();
                    head = obj.addOne(head);
                    printList(head); 
                }
        }
}
// } Driver Code Ends


/*
class Node{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
} 
*/

class Solution
{
    static int carry=0;
    static Node newHead;
    public static Node fun(Node head)
    {
        if(head==null)
        return null;
        if(head.next==null)
        {
            head.data+=carry+1;
            carry=head.data/10;
            head.data%=10;
            return head;
        }
        head.next=fun(head.next);
        head.data+=carry;
        carry=head.data/10;
        head.data%=10;
        return head;
    }
    public static Node addOne(Node head) 
    { 
        carry=0;
        newHead=fun(head);
        if(carry!=0)
        {
            Node temp=new Node(carry);
            temp.next=newHead;
            newHead=temp;
        }
        return newHead;
        
    }
}
