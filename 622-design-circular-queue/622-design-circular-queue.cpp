
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
class MyCircularQueue {
public:
    Node*head;
    Node*tail;
    int count;
    int total;
    MyCircularQueue(int k) {
        head=tail=NULL;
        count=k;
        total=0;
    }
    
    bool enQueue(int value) 
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
            tail=temp;
        }
        total++;
        return true;
    }
    
    bool deQueue() 
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
    
    int Front() {
        if(head)
            return head->val;
        return -1;
    }
    
    int Rear() {
        if(tail)
            return tail->val;
        return -1;
    }
    
    bool isEmpty() {
        return total==0;
    }
    
    bool isFull() {
        return total==count;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */