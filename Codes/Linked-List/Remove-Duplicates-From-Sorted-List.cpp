/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void removeDuplicates(ListNode* A)
{
    ListNode* head = A;
    ListNode* nxt = A->next;
    
    while((nxt!=NULL) && (nxt->val==head->val))
    {
        head->next = nxt->next;
        ListNode* temp=nxt;
        nxt = nxt->next;
        temp->next = NULL;
    }
}

ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A==NULL)return A;
    ListNode* current = A;
    while(current!=NULL && current->next!=NULL)
    {
        if(current->val==current->next->val)
        {
            removeDuplicates(current);
        }
        
        current = current->next;
    }
    
    return A;
}
