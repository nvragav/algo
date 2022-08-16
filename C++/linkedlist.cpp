#include <iostream>

using namespace std;
/*
OUTPUT:
-------
Inserting node for 5
Inserting node for 4
Inserting node for 3
Inserting node for 2
Inserting node for 1
--- LinkedList ---
5->4->3->2->1->NULL
--- Deleting 3 ---
--- LinkedList ---
5->4->2->1->NULL
Is available ?  --- Searching 1 ---
1
Is available ?  --- Searching 3 ---
0
--- Printing Linked list in reverse order ---
1->2->4->5->NULL
--- Sequence of Linkedlist ---
5->4->2->1->NULL
Swapping the nodes that holds 4 and 2
5->2->4->1->NULL
Swapping the nodes that holds 2 and 1
5->1->4->2->NULL
Swapping the nodes that holds 5 and 4
4->1->5->2->NULL
Inserting node for 3
Inserting node for 10
Inserting node for 11
--- LinkedList ---
4->1->5->2->3->10->11->NULL
--- Reversing LinkedList by 3
5->1->4->10->3->2->11->NULL
--- Swapping the nodes with the distance of 3
4->1->5->2->3->10->11->NULL
--- Reversing LinkedList ---
11->10->3->2->5->1->4->NULL

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
        cout << "Inserting node for " << node->data << endl;
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
    
    //Print the linkedlist nodes in reverse without reversing the pointers.
    //Ref: https://www.geeksforgeeks.org/print-reverse-of-a-linked-list-without-actually-reversing/
    void printReverse(struct llNode* head)
    {
        if(head != NULL)
        {
            printReverse(head->next);
            cout << head->data << "->" ;
        }
    }

void swapllNodesByPointers(struct llNode* &head, int d1, int d2)
    {
        struct llNode *p1, *c1;
        struct llNode *p2, *c2,*tmp;
        
        p1 = p2 = head;
        c1 = c2 = (head->data == d1 ) ? head : head->next;
        
        cout << "Swapping the nodes that holds " << d1 << " and " << d2 << endl;
        
        while((c1 != NULL) && (c2 != NULL))
        {
            
            if( c1->data == d1 && c2->data == d2)
            {
                
                 /* Swapping data with head node */
                  if(head == c1)
                    head = c2 ;              
                /* swap */
                tmp = c2->next;
                c2->next = c1->next;
                p1->next = c2;
                
                
                if(c1 == p2) /* swapping adjacent nodes */
                    p2 = c2;
                p2->next = c1;
                c1->next = tmp;
                /* updating the tail pointer if there is any change in tail node */
                tail = (tail == c1) ? c2 : ((tail == c2) ? c1 : tail ) ;
                
                break;
            }
            else if( c1->data == d1)
            {
                /* Move p2, c2 until it reaches d2 */
                p2 = c2;
                c2 = c2->next;
            }
            else if( c2->data == d2)
            {
                /* Move p1, c1 until it reaches d1 */
                p1 = c1;
                c1 = c1->next;
            }
            else
            {
                p1 = p2 = c1;
                c1 = c2 = c1->next;
            }
        }
    }

    struct llNode* swapllNodesByK(struct llNode* head, int k)
    {
        struct llNode *prev, *curr,*tmp;
        int cnt = 1;
        
        if(head == NULL)
            return NULL;
        
        prev = head;
        curr = head->next;
        
        while((curr != NULL) && (cnt < (k-1)))
        {
            
            prev = curr;
            curr = curr->next;
            cnt++;
        }
       
        if(curr != NULL)
        {
            //cout << "Swapping nodes " << head->data << " " << curr->data;
            tmp = curr->next;
            prev->next = head;
            curr->next = head->next;
            head->next = tmp;
            
            head->next = swapllNodesByK(head->next, k);
            
            return(curr);
        }
        else
        {
            return(head);
        }
        
    }
    
    struct llNode* reverseLinkedListByK(struct llNode* head, int k )
    {
        struct llNode *prev,*curr,*tmp;
        
        int cnt = 1;
        prev = head;
        curr = head->next;
        while((curr != NULL) && (cnt < k))
        {
            //cout << prev->data << " " << curr->data << endl;
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            cnt++;
        }

        if(curr != NULL)
            head->next = reverseLinkedListByK(curr,k);
        
        return(prev);
    }
    struct llNode* reverseLinkedList(struct llNode *head,struct llNode* &gTail)
    {
        struct llNode *tmp = NULL;
        struct llNode *prev,*curr;
        struct llNode *tail ;
        
        prev = tail = head;
        curr = head->next;
        while(curr != NULL)
        {
            tmp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = tmp;
        }
        tail->next = NULL;
        //Updating tail
        gTail = tail;
        return(prev);
    }
    void createLinkedListLoop(struct llNode* head, int k,struct llNode* tail)
    {
        struct llNode* curr;
        int cnt = 1;
        curr = head;
        while((curr != NULL) && (cnt < k))
        {
            curr = curr->next;
            cnt++;
        }        
        tail->next = curr;
        cout << "Loop node : " << curr->data << endl; 
        
    }
    void breakLinkedListLoop(struct llNode* head,struct llNode* &tail)
    {
        struct llNode *slowPtr, *fastPtr,*tPtr;

        
        slowPtr = head;
        fastPtr = head;
        do
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
        }while(slowPtr != fastPtr);
        
        
        //To detect the loop, fastPtr might have travelled to 2x length when slowPtr travelled x.
        // Reset the fastPtr to head and move both the pointers to same pace. both of them will meet
        // at loop node.
        fastPtr = head;
        
        while(slowPtr != fastPtr)
        {
            //cout << slowPtr->data << " " << fastPtr->data << endl;
            tPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        cout << "Last node : " << tPtr->data << endl;
        tPtr->next = NULL;
        tail = tPtr;
        
    }
    
};

int main()
{
    linkedList sll;

    int K = 3;
    
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
    
    cout << "--- Printing Linked list in reverse order ---" << endl;
    sll.printReverse(sll.head);
    cout << "NULL" << endl;    

    cout << "--- Sequence of Linkedlist ---" << endl;
    sll.traversellNode(sll.head);
    sll.swapllNodesByPointers(sll.head,4,2);
    sll.traversellNode(sll.head);
    sll.swapllNodesByPointers(sll.head,2,1);
    sll.traversellNode(sll.head);  
     sll.swapllNodesByPointers(sll.head,5,4);
    sll.traversellNode(sll.head); 

    sll.insertllNode(sll.head,sll.tail,sll.createllNode(3));
    sll.insertllNode(sll.head,sll.tail,sll.createllNode(10));
    sll.insertllNode(sll.head,sll.tail,sll.createllNode(11));

    cout << "--- LinkedList ---" << endl;
    sll.traversellNode(sll.head);
    cout << "--- Reversing LinkedList by " << K << endl; 
    sll.head = sll.reverseLinkedListByK(sll.head,K);
    sll.traversellNode(sll.head);
    
    cout << "--- Swapping the nodes with the distance of " << K << endl;
    sll.head = sll.swapllNodesByK(sll.head,3);
    sll.traversellNode(sll.head);    
  
    cout << "--- Reversing LinkedList ---" << endl;
    sll.head = sll.reverseLinkedList(sll.head,sll.tail);
    sll.traversellNode(sll.head);

    cout << "--- Removal of loop in LinkedList ---" << endl;
    sll.createLinkedListLoop(sll.head,K,sll.tail);
    sll.breakLinkedListLoop(sll.head,sll.tail);
    sll.traversellNode(sll.head); 
}
