//{ Driver Code Starts
import java.util.*;
import java.lang.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class ReverseInSize
{
    static Node head;
    
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node tail = head;
            for(int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                // addToTheLast(new Node(a));
                tail.next = new Node(a);
                tail =tail.next;
            }
            
            int k = sc.nextInt();
            Solution ob = new Solution();
            Node res = ob.reverse(head, k);
            printList(res);
            System.out.println();
        }
    }
    
    public static void printList(Node node)
    {
        while(node != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }
    
}


// } Driver Code Ends


/*node class of the linked list

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

*/

class Solution
{
    static Node th=null;
    static Node tt=null;
    public static void addOne(Node ele)
    {
        if(th==null)
        {
            th=tt=ele;
        }
        else{
            ele.next=th;
            th=ele;
        }
    }
    
    public static Node reverse(Node node, int k)
    {
        Node newHead=new Node(-1);
        Node trail=newHead;
        Node head=node;
        while(head!=null)
        {
            for(int i=0;i<k && head!=null;i++)
            {
                Node temp=head.next;
                head.next=null;
                addOne(head);
                head=temp;
            }
            trail.next=th;
            trail=tt;
            tt=th=null;
        }
        return newHead.next;
    }
}

