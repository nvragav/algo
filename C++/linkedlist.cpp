#include <iostream>

using namespace std;
/*
OUTPUT:
-------
--- LinkedList ---
5->4->3->2->1->NULL
--- Deleting 3 ---
--- LinkedList ---
5->4->2->1->NULL
--- Searching 1 ---
Is available ?  1
--- Searching 3 ---
Is available ?  0
*/
class linkedList {

    public:

    struct llNode {
        int data;
        struct llNode* next;
    };
    struct llNode* head = NULL;
    struct llNode* tail = NULL;   
    struct llNode* createllNode(int data)
    {
        auto node = new llNode();
        node->data = data;
        return node;
    }
    //insert at the back
    struct llNode* insertllNode(struct llNode* &head, struct llNode* &tail, struct llNode* node) 
    {
        if(head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        return head;
    }
    
    bool searchllNode(struct llNode* head, int data)
    {
        struct llNode* tmp = head;
        
        cout << "--- Searching " << data << " ---" << endl;
        while( tmp != NULL)
        {
            if(tmp->data == data)
                return true;
                
            tmp = tmp->next;
        }
        return false;
    }   
    
    //delete operation
    struct llNode* deletellNode(struct llNode* head, struct llNode* tail,int data)
    {
        struct llNode *curr, *prev;
        prev = head;
        curr = head->next;
        
        cout << "--- Deleting " << data << " ---" << endl;
        //Deleting head
        if(head->data == data)
        {
            head = curr;
            delete prev;
        }
        else
        {
            while(curr != NULL)
            {
                if(curr->data == data)
                {
                    prev->next = curr->next;
                    if(tail == curr)
                        tail = prev;
                    delete curr;
                    break;
                    
                }
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
    
    //Traversal 
    void traversellNode(struct llNode* head)
    {
        if(head != NULL)
        {
            cout << head->data << "->" ;
            traversellNode(head->next);
        }
        else
        {
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    linkedList sll;
    
    sll.insertllNode(sll.head,sll.tail,sll.createllNode(5));
    sll.insertllNode(sll.head,sll.tail,sll.createllNode(4));
    sll.insertllNode(sll.head,sll.tail,sll.createllNode(3));
    sll.insertllNode(sll.head,sll.tail,sll.createllNode(2));
    sll.insertllNode(sll.head,sll.tail,sll.createllNode(1));
    cout << "--- LinkedList ---" << endl;
    
    sll.traversellNode(sll.head);
    
    sll.deletellNode(sll.head,sll.tail, 3);
    cout << "--- LinkedList ---" << endl;
    sll.traversellNode(sll.head);
    cout << "Is available ?  " << sll.searchllNode(sll.head,1) << endl;
    cout << "Is available ?  " << sll.searchllNode(sll.head,3) << endl;
    
    
    
}