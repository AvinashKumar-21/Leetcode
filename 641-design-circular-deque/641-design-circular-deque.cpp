
class Node
{
    public:
    int val;
    Node*prev;
    Node*next;
    Node(int data)
    {
        val=data;
        next=prev=NULL;
    }
};
class MyCircularDeque {
public:
    Node*head;
    Node*tail;
    int count;
    int total;
    MyCircularDeque(int k) 
    {
        head=tail=NULL;
        count=k;
        total=0;
    }
    
    bool insertFront(int value) 
    {
        if(count<=total)
            return false;
        Node*temp=new Node(value);
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        total++;
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(count<=total)
            return false;
        Node*temp=new Node(value);
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        total++;
        return true;
    }
    
    bool deleteFront() 
    {
        if(total<=0)
            return false;
        if(head->next)
        {
            head=head->next;
            head->prev=NULL;
        }
        else
        {
            tail=head=NULL;
        }
        total--;
        return true;
        
    }
    
    bool deleteLast() 
    {
        if(total<=0)
            return false;
        if(tail->prev)
        {
            tail=tail->prev;
            tail->next=NULL;
        }
        else
        {
            tail=head=NULL;
        }
        total--;
        return true;
    }
    
    int getFront() {
        if(!head)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if(!tail)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return total==0;
    }
    
    bool isFull() {
        return total==count;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */