/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL)return B;
    if(B==NULL)return A;
    ListNode* head = NULL;
    ListNode* current = NULL;
    ListNode* Ahead = A;
    
    ListNode* Bhead = B;
    
    while(Ahead!=NULL && Bhead!=NULL)
    {
        if(head==NULL)
        {
            if(Ahead->val<Bhead->val)
            {
                head=A;
                Ahead=Ahead->next;
            }
            
            else 
            {
                head=B;
                Bhead=Bhead->next;
            }
            
            current = head;
        }
        
        else
        {
            if(Ahead->val<Bhead->val)
            {
                current->next=Ahead;
                current=current->next;
                Ahead=Ahead->next;
            }
            
            else
            {
                current->next = Bhead;
                current = current->next;
                Bhead=Bhead->next;
            }
        }
    }
    
    while(Ahead!=NULL)
    {
        current->next=Ahead;
        current=current->next;
        Ahead=Ahead->next;
        
    }
    
    while(Bhead!=NULL)
    {
        current->next=Bhead;
        current=current->next;
        Bhead=Bhead->next;
    }
    
    return head;
    
}
